// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Containers/Map.h"
#include "DictionaryEntry.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class ROSETTA_API UDictionaryEntry : public UObject
{
	GENERATED_BODY()

private:
	FString Original;

	FString Translation;

	// TODO: add picture variable

public:
	UFUNCTION(BlueprintCallable, Category = "Dictionary Entry")
	FString GetOriginal() const { return Original; }

	UFUNCTION(BlueprintCallable, Category = "Dictionary Entry")
	void SetOriginal(const FString OriginalText) { this->Original = OriginalText; }

	UFUNCTION(BlueprintCallable, Category = "Dictionary Entry")
	FString GetTranslation() const { return Translation; }

	UFUNCTION(BlueprintCallable, Category = "Dictionary Entry")
	void SetTranslation(const FString TranslationText) { this->Translation = TranslationText; }

	void Initialize(FString OriginalText, FString TranslationText)
	{
		SetOriginal(OriginalText);
		SetTranslation(TranslationText);
	}
};
