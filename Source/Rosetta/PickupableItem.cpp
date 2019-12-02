// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupableItem.h"

// Called when the game starts or when spawned
void APickupableItem::BeginPlay()
{
	Super::BeginPlay();

}

void APickupableItem::Interact()
{
	OnPickup();
	Destroy();
}

FText APickupableItem::GetActionDescription()
{
	return FText::FromString("pick up item");
}