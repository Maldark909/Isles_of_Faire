// Copyright Epic Games, Inc. All Rights Reserved.

#include "Isles_of_FaireGameMode.h"
#include "Isles_of_FaireCharacter.h"
#include "UObject/ConstructorHelpers.h"

AIsles_of_FaireGameMode::AIsles_of_FaireGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
