// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataTable.h"
#include "MaterialDataTableStruct.generated.h"


USTRUCT(BlueprintType)
struct FMaterialDataTableStruct : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category=MaterialData)
    FString Name;
    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category=MaterialData)
    int Index;
    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category=MaterialData)
    float Hardness;
    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category=MaterialData)
    FString Color;
    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category=MaterialData)
    FString TerrainType;
    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category=MaterialData)
    bool baseMaterial;
    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category=MaterialData)
    float Friction;
    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category=MaterialData)
    float Frequency;
    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category=MaterialData)
    bool Ore;
    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category=MaterialData)
    FString VeinSize;
    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category=MaterialData)
    FString ItemsDropped;
    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category=MaterialData)
    FString DroppedItems;
    
};