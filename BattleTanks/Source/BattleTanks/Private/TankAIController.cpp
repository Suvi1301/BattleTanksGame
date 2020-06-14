// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    ATank* PossessedTank = GetControlledTank();
    if (PossessedTank)
        UE_LOG(LogTemp, Warning, TEXT("AIController possessing tank: %s"), *PossessedTank->GetName())
    else
        UE_LOG(LogTemp, Warning, TEXT("AIController not possessing tank."))
}


ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}
