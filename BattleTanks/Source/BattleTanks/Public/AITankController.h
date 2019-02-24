// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AITankController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANKS_API AAITankController : public AAIController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
private:
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float AcceptanceRadius = 0.0f;
};
