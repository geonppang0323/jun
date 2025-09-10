// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class C9 : ModuleRules
{
	public C9(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
		{
			// Initial Dependencies
			"Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput",

            "UMG", "Slate", "SlateCore",
        });

PrivateDependencyModuleNames.AddRange(new string[] { });

PublicIncludePaths.AddRange(new string[] { "C9" });
	}
}

