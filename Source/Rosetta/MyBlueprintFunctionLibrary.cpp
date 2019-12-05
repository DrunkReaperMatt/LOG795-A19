// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBlueprintFunctionLibrary.h"
#include "RosettaCharacter.h"
#include <iostream>
//#include "../PythonScriptPlugin/Private/PythonScriptPlugin.h"

FString UMyBlueprintFunctionLibrary::ExecutePythonString(FString PythonCmd)
{
	UPythonBlueprintFunctionLibrary::ExecutePythonString(PythonCmd);
	//FPythonScriptPlugin::Get()->ExecPythonCommand(*PythonCmd);

	return PythonCmd;
}
