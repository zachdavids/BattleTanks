// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "SpawnPoint.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API USpawnPoint : public USceneComponent
{
	GENERATED_BODY()

public:	

	USpawnPoint();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	AActor* GetSpawnedActor() const	{ return SpawnedActor; }

protected:

	virtual void BeginPlay() override;

private:	

	UPROPERTY()
	AActor* SpawnedActor;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AActor> SpawnClass;
		
};
