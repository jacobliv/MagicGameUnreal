// Fill out your copyright notice in the Description page of Project Settings.


#include "Chunk.h"

// Sets default values
AChunk::AChunk()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	terrainMesh = CreateDefaultSubobject<UProceduralMeshComponent>("ChunkMesh");
	terrainMesh->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	terrainMesh->AddLocalRotation(FRotator(0,0,180));
	meshInstantiator = CreateDefaultSubobject<UMeshInstantiator>("Mesh Instantiator");
	// terrainMesh->SetMaterial(0,material);


}

// Called when the game starts or when spawned
void AChunk::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AChunk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AChunk::createMesh() {
	UE_LOG(LogTemp, Warning, TEXT("GOING TO CREATE MESH" ));

	meshInstantiator->instantiate(terrainMesh,generationData);
}

