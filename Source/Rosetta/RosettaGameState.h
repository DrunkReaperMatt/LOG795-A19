// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/GameStateBase.h"
#include "RosettaGameState.generated.h"

/**
 * 
 */
UCLASS()
class ROSETTA_API ARosettaGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	ARosettaGameState();

	UDataTable* GetItemDB() const;

protected:
	UPROPERTY(EditDefaultsOnly)
		class UDataTable* ItemDB;
};
