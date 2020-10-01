// Copyright Epic Games, Inc. All Rights Reserved.

#include "MagicGame2DGameMode.h"
#include "MagicGame2DCharacter.h"

AMagicGame2DGameMode::AMagicGame2DGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = AMagicGame2DCharacter::StaticClass();	
}
