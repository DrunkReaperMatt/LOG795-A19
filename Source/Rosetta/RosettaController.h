// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InventoryItem.h"
#include "RosettaController.generated.h"

/**
 * 
 */
UCLASS()
class ROSETTA_API ARosettaController : public APlayerController
{
	GENERATED_BODY()
	

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ReloadInventory();
	

	UFUNCTION(BlueprintCallable, Category = "Utils")
	bool AddItemToInventoryByID(FName ID);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<FInventoryItem> Inventory;

	UFUNCTION(BlueprintCallable, Category = "Utils")
	int CountItemByID(FName ID) const;

	UFUNCTION(BlueprintCallable, Category = "Utils")
		void RemoveItemFromInventoryByID(FName ID, int Count);
};
