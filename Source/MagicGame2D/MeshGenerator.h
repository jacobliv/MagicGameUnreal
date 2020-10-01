// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Actor.h"
#include "CellularAutomata.h"
#include "MarchingSquares.h"
#include "Global.h"

#include <MagicGame2D\AutomataRenderer.h>
#include <map>


#include "MaterialDataTableStruct.h"
#include "SquareRenderer.h"
#include "TriangleRenderer.h"


#include "MeshGenerator.generated.h"

UCLASS(ClassGroup = (MeshGeneration))
class MAGICGAME2D_API AMeshGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMeshGenerator();
	UPROPERTY(EditAnywhere,Category="Data Drive")
	UDataTable* materials;
	UPROPERTY(EditAnywhere)
	UMaterial* material;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UCellularAutomata* cellularAutomata;
	AAutomataRenderer* automataRenderer;
	USquareRenderer* squareRenderer;
	UTriangleRenderer* triangleRenderer;

	UMarchingSquares* marchingSquares;
	GenerationData generationData;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
