using UnrealBuildTool;

public class RosettaTests : ModuleRules
{
    public RosettaTests(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivateIncludePaths.AddRange(new string[] { "RosettaTests/Private" });
        PublicIncludePaths.AddRange(new string[] { "RosettaTests/Public" });
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivateDependencyModuleNames.AddRange(new string[] {
            "Core",
            "Engine",
            "CoreUObject",
            "Rosetta"
        });
    }
}