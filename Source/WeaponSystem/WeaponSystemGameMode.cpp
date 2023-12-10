// Copyright Epic Games, Inc. All Rights Reserved.

#include "WeaponSystemGameMode.h"
#include "WeaponSystemCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWeaponSystemGameMode::AWeaponSystemGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
