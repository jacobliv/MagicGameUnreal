// Fill out your copyright notice in the Description page of Project Settings.


#include "MeshInstantiator.h"

#include <string>

// Sets default values for this component's properties
UMeshInstantiator::UMeshInstantiator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


	// ...
}


// Called when the game starts
void UMeshInstantiator::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMeshInstantiator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMeshInstantiator::instantiate(UProceduralMeshComponent* mesh, const std::shared_ptr<GenerationData>& data){

	TArray<FVector> vertices;
	TArray<FLinearColor> colors;
	TArray<int> indices;
	 for (auto values : *data->getTriangles()) {
	 	std::shared_ptr<std::vector<Tri>> tris = values.second;
	 	for (auto tri : *tris) {
	 		vertices.Add(tri.point1.getFVector());
	 		colors.Add(FLinearColor::Blue);
	 		vertices.Add(tri.point2.getFVector());
	 		colors.Add(FLinearColor::Blue);
	 		vertices.Add(tri.point3.getFVector());
	 		colors.Add(FLinearColor::Blue);
	 		// break;
	 	}
	 	// break;
	 }
	// indices.Add(0);
	// indices.Add(1);
	// indices.Add(2);

	// UE_LOG(LogTemp, Warning, TEXT("Vert Size: %d" ),vertices.Num());
	// UE_LOG(LogTemp, Warning, TEXT("colors Size: %d" ),colors.Num());
	// UE_LOG(LogTemp, Warning, TEXT("Vert 1: %f %f" ),vertices.GetData()->X,vertices.GetData()->Z);


	// vertices.Add(FVector(0, -100, 0)); //lower left - 0
	// vertices.Add(FVector(0, -100, 100)); //upper left - 1
	// vertices.Add(FVector(0, 100, 0)); //lower right - 2 
	// vertices.Add(FVector(0, 100, 100)); //upper right - 3
	//
	// vertices.Add(FVector(100, -100, 0)); //lower front left - 4
	// vertices.Add(FVector(100, -100, 100)); //upper front left - 5
 //
	// vertices.Add(FVector(100, 100, 100)); //upper front right - 6
	// vertices.Add(FVector(100, 100, 0)); //lower front right - 7
 //
	// //Back face of cube
	// indices.Add(0);
	// indices.Add(2);
	// indices.Add(3);
	//
	// indices.Add(3);
	// indices.Add(1);
	// indices.Add(0);
 //
	// //Left face of cube
	// indices.Add(0);
	// indices.Add(1);
	// indices.Add(4);
	//
	// indices.Add(4);
	// indices.Add(1);
	// indices.Add(5);
	//
	//
	// //Front face of cube
	// indices.Add(4);
	// indices.Add(5);
	// indices.Add(7);
	//
	// indices.Add(7);
	// indices.Add(5);
	// indices.Add(6);
	//
 //
	// //Right face of cube
	// indices.Add(7);
	// indices.Add(6);
	// indices.Add(3);
	//
	// indices.Add(3);
	// indices.Add(2);
	// indices.Add(7);
	//
 //
	// //Top face
	// indices.Add(1);
	// indices.Add(3);
	// indices.Add(5);
	//
	// indices.Add(6);
	// indices.Add(5);
	// indices.Add(3);
	//
 //
	// //bottom face
	// indices.Add(2);
	// indices.Add(0);
	// indices.Add(4);
	//
	// indices.Add(4);
	// indices.Add(7);
	// indices.Add(2);
	//
 //
	// TArray<FLinearColor> VertexColors;
	// VertexColors.Add(FLinearColor(0.f, 0.f, 1.f));
	// VertexColors.Add(FLinearColor(1.f, 0.f, 0.f));
	// VertexColors.Add(FLinearColor(1.f, 0.f, 0.f));
	// VertexColors.Add(FLinearColor(0.f, 1.f, 0.f));
	// VertexColors.Add(FLinearColor(0.5f, 1.f, 0.5f));
	// VertexColors.Add(FLinearColor(0.f, 1.f, 0.f));
	// VertexColors.Add(FLinearColor(1.f, 1.f, 0.f));
	// VertexColors.Add(FLinearColor(0.f, 1.f, 1.f));
 
	mesh->CreateMeshSection_LinearColor(0, vertices, indices, TArray<FVector>(), TArray<FVector2D>(), colors, TArray<FProcMeshTangent>(),true);
}
