// Fill out your copyright notice in the Description page of Project Settings.


#include "RosettaController.h"
#include "RosettaGameState.h"
#include "RosettaCharacter.h"

bool ARosettaController::AddItemToInventoryByID(FName ID)
{

	ensure(GetWorld() != NULL);
	ARosettaGameState* GameState = GetWorld()->GetGameState<ARosettaGameState>();
	ensure(GameState != nullptr);
	UDataTable* ItemTable = GameState->GetItemDB();
	FInventoryItem* ItemToAdd = ItemTable->FindRow<FInventoryItem>(ID, "");

	if (ItemToAdd)
	{
		Inventory.Add(*ItemToAdd);
		ReloadInventory();
		return true;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Could not find the item with ID %s"), *ID.ToString());
	}
	return false;
}