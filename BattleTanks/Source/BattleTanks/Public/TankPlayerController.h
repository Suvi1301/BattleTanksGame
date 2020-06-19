// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

// Forward Declarations
class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
    
public:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(EditAnywhere)
    float CrossHairXLocation = 0.5;
    
    UPROPERTY(EditAnywhere)
    float CrossHairYLocation = 0.33333;
    
    UPROPERTY(EditAnywhere)
    float LineTraceRange = 1000000.0; // 10 Kilometers.
    
    /* Start the tank movinf the barrel so that a shot would hit where
    the crosshair intersects the world */
    void AimTowardsCrosshair();
    
    ATank* GetControlledTank() const;
    bool GetSightRayHitLocation(FVector &OutHitLocation) const;
    bool GetLookDirection(FVector &LookDirection) const;
    bool GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const;
    
};
