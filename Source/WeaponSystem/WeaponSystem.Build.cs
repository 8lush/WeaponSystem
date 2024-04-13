// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WeaponSystem : ModuleRules
{
	public WeaponSystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange
		(
			new string[] 
			{ 
				// Base Modules
				"Core", 
				"CoreUObject",
				"Engine", 
				"InputCore", 
				"HeadMountedDisplay", 
				"EnhancedInput",

			}
		);

		PrivateDependencyModuleNames.AddRange
		(
			new string[] 
			{
				// GAS
				"GameplayAbilities", 
				"GameplayTags", 
				"GameplayTasks",

				// Create Blueprint
				"AssetTools", 
				"AssetRegistry", 
				"UnrealEd", 
				"KismetCompiler",

			}
		);
	}
}
