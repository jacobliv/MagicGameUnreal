// Fill out your copyright notice in the Description page of Project Settings.


#include "BoundingBox.h"

BoundingBox::BoundingBox()
{
}

BoundingBox::BoundingBox(float minX, float minZ, float maxX, float maxZ): min(Vector2(minX,minZ)), max(Vector2(maxX,maxZ))
{
    
}

BoundingBox::BoundingBox(Vector2 min, Vector2 max) : min(min), max(max)
{
}

BoundingBox::~BoundingBox()
{
}

bool BoundingBox::inside(Vector2 point)
{
    return point.X >= min.X && point.X <= max.X &&
        point.Z >= min.Z && point.Z <= max.Z;
}
