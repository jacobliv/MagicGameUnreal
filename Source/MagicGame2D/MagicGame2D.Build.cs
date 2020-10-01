// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MagicGame2D : ModuleRules
{
	public MagicGame2D(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Paper2D", "FastNoise","ProceduralMeshComponent" });
		//DynamicallyLoadedModuleNames.AddRange(new string[] { "FastNoise" });
		PrivateIncludePathModuleNames.AddRange(new string[] { "FastNoise" });
	}
}
