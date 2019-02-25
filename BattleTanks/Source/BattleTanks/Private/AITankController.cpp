// Fill out your copyright notice in the Description page of Project Settings.

#include "AITankController.h"
#include "TankAimingComponent.h"

void AAITankController::BeginPlay()
{
	Super::BeginPlay();
}

void AAITankController::Tick(float DelaTime)
{
	Super::Tick(DelaTime);

	APawn* PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	APawn* ControlledTank = GetPawn();
	if (!ensure(PlayerTank && ControlledTank)) { return; }

	MoveToActor(PlayerTank, AcceptanceRadius); //todo check units
	UTankAimingComponent* AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	AimingComponent->Fire();
}
