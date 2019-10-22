// Fill out your copyright notice in the Description page of Project Settings.


#include "DictionaryItem.h"
#include "RosettaCharacter.h"
#include "Dictionary.h"

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
	Player->GetDictionary()->AddEntry("Grany", "Hello");
	Player->GetDictionary()->AddEntry("jweeb", "there");
	//Player->GetDictionary()->AddEntry(("olgada", "stranger");
	Player->GetDictionary()->AddEntry("A", "I");
	Player->GetDictionary()->AddEntry("zu", "am");
	Player->GetDictionary()->AddEntry("nasee", "blind");
	Player->GetDictionary()->AddEntry("iko", "and");
	Player->GetDictionary()->AddEntry("meh", "so");
	Player->GetDictionary()->AddEntry("pandu", "cannot");
	//Player->GetDictionary()->AddEntry(("jojo", "count");
	Player->GetDictionary()->AddEntry("wa", "how");
	Player->GetDictionary()->AddEntry("saba", "many");
	Player->GetDictionary()->AddEntry("kischmet", "buildings");
	Player->GetDictionary()->AddEntry("sont", "are");
	Player->GetDictionary()->AddEntry("nepi", "in");
	Player->GetDictionary()->AddEntry("mantra", "town");
	Player->GetDictionary()->AddEntry("Kozo", "Could");
	//Player->GetDictionary()->AddEntry(("jula", "you");
	Player->GetDictionary()->AddEntry("miki", "please");
	Player->GetDictionary()->AddEntry("jubus", "them");
	Player->GetDictionary()->AddEntry("tom", "for");
	//Player->GetDictionary()->AddEntry(("Da", "me");
	//Player->GetDictionary()->AddEntry(("Zvari", "Thirteen");
	Player->GetDictionary()->AddEntry("juba", "that");
	Player->GetDictionary()->AddEntry("ze", "is");
	Player->GetDictionary()->AddEntry("ma", "a");
	Player->GetDictionary()->AddEntry("hünt", "lot");
	Player->GetDictionary()->AddEntry("uve", "of");
	//Player->Dictionary.Ad(("Kula", "Thank");
	Player->GetDictionary()->AddEntry("lep", "for");
	Player->GetDictionary()->AddEntry("julan", "your");
	Player->GetDictionary()->AddEntry("jimji", "help");
	//Player->GetDictionary()->AddEntry(("ouchi", "sorry");
	Player->GetDictionary()->AddEntry("buta", "but");
	Player->GetDictionary()->AddEntry("hua", "did");
	Player->GetDictionary()->AddEntry("du", "not");
	Player->GetDictionary()->AddEntry("undami", "understand");
	//Player->GetDictionary()->AddEntry(("kime", "what");
	Player->GetDictionary()->AddEntry("wawa", "said");
	Player->GetDictionary()->AddEntry("qual", "seem");
	Player->GetDictionary()->AddEntry("ku", "to");
	Player->GetDictionary()->AddEntry("mul", "recall");
	Player->GetDictionary()->AddEntry("e", "a");
	Player->GetDictionary()->AddEntry("vuruzu", "different");
	Player->GetDictionary()->AddEntry("zvarma", "number");
	Player->GetDictionary()->AddEntry("luis", "again");
	Player->GetDictionary()->AddEntry("jibi", "pretty");
	Destroy();
}

FText ADictionaryItem::GetActionDescription()
{
	return FText::FromString("pick up item");
}

