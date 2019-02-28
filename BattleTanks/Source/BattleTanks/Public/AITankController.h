// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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
protected:
	UPROPERTY(EditAnywhere, Category = Setup)
	float AcceptanceRadius = 3000.0f;
private:
	virtual void Tick(float DeltaTime) override;

};
