// Fill out your copyright notice in the Description page of Project Settings.


#include "AutomataRenderer.h"

#include "MaterialDataTableStruct.h"


// Sets default values
AAutomataRenderer::AAutomataRenderer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}



void AAutomataRenderer::Render(GenerationData* data, UWorld* world) {
	if (data->getAutomata() == nullptr) return;
	if(!Globals::SHOW_AUTOMATA) return; 
	std::shared_ptr<std::map<Vector2, int>> automata = data->getAutomata();

	for(auto pair : *data->getAutomata().get()) {
		Vector2 pos = pair.first;
		int onOff = pair.second;
		if (onOff>0) {
			FMaterialDataTableStruct* material = (*data->GetIndexedMaterials())[onOff];
			DrawDebugSolidBox(world, pos.getFVector(),FVector(Globals::SQUARE_SIZE/8.f,0, Globals::SQUARE_SIZE / 8.f),FColor::FromHex(material->Color));
		} else {
			// DrawDebugSolidBox(world, pos.getFVector(),FVector(Globals::SQUARE_SIZE/2.f,0, Globals::SQUARE_SIZE / 2.f),FColor::Black);
		}
	}
}

void AAutomataRenderer::setMaterials(UDataTable* Materials) {
	materials = Materials;
}
