// Fill out your copyright notice in the Description page of Project Settings.


#include "DictionaryItem.h"
#include "RosettaCharacter.h"

#include <Engine/Engine.h>

// Sets default values
ADictionaryItem::ADictionaryItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADictionaryItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADictionaryItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADictionaryItem::Interact()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
	if (false)
	{
		Player->UpdateDictionary("Original1", "Translation1");
	}
}

