// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Globals.h"
#include "Global.generated.h"

UCLASS()
class MAGICGAME2D_API AGlobal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGlobal();
	/** Main size variable for all parts of the project */
	UPROPERTY(EditAnywhere,Config, Category = "Variables", DisplayName="Square Size")
		int SQUARE_SIZE = 100;
	/** Number of squares in 1 chunk */
	UPROPERTY(EditAnywhere,Config, Category = "Variables", DisplayName="Chunk Size")
		int CHUNK_SIZE = 50;
	/** Number of iterations to run the automata through smoothing */
	UPROPERTY(EditAnywhere, Config, Category = "Variables", DisplayName = "Smooth Iterations")
		int SMOOTH_ITERATIONS = 2;
	UPROPERTY(EditAnywhere, Config, Category = "Variables", DisplayName = "Smooth Wall Threshold")
		int SMOOTH_WALL_THRESHOLD = 4;
	UPROPERTY(EditAnywhere, Config, Category = "Debug", DisplayName = "Show ControlNodes")
	bool SHOW_CONTROL_NODES = true;
	UPROPERTY(EditAnywhere, Config, Category = "Debug", DisplayName = "Show Automata")
	bool SHOW_AUTOMATA = true;
	UPROPERTY(EditAnywhere, Config, Category = "Debug", DisplayName = "Show Squares")
	bool SHOW_SQUARES = true;
	UPROPERTY(EditAnywhere, Config, Category = "Debug", DisplayName = "Show Triangles")
	bool SHOW_TRIANGLES = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostLoad() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
