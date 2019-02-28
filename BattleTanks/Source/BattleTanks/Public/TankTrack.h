// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS( ClassGroup = (CUSTOM), meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	UTankTrack();
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDrivingForce = 62000000.0f;
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
private:
	float CurrentThrottle = 0;
	virtual void BeginPlay() override;
	void ApplySidewaysForce();
	void DriveTrack();
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
