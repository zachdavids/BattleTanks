// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "AITankController.generated.h"

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
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;
};
