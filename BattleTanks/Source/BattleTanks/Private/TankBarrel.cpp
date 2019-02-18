// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, 1.0f);
	float ElevationChange = GetWorld()->DeltaTimeSeconds * RelativeSpeed * MaxDegreesPerSecond;
	float NewElevation = FMath::Clamp<float>(RelativeRotation.Pitch + ElevationChange, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(NewElevation, 0, 0));
}
