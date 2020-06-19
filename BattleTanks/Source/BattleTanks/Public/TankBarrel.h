// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
    // -1 is max downward movement and +1 is max up movement
    void Elevate(float RelativeSpeed);
	
private:
    UPROPERTY(EditAnywhere, Category = Setup)
    float MaxDegreesPerSecond = 5;
    
    UPROPERTY(EditAnywhere, Category = Setup)
    float MaxElevationDegrees = 45;
    
    UPROPERTY(EditAnywhere, Category = Setup)
    float MinElevationDegrees = 0;
};
