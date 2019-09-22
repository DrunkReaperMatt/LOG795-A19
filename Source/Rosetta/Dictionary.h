// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Dictionary.generated.h"

/**
 * 
 */
UCLASS()
class ROSETTA_API UDictionary : public UObject
{
	GENERATED_BODY()

private:
	TArray<struct FDictionaryEntry*> Entries;

	bool IsIndexInRange(int Index);

public:
	int GetEntriesCount() const;
	FDictionaryEntry* GetEntry(int Index);
	void DeleteEntry(int Index);
	void AddEntry(FString Original, FString Translation = "");
};
