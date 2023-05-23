// Copyright Epic Games, Inc. All Rights Reserved.

#include "SprungGameMode.h"
#include "SprungCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASprungGameMode::ASprungGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}