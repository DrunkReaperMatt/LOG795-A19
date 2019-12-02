// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBlueprintFunctionLibrary.h"
#include <iostream>
//#include "../PythonScriptPlugin/Private/PythonScriptPlugin.h"

void UMyBlueprintFunctionLibrary::ExecutePythonString(FString PythonCmd, FString WidgetInput)
{
	UPythonBlueprintFunctionLibrary::ExecutePythonString(PythonCmd);
	FString result = WidgetInput;
	//UPythonBlueprintFunctionLibrary::ExecutePythonScript(PythonCmd);
	//FPythonScriptPlugin::Get()->ExecPythonCommand(*PythonCmd);
}


