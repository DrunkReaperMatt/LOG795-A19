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
	Player->UpdateDictionary("Grany", "Hello");
	Player->UpdateDictionary("jweeb", "there");
	//Player->UpdateDictionary(("olgada", "stranger");
	Player->UpdateDictionary("A", "I");
	Player->UpdateDictionary("zu", "am");
	Player->UpdateDictionary("nasee", "blind");
	Player->UpdateDictionary("iko", "and");
	Player->UpdateDictionary("meh", "so");
	Player->UpdateDictionary("pandu", "cannot");
	//Player->UpdateDictionary(("jojo", "count");
	Player->UpdateDictionary("wa", "how");
	Player->UpdateDictionary("saba", "many");
	Player->UpdateDictionary("kischmet", "buildings");
	Player->UpdateDictionary("sont", "are");
	Player->UpdateDictionary("nepi", "in");
	Player->UpdateDictionary("mantra", "town");
	Player->UpdateDictionary("Kozo", "Could");
	//Player->UpdateDictionary(("jula", "you");
	Player->UpdateDictionary("miki", "please");
	Player->UpdateDictionary("jubus", "them");
	Player->UpdateDictionary("tom", "for");
	//Player->UpdateDictionary(("Da", "me");
	//Player->UpdateDictionary(("Zvari", "Thirteen");
	Player->UpdateDictionary("juba", "that");
	Player->UpdateDictionary("ze", "is");
	Player->UpdateDictionary("ma", "a");
	Player->UpdateDictionary("hünt", "lot");
	Player->UpdateDictionary("uve", "of");
	//Player->Dictionary.Ad(("Kula", "Thank");
	Player->UpdateDictionary("lep", "for");
	Player->UpdateDictionary("julan", "your");
	Player->UpdateDictionary("jimji", "help");
	//Player->UpdateDictionary(("ouchi", "sorry");
	Player->UpdateDictionary("buta", "but");
	Player->UpdateDictionary("hua", "did");
	Player->UpdateDictionary("du", "not");
	Player->UpdateDictionary("undami", "understand");
	//Player->UpdateDictionary(("kime", "what");
	Player->UpdateDictionary("wawa", "said");
	Player->UpdateDictionary("qual", "seem");
	Player->UpdateDictionary("ku", "to");
	Player->UpdateDictionary("mul", "recall");
	Player->UpdateDictionary("e", "a");
	Player->UpdateDictionary("vuruzu", "different");
	Player->UpdateDictionary("zvarma", "number");
	Player->UpdateDictionary("luis", "again");
	Player->UpdateDictionary("jibi", "pretty");
	Destroy();
}

FText ADictionaryItem::GetActionDescription()
{
	return FText::FromString("pick up item");
}

