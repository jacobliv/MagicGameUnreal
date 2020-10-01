// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GenerationData.h"

/**
 * 
 */
class MAGICGAME2D_API VerticeDefiner
{
public:
	VerticeDefiner();
	~VerticeDefiner();
	void addBelow(const std::shared_ptr<ControlNode>& node, TArray<FVector> vertices);
	void addCenter(const std::shared_ptr<ControlNode>& node, TArray<FVector> vertices);
	static void add(const FVector pos, TArray<FVector> vertices);
	void addRight(const std::shared_ptr<ControlNode>& node, TArray<FVector> vertices);
	void defineVertices(GenerationData* data);
};
