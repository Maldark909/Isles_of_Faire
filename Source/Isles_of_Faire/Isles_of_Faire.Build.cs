// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Isles_of_Faire : ModuleRules
{
	public Isles_of_Faire(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
