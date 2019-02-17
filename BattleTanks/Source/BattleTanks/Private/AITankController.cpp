// Fill out your copyright notice in the Description page of Project Settings.

#include "AITankController.h"

ATank* AAITankController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * AAITankController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);
}

void AAITankController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Player is %s"), *GetPlayerTank()->GetName());
}
