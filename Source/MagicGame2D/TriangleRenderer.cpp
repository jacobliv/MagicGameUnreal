// Fill out your copyright notice in the Description page of Project Settings.


#include "TriangleRenderer.h"

#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UTriangleRenderer::UTriangleRenderer()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTriangleRenderer::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTriangleRenderer::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTriangleRenderer::Render(GenerationData* data, UWorld* world) {
	if (data->getTriangles() == nullptr || !Globals::SHOW_TRIANGLES) return;
	for (auto values : *data->getTriangles()) {
		if(values.second == nullptr) continue;
		for (auto tri : *values.second) {
			DrawDebugLine(world, tri.getPoint1().getFVector(),tri.getPoint2().getFVector(),FColor::Red);
			DrawDebugLine(world, tri.getPoint2().getFVector(),tri.getPoint3().getFVector(),FColor::Red);
			DrawDebugLine(world, tri.getPoint3().getFVector(),tri.getPoint1().getFVector(),FColor::Red);

		}

	}

}

