// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerTankController.h"

ATank* APlayerTankController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
