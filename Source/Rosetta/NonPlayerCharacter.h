// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "NonPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ROSETTA_API ANonPlayerCharacter : public AInteractableActor
{
	GENERATED_BODY()

	ANonPlayerCharacter();
		
	UPROPERTY()
	TSubclassOf<class UUserWidget> DWClass;
	
	virtual void Interact() override;

	//UFUNCTION(BlueprintGetter)
	virtual FText GetActionDescription() override;
};
