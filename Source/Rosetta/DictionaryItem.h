// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupableItem.h"
#include "DictionaryItem.generated.h"

UCLASS()
class ROSETTA_API ADictionaryItem : public APickupableItem
{
	GENERATED_BODY()

private:	
	virtual void OnPickup() override;
};
