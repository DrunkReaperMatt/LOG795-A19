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
	Player->GetDictionary()->ReplaceEntry("Grany", "Hello");
	Player->GetDictionary()->ReplaceEntry("jweeb", "there");
	//Player->GetDictionary()->ReplaceEntry("olgada", "stranger");
	Player->GetDictionary()->ReplaceEntry("A", "I");
	Player->GetDictionary()->ReplaceEntry("zu", "am");
	Player->GetDictionary()->ReplaceEntry("nasee", "blind");
	Player->GetDictionary()->ReplaceEntry("iko", "and");
	Player->GetDictionary()->ReplaceEntry("meh", "so");
	Player->GetDictionary()->ReplaceEntry("pandu", "cannot");
	//Player->GetDictionary()->ReplaceEntry("jojo", "count");
	Player->GetDictionary()->ReplaceEntry("wa", "how");
	Player->GetDictionary()->ReplaceEntry("saba", "many");
	Player->GetDictionary()->ReplaceEntry("kischmet", "buildings");
	Player->GetDictionary()->ReplaceEntry("sont", "are");
	Player->GetDictionary()->ReplaceEntry("nepi", "in");
	Player->GetDictionary()->ReplaceEntry("mantra", "town");
	Player->GetDictionary()->ReplaceEntry("Kozo", "Could");
	//Player->GetDictionary()->ReplaceEntry("jula", "you");
	Player->GetDictionary()->ReplaceEntry("miki", "please");
	Player->GetDictionary()->ReplaceEntry("jubus", "them");
	Player->GetDictionary()->ReplaceEntry("tom", "for");
	//Player->GetDictionary()->ReplaceEntry("Da", "me");
	//Player->GetDictionary()->ReplaceEntry("Zvari", "Thirteen");
	Player->GetDictionary()->ReplaceEntry("juba", "that");
	Player->GetDictionary()->ReplaceEntry("ze", "is");
	Player->GetDictionary()->ReplaceEntry("ma", "a");
	Player->GetDictionary()->ReplaceEntry("hünt", "lot");
	Player->GetDictionary()->ReplaceEntry("uve", "of");
	//Player->Dictionary.ReplaceEntry("Kula", "Thank");
	Player->GetDictionary()->ReplaceEntry("lep", "for");
	Player->GetDictionary()->ReplaceEntry("julan", "your");
	Player->GetDictionary()->ReplaceEntry("jimji", "help");
	//Player->GetDictionary()->ReplaceEntry("ouchi", "sorry");
	Player->GetDictionary()->ReplaceEntry("buta", "but");
	Player->GetDictionary()->ReplaceEntry("hua", "did");
	Player->GetDictionary()->ReplaceEntry("du", "not");
	Player->GetDictionary()->ReplaceEntry("undami", "understand");
	//Player->GetDictionary()->ReplaceEntry("kime", "what");
	Player->GetDictionary()->ReplaceEntry("wawa", "said");
	Player->GetDictionary()->ReplaceEntry("qual", "seem");
	Player->GetDictionary()->ReplaceEntry("ku", "to");
	Player->GetDictionary()->ReplaceEntry("mul", "recall");
	Player->GetDictionary()->ReplaceEntry("e", "a");
	Player->GetDictionary()->ReplaceEntry("vuruzu", "different");
	Player->GetDictionary()->ReplaceEntry("zvarma", "number");
	Player->GetDictionary()->ReplaceEntry("luis", "again");
	Player->GetDictionary()->ReplaceEntry("jibi", "pretty");
	Destroy();
}

FText ADictionaryItem::GetActionDescription()
{
	return FText::FromString("pick up item");
}

