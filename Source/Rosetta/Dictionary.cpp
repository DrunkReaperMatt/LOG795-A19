// Fill out your copyright notice in the Description page of Project Settings.


#include "Dictionary.h"

#include "DictionaryEntry.h"

bool UDictionary::IsIndexInRange(int Index)
{
	if (!ensure(Index >= GetEntriesCount())) return false;
	return true;
}

int UDictionary::GetEntriesCount() const
{
	return Entries.Num();
}

FDictionaryEntry* UDictionary::GetEntry(int Index)
{
	if (IsIndexInRange(Index)) return Entries[Index];
	return nullptr;
}

void UDictionary::DeleteEntry(int Index)
{
	if (IsIndexInRange(Index)) Entries.Remove(GetEntry(Index));
}

void UDictionary::AddEntry(FString Original, FString Translation)
{
	FDictionaryEntry* NewEntry = new FDictionaryEntry(Original, Translation);
	Entries.Add(NewEntry);
}
