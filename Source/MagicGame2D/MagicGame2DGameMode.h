// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MagicGame2DGameMode.generated.h"

/**
 * The GameMode defines the game being played. It governs the game rules, scoring, what actors
 * are allowed to exist in this game type, and who may enter the game.
 *
 * This game mode just sets the default pawn to be the MyCharacter asset, which is a subclass of MagicGame2DCharacter
 */
UCLASS(minimalapi)
class AMagicGame2DGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	AMagicGame2DGameMode();
	UPROPERTY(EditAnywhere, Config, Category = "Variables", DisplayName = "Square Size")
		int SQUARE_SIZE = 100;
	/** Number of squares in 1 chunk */
	UPROPERTY(EditAnywhere, Config, Category = "Variables", DisplayName = "Chunk Size")
		int CHUNK_SIZE = 50;
	/** Number of iterations to run the automata through smoothing */
	UPROPERTY(EditAnywhere, Config, Category = "Variables", DisplayName = "Smooth Iterations")
		int SMOOTH_ITERATIONS = 2;
	UPROPERTY(EditAnywhere, Config, Category = "Variables", DisplayName = "Smooth Wall Threshold")
		int SMOOTH_WALL_THRESHOLD = 4;
};
