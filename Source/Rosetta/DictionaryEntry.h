// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Containers/Map.h"
#include "DictionaryEntry.generated.h"

/**
 * 
 */
USTRUCT()
struct ROSETTA_API FDictionaryEntry
{
	GENERATED_BODY()
	
	UPROPERTY()
	FString Original;

	UPROPERTY()
	FString Translation;

	// TODO: add picture variable
	
	FString GetOriginal() const { return Original; }

	void SetOriginal(const FString OriginalText) { this->Original = OriginalText; }
	
	FString GetTranslation() const { return Translation; }

	void SetTranslation(const FString TranslationText) { this->Translation = TranslationText; }

	FDictionaryEntry()
	{
	}

	FDictionaryEntry(FString OriginalText, FString TranslationText)
	{
		SetOriginal(OriginalText);
		SetTranslation(TranslationText);
	}
};
