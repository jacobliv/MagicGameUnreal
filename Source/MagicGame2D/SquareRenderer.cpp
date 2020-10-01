// Fill out your copyright notice in the Description page of Project Settings.


#include "SquareRenderer.h"
#include "DrawDebugHelpers.h"

USquareRenderer::USquareRenderer()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USquareRenderer::BeginPlay()
{
	Super::BeginPlay();
}

void USquareRenderer::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void USquareRenderer::Render(GenerationData* data, UWorld* world) {
	if(data->getSquares() == nullptr || !Globals::SHOW_SQUARES) return;
	std::shared_ptr<std::map<Vector2, int>> automata = data->getAutomata();
	for(auto square : *data->getSquares().get()) {
		DrawDebugBox(world, square->centerTop->getLocation().add(Vector2(0, -Globals::SQUARE_SIZE/2.f)).getFVector(),FVector(Globals::SQUARE_SIZE/2.f,0, Globals::SQUARE_SIZE / 2.f),FColor::FromHex(FString("0xffaabbff")));
	}

}

