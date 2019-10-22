// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InteractionIcon.generated.h"

/**
 * 
 */
UCLASS()
class ROSETTA_API UInteractionIcon : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, Category = "Text")
	FText InteractionDescription;

	UFUNCTION(BlueprintCallable, Category = "Text")
	void SetInteractionDescription(const FText ActionDescription);
};
