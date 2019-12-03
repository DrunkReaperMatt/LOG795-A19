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
		this->Weight = 1;
		this->Value = 1;
		this->Description = FText::FromString("No Description");
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Weight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMesh* Thumbnail;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Description;

	bool operator==(const FInventoryItem& OtherItem) const
	{
		if (ItemID == OtherItem.ItemID)
			return true;
		return false;
	}
};