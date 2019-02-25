// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTankTurret;
class AProjectile;

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};

/**
Helps the player aim.
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()
public:	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);
	void AimAt(FVector HitLocation);
	void MoveBarrelTowards(FVector AimDirection);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Fire();
protected:
	UPROPERTY(BlueprintReadOnly, Category = State)
	EFiringState FiringState = EFiringState::Reloading;
private:
	float LastFireTime = 0.0f;
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 4000.0f;
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTime = 3.0f;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
};
