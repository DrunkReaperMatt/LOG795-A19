// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventoryItem.h"
#include "InventoryManager.generated.h"

/**
 * 
 */
UCLASS()
class ROSETTA_API UInventoryManager : public UObject
{
	GENERATED_BODY()
	
private:
	//UInventoryManager();

	//TMap<FName, int> Inventory;
	//TArray<FName> ItemTypes;

public:
	//void AddItem(class APickupableItem* Item, int Count = 1);
	//APickupableItem* GetItem(int index);
	//void SpawnItem(int index);

	//UFUNCTION(BlueprintCallable, Category = "Utils")
	//	int32 GetInventoryWeight();

	//UFUNCTION(BlueprintCallable, Category = "Utils")
	//	bool AddItemToInventoryByID(FName ID);

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	//	class APickupableItem* CurrentPickupable;

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	//	TArray<FInventoryItem> Inventory;

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	//	int32 Money;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//	int32 InventorySlotLimit;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//	int32 InventoryWeightLimit;
};

//UENUM(BlueprintType)
//enum class EItemTypes
//{
//	ADictionaryItem,
//	ACoconutItem
//};