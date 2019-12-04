// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "InventoryItem.generated.h"

USTRUCT(BlueprintType)
struct FInventoryItem : public FTableRowBase
{
	GENERATED_BODY()

public:
	FInventoryItem()
	{
		this->Name = FText::FromString("No Name");
		this->Description = FText::FromString("No Description");
		this->ItemCount = 0;
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ItemData")
		FName ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
		FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
		int ItemCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
		UTexture2D* Thumbnail;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
		FText Description;

	bool operator==(const FInventoryItem& OtherItem) const
	{
		if (ItemID == OtherItem.ItemID)
			return true;
		return false;
	}
};