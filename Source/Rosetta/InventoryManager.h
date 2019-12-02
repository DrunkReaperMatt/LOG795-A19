// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventoryManager.generated.h"

/**
 * 
 */
UCLASS()
class ROSETTA_API UInventoryManager : public UObject
{
	GENERATED_BODY()
	
private:
	UInventoryManager();

	TMap<FName, int> Inventory;
	TArray<FName> ItemTypes;

public:
	void AddItem(class APickupableItem* Item, int Count = 1);
	APickupableItem* GetItem(int index);
	void SpawnItem(int index);
};

//UENUM(BlueprintType)
//enum class EItemTypes
//{
//	ADictionaryItem,
//	ACoconutItem
//};