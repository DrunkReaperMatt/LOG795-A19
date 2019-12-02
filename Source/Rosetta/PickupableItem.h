// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "PickupableItem.generated.h"

/**
 * 
 */
UCLASS()
class ROSETTA_API APickupableItem : public AInteractableActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void Interact() override;

	virtual FText GetActionDescription() override;
	
private:
	virtual void OnPickup() { check(0 && "You must override this"); }
};
