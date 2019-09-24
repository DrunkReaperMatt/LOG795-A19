// Fill out your copyright notice in the Description page of Project Settings.


#include "Dictionary.h"

#include "DictionaryEntry.h"

bool UDictionary::IsIndexInRange(int Index) const
{
	if (Index >= UDictionary::GetEntriesCount())
	{
		UE_LOG(LogTemp, Error, TEXT("Index is out of Entries range"));
		return false;
	}
	return true;
}

int UDictionary::GetEntriesCount() const
{
	return Entries.Num();
}

bool UDictionary::Contains(FString Original) const
{
	return UDictionary::GetEntry(Original) != nullptr;
}

int UDictionary::GetEntryIndex(FString Original) const
{
	for (int i = 0; i < Entries.Num(); i++)
	{
		if (Entries[i]->GetOriginal() == Original)
		{
			return i;
		}
	}
	return INDEX_NONE;
}

FDictionaryEntry* UDictionary::GetEntry(int Index) const
{
	if (UDictionary::IsIndexInRange(Index))
	{
		return Entries[Index];
	}
	return nullptr;
}

FDictionaryEntry* UDictionary::GetEntry(FString Original) const
{
	for (FDictionaryEntry* Entry : Entries)
	{
		if (Entry->GetOriginal() == Original)
		{
			return Entry;
		}
	}
	return nullptr;
}

void UDictionary::DeleteEntry(int Index)
{
	if (UDictionary::IsIndexInRange(Index))
	{
		Entries.Remove(UDictionary::GetEntry(Index));
	}
}

bool UDictionary::AddEntry(FString Original, FString Translation)
{
	if (!UDictionary::Contains(Original))
	{
		FDictionaryEntry* NewEntry = new FDictionaryEntry(Original, Translation);
		Entries.Add(NewEntry);
		return true;
	}
	return false;
}

void UDictionary::UpdateEntryTranslation(int Index, FString NewTranslation)
{
	UDictionary::GetEntry(Index)->SetTranslation(NewTranslation);
}

void UDictionary::UpdateEntryTranslation(FString Original, FString NewTranslation)
{
	UDictionary::UpdateEntryTranslation(UDictionary::GetEntryIndex(Original), NewTranslation);
}

bool UDictionary::UpdateEntryOriginal(int Index, FString NewOriginal)
{
	if (UDictionary::Contains(NewOriginal))
	{
		UDictionary::GetEntry(Index)->SetOriginal(NewOriginal);
		return true;
	}
	return false;
}
