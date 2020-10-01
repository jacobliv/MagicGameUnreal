// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GenerationData.h"
#include "MeshInstantiator.h"
#include "GameFramework/Actor.h"
#include "Chunk.generated.h"

UCLASS()
class MAGICGAME2D_API AChunk : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChunk();
	UPROPERTY(EditAnywhere)
	UProceduralMeshComponent* terrainMesh;
	UMaterial* material;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	std::shared_ptr<GenerationData> generationData;
	UMeshInstantiator* meshInstantiator;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	inline void setGenerationData(const std::shared_ptr<GenerationData>& gData){generationData = gData;}
	void createMesh();
	inline void setMaterial(UMaterial* Material) {
		material = Material;
		terrainMesh->SetMaterial(0,material);
	}

};
