// Fill out your copyright notice in the Description page of Project Settings.

#include "AITankController.h"
#include "TankAimingComponent.h"
#include "Tank.h"

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
	if (AimingComponent->GetFiringState() == EFiringState::Locked)
	{
		AimingComponent->Fire();
	}
}

void AAITankController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		ATank* PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }
		//Subscribe method
		PossessedTank->OnDeath.AddUniqueDynamic(this, &AAITankController::OnTankDeath);
	}
}

void AAITankController::OnTankDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("Received"));
}
