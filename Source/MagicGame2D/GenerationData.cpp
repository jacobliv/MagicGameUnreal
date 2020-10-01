// Fill out your copyright notice in the Description page of Project Settings.


#include "GenerationData.h"

#include <memory>

GenerationData::GenerationData()
{
}

void GenerationData::setupMaterialMap() {
    std::map<int,FMaterialDataTableStruct*> ore;
    std::map<int,FMaterialDataTableStruct*> bMaterials;
    std::map<int,FMaterialDataTableStruct*> indexed;


    for (auto RowName : materials->GetRowNames()) {
        FMaterialDataTableStruct* material = materials->FindRow<FMaterialDataTableStruct>(RowName,"Can't find it",false);
        indexed.emplace(material->Index,material);
        if(material->Ore) {
            ore.emplace(material->Index,material);
            continue;
        } else if(material->baseMaterial) {
            bMaterials.emplace(material->Index,material);
        }
    }
    ores = std::make_shared<std::map<int,FMaterialDataTableStruct*>>(ore);
    baseMaterials = std::make_shared<std::map<int,FMaterialDataTableStruct*>>(bMaterials);
    indexedMaterials = std::make_shared<std::map<int,FMaterialDataTableStruct*>>(indexed);
}

GenerationData::GenerationData(UDataTable* Materials):materials(Materials) {
    setupMaterialMap();
}

GenerationData::~GenerationData()
{
}
