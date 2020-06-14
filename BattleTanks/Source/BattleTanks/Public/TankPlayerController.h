// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "TankPlayerController.generated.h"

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
    
    ATank* GetControlledTank() const;
    
    /* Start the tank movinf the barrel so that a shot would hit where
    the crosshair intersects the world */
    void AimTowardsCrosshair();
    bool GetSightRayHitLocation(FVector &OutHitLocation) const;
    bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const;
	
};
