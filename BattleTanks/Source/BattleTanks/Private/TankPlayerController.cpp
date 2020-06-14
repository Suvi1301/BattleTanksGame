// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    ATank* PossessedTank = GetControlledTank();
    if (PossessedTank)
        UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing tank: %s"), *PossessedTank->GetName())
    else
        UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing tank."))
}


void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    AimTowardsCrosshair();
}


void ATankPlayerController::AimTowardsCrosshair()
{
    if (!GetControlledTank()) { return; }
    
    FVector HitLocation; // Out parameter
    if (GetSightRayHitLocation(HitLocation)) {// Has a "side effect", is going to line trace.
        UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString())
        // Get world location if linetrace through crosshair
        // If it hits the landscape
            // Tell controlled tank to aim this point.
    }
}


ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}


bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
    FVector LookDirection;
    if (GetLookDirection(LookDirection)) {
        // Line-trace along that look direction and see what we hit up (up to max range)
        GetLookVectorHitLocation(LookDirection, OutHitLocation);
    }
    return true;
}


bool ATankPlayerController::GetLookDirection(FVector &OutLookDirection) const
{
    // Find the crosshair position in pixel coordinates
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
    
    // "De-project" the screeen position of the crosshair to a world direction
    FVector CameraWorldLocation; // Not used but needed for Deproject method.
    return DeprojectScreenPositionToWorld(
       ScreenLocation.X,
       ScreenLocation.Y,
       CameraWorldLocation,
       OutLookDirection
   );
}


bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &OutHitLocation) const
{
    FHitResult HitResult;
    FVector StartLocation = PlayerCameraManager->GetCameraLocation();
    FVector EndLocation = StartLocation + (LookDirection * LineTraceRange);
    if (GetWorld()->LineTraceSingleByChannel(
            HitResult,
            StartLocation,
            EndLocation,
            ECollisionChannel::ECC_Visibility
        )
    )
    {
        OutHitLocation = HitResult.Location;
        return true;
    }
    OutHitLocation = FVector(0);
    return false;
}
