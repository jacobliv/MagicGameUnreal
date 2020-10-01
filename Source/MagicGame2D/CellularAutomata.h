// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FastNoise.h"
#include <map>
#include <string>

#include "GenerationData.h"
#include "Vector2.h"
#include "Globals.h"

#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "CellularAutomata.generated.h"

using namespace std;


UCLASS( ClassGroup=(MeshGeneration), meta=(BlueprintSpawnableComponent) )
class MAGICGAME2D_API UCellularAutomata : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCellularAutomata();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	FastNoise fastNoise;
	map<Vector2, int> Smooth(map<Vector2, int> automata);
	int GetNumberOfWalls(Vector2 pos, map<Vector2, int> automata);
	int assignBaseMaterials(std::map<int,FastNoise>* noiseFunction, shared_ptr<std::map<int,FMaterialDataTableStruct*>> baseMaterials, Vector2 position );
	int assignOres(const shared_ptr<map<int, FMaterialDataTableStruct*>>& ores, const Vector2& position);


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Generate(GenerationData* data);
};
 
