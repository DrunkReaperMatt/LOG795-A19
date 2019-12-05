// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PythonBlueprintFunctionLibrary.h"
#include "NonPlayerCharacter.h"
#include "MyBlueprintFunctionLibrary.generated.h"

UCLASS()
class ROSETTA_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Unreal Python")
		static FString ExecutePythonString(FString PythonCmd);
};
