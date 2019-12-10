// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBlueprintFunctionLibrary.h"
#include "RosettaCharacter.h"
#include "Dictionary.h"
#include "DictionaryEntry.h"
#include <Engine/Engine.h>
#include <iostream>
//#include "../PythonScriptPlugin/Private/PythonScriptPlugin.h"

FString UMyBlueprintFunctionLibrary::ExecutePythonString(FString PythonCmd)
{
	UPythonBlueprintFunctionLibrary::ExecutePythonString(PythonCmd);
	//FPythonScriptPlugin::Get()->ExecPythonCommand(*PythonCmd);

	return PythonCmd;
}

FString UMyBlueprintFunctionLibrary::GetInputTextTranslation(FString InputText, ARosettaCharacter* Player)
{
	//ARosettaCharacter* Player = Cast<ARosettaCharacter*>(GetWorld()->GetFirstPlayerController()->GetPawn());
	UDictionary* Dict = Player->GetDictionary();

	FString Translation;
	FString word = "";
	for (auto x : InputText)
	{
		if (x == ' ')
		{
			word = "";
		}
		else
		{
			word = word + x;
			if (Dict->Contains(word))
			{
				Translation = Translation + " " + Dict->GetEntry(word)->GetTranslation();
			}
		}
	}

	if (Translation == "")
	{
		return InputText;
	}

	return Translation;
}