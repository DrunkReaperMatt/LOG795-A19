// Fill out your copyright notice in the Description page of Project Settings.


#include "RosettaGameState.h"

ARosettaGameState::ARosettaGameState()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> BP_ItemDB(TEXT("DataTable'/Game/Inventory/ItemDB.ItemDB'"));
	ItemDB = BP_ItemDB.Object;
}

UDataTable* ARosettaGameState::GetItemDB() const
{
	return ItemDB;
}