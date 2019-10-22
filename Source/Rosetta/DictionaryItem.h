// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableActor.h"
#include "DictionaryItem.generated.h"

UCLASS()
class ROSETTA_API ADictionaryItem : public AInteractableActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADictionaryItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact() override;

	//UFUNCTION(BlueprintGetter)
	virtual FText GetActionDescription() override;
};
