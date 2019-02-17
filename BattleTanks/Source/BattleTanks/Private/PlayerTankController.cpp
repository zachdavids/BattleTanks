// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerTankController.h"

ATank* APlayerTankController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void APlayerTankController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Player controlling %s"), *GetControlledTank()->GetName());
}
