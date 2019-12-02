// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryManager.h"
#include "PickupableItem.h"

UInventoryManager::UInventoryManager()
{
	ItemTypes.Add("ADictionaryItem");
	ItemTypes.Add("ACoconutItem");
}

void UInventoryManager::AddItem(APickupableItem* Item, int Count)
{
	int i = ItemTypes.Find(Item->StaticClass()->GetFName());
	if (i != INDEX_NONE)
	{
		if (Inventory.Contains(ItemTypes[i]))
		{
			Inventory[ItemTypes[i]] += Count;
		}
		else
		{
			Inventory.Add(ItemTypes[i], Count);
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s is not a valid PickupableItem or hasn't been added to the list of IDs", 
			Item->StaticClass()->GetFName().ToString()));
	}
}

APickupableItem* UInventoryManager::GetItem(int index)
{
	// TODO: finish this
	FString s = ItemTypes[index].ToString();
	LoadClass<APickupableItem>(NULL, TEXT(""), NULL, LOAD_None, NULL);
}

void UInventoryManager::SpawnItem(int index)
{
	//UWorld::SpawnActor()
}
