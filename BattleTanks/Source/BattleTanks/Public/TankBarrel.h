// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
	Holds properties for the tank's barrel
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	void Elevate(float RelativeSpeed);
private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSecond = 5.0f;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxElevationDegrees = 40.0f;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinElevationDegrees = 0.0f;
};
