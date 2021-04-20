// Copyright Epic Games, Inc. All Rights Reserved.

#include "NigelsExpeditionGameMode.h"
#include "NigelsExpeditionCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANigelsExpeditionGameMode::ANigelsExpeditionGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
