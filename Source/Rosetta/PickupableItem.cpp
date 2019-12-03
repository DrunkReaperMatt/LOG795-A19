// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupableItem.h"
#include "RosettaController.h"
#include "RosettaCharacter.h"

// Called when the game starts or when spawned
void APickupableItem::BeginPlay()
{
	Super::BeginPlay();

}

APickupableItem::APickupableItem()
{
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickupMesh");
	RootComponent = Cast<USceneComponent>(PickupMesh);

	ItemID = FName("No ID");
}

void APickupableItem::Interact()
{
	ARosettaController* IController = GetWorld()->GetFirstPlayerController<ARosettaController>();
	if (IController->AddItemToInventoryByID(ItemID))
	{
		OnPickup();
		Destroy();
	}
}

FText APickupableItem::GetActionDescription()
{
	return FText::FromString("pick up item");
}