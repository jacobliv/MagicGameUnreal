// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <map>
#include "Vector2.h"
#include "Globals.h"
#include "DrawDebugHelpers.h"
#include "GenerationData.h"
#include "Engine/DataTable.h"


#include "AutomataRenderer.generated.h"

UCLASS()
class MAGICGAME2D_API AAutomataRenderer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAutomataRenderer();
	void Render(GenerationData* data, UWorld* world);
	void setMaterials(UDataTable* Materials);
protected:
	UDataTable* materials;


};
