// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Vector2.h"

/**
 * 
 */
class MAGICGAME2D_API BoundingBox
{
public:
	BoundingBox();
	BoundingBox(float minX,float minZ, float maxX, float maxZ);
	BoundingBox(Vector2 min, Vector2 max);
	~BoundingBox();
	Vector2 min;
	Vector2 max;
	bool inside(Vector2 point);
};
