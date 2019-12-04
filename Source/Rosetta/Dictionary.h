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
	TArray<UDictionaryEntry*> Entries;

	bool IsIndexInRange(int Index) const;

public:
	UFUNCTION(BlueprintCallable, Category = "Dictionary")
	int GetEntriesCount() const;

	UFUNCTION(BlueprintCallable, Category = "Dictionary")
	bool Contains(FString Original) const;

	UFUNCTION(BlueprintCallable, Category = "Dictionary")
	int GetEntryIndex(FString Original) const;

	UFUNCTION(BlueprintCallable, Category="Dictionary")
	UDictionaryEntry* GetEntry(int Index) const;

	UDictionaryEntry* GetEntry(FString Original) const;
	void DeleteEntry(int Index);

	/**
	 * Checks if the entry currently exists. If not, adds a new entry
	 * @returns: whether or not addition was succesful
	 */
	UFUNCTION(BlueprintCallable, Category = "Dictionary")
	bool AddEntry(FString Original, FString Translation = "");

	UFUNCTION(BlueprintCallable, Category = "Dictionary")
	void ReplaceEntry(FString Original, FString Translation = "");

	UFUNCTION(BlueprintCallable, Category = "Dictionary")
	void UpdateEntryTranslation(int Index, FString NewTranslation);

	void UpdateEntryTranslation(FString Original, FString Translation);

	/**
	 * Updates an entry's original word, if there's no entry currently associated with it. 
	 * If this fails, you should try to fuse the entries 
	 * @returns: whether or not the update was successful
	 */
	UFUNCTION(BlueprintCallable, Category = "Dictionary")
	bool UpdateEntryOriginal(int Index, FString NewOriginal);
};
