// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerTankController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API APlayerTankController : public APlayerController
{
	GENERATED_BODY()
public:
	ATank* GetControlledTank() const;
};
