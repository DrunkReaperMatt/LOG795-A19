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

int ARosettaController::CountItemByID(FName ID) const
{
	int Count = 0;
	for (FInventoryItem Item : Inventory)
	{
		if (Item.ItemID == ID)
		{
			Count++;
		}
	}
	return Count;
}

void ARosettaController::RemoveItemFromInventoryByID(FName ID, int Count)
{
	if (Count > CountItemByID(ID))
	{
		UE_LOG(LogTemp, Error, TEXT("Tried to remove more items than there are available"));
		return;
	}
	int j = 0;
	for (int i = 0; i < Inventory.Num(); i++)
	{
		if (j >= Count)
		{
			return;
		}
		if (Inventory[i].ItemID == ID)
		{
			Inventory.RemoveAt(i);
			i--;
			j++;
		}
	}
}
