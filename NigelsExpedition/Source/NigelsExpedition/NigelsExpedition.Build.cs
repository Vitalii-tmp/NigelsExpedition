// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NigelsExpedition : ModuleRules
{
	public NigelsExpedition(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "LevelSequence" });
		PrivateDependencyModuleNames.AddRange(new string[] { "MovieScene" });
	}
}
