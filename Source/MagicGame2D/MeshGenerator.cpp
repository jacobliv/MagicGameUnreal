// Fill out your copyright notice in the Description page of Project Settings.


#include "MeshGenerator.h"


#include "Chunk.h"
#include "GenerationData.h"

// Sets default values
AMeshGenerator::AMeshGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	cellularAutomata = CreateDefaultSubobject<UCellularAutomata>("Automata");
	marchingSquares = CreateDefaultSubobject<UMarchingSquares>("Marching Squares");
	automataRenderer = CreateDefaultSubobject<AAutomataRenderer>("Automata Renderer");
	squareRenderer = CreateDefaultSubobject<USquareRenderer>("Square Renderer");
	triangleRenderer = CreateDefaultSubobject<UTriangleRenderer>("Triangle Renderer");

}

// Called when the game starts or when spawned
void AMeshGenerator::BeginPlay()
{
	Super::BeginPlay();
	generationData = GenerationData(materials);
	generationData.setBoundingBox(make_shared<BoundingBox>(Vector2(0,0),
		Vector2(Globals::SQUARE_SIZE*Globals::CHUNK_SIZE,Globals::SQUARE_SIZE*Globals::CHUNK_SIZE)));
	cellularAutomata->Generate(&generationData);
	marchingSquares->Generate(&generationData);
	automataRenderer->setMaterials(materials);
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Name = FName("Chunk-"+Vector2(0,0).toString());
	AChunk* chunk = GetWorld()->SpawnActor<AChunk>(Vector2(0,0).getFVector(),FRotator(0,0,0), SpawnInfo);
	chunk->SetFolderPath("Chunks");
	chunk->setGenerationData(make_shared<GenerationData>(generationData));
	chunk->setMaterial(material);

	chunk->createMesh();
}

// Called every frame
void AMeshGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	squareRenderer->Render(&generationData,GetWorld());
	automataRenderer->Render(&generationData,GetWorld());
	triangleRenderer->Render(&generationData,GetWorld());

}

