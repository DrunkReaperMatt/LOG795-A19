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

	bool IsIndexInRange(int Index) const;

public:
	int GetEntriesCount() const;
	bool Contains(FString Original) const;
	int GetEntryIndex(FString Original) const;
	FDictionaryEntry* GetEntry(int Index) const;
	FDictionaryEntry* GetEntry(FString Original) const;
	void DeleteEntry(int Index);

	/**
	 * Checks if the entry currently exists. If not, adds a new entry
	 * @returns: whether or not addition was succesful
	 */
	bool AddEntry(FString Original, FString Translation = "");

	void UpdateEntryTranslation(int Index, FString NewTranslation);
	void UpdateEntryTranslation(FString Original, FString Translation);

	/**
	 * Updates an entry's original word, if there's no entry currently associated with it. 
	 * If this fails, you should try to fuse the entries 
	 * @returns: whether or not the update was successful
	 */
	bool UpdateEntryOriginal(int Index, FString NewOriginal);
};
