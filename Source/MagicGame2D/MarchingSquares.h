// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <MagicGame2D\Vector2.h>
#include "ControlNode.h"
#include "Square.h"
#include <map>
#include <vector>

#include "GenerationData.h"
#include "Triangulator.h"
#include "Components/ActorComponent.h"
#include "MarchingSquares.generated.h"
using namespace std;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAGICGAME2D_API UMarchingSquares : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMarchingSquares();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void getControlNodes(GenerationData* data);
	inline bool isControlNode(const Vector2& pos, GenerationData* data, const shared_ptr<BoundingBox>& boundingBox);
	void getSquares(GenerationData* data);
	Triangulator triangulator;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Generate(GenerationData* data);

		
};
