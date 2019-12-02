// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickupableItem.h"
#include "CoconutItem.generated.h"

/**
 * 
 */
UCLASS()
class ROSETTA_API ACoconutItem : public APickupableItem
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	virtual void OnPickup() override;
};
