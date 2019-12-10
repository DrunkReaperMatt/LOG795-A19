// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Rosetta : ModuleRules
{
    public Rosetta(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UMG", "Slate", "SlateCore", "Python", "PythonScriptPlugin", "UnrealEnginePython" });
		
		PrivateDependencyModuleNames.AddRange(new string[] {"DlgSystem"});
	}
}
