// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryManager.h"
#include "PickupableItem.h"
#include <Engine/DataTable.h>
#include "RosettaGameState.h"
#include "RosettaCharacter.h"

//UInventoryManager::UInventoryManager()
//{
//	ItemTypes.Add("ADictionaryItem");
//	ItemTypes.Add("ACoconutItem");
//}

//void UInventoryManager::AddItem(APickupableItem* Item, int Count)
//{
//	//int i = ItemTypes.Find(Item->StaticClass()->GetFName());
//	//if (i != INDEX_NONE)
//	//{
//	//	if (Inventory.Contains(ItemTypes[i]))
//	//	{
//	//		Inventory[ItemTypes[i]] += Count;
//	//	}
//	//	else
//	//	{
//	//		Inventory.Add(ItemTypes[i], Count);
//	//	}
//	//}
//	//else
//	//{
//	//	UE_LOG(LogTemp, Error, TEXT("%s is not a valid PickupableItem or hasn't been added to the list of IDs"), 
//	//		*Item->StaticClass()->GetFName().ToString());
//	//}
//}

//APickupableItem* UInventoryManager::GetItem(int index)
//{
//	// TODO: finish this
//	//FString s = ItemTypes[index].ToString();
//	//UClass* c = LoadClass<APickupableItem>(NULL, TEXT(""), NULL, LOAD_None, NULL);
//	//NewObject<*c>();
//	return nullptr;
//}
//
//void UInventoryManager::SpawnItem(int index)
//{
//	//UWorld::SpawnActor()
//}

//bool UInventoryManager::AddItemToInventoryByID(FName ID)
//{
//	//ensure(GetWorld() != NULL);
//	//ARosettaGameState* GameState = GetWorld()->GetGameState<ARosettaGameState>();
//	//ensure(GameState != nullptr);
//	//UDataTable* ItemTable = GameState->GetItemDB();
//	//FInventoryItem* ItemToAdd = ItemTable->FindRow<FInventoryItem>(ID, "");
//
//	//if (ItemToAdd)
//	//{
//	//	Inventory.Add(*ItemToAdd);
//	//	Cast<ARosettaCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn())->ReloadInventory();
//	//	return true;
//	//}
//	//return false;
//}
