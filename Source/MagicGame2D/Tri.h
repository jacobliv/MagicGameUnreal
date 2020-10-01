// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Vector2.h"

/**
 * 
 */
class MAGICGAME2D_API Tri
{
public:
	Tri();
	Tri(Vector2 p1, Vector2 p2, Vector2 p3);
	~Tri();
	Vector2 point1;
	Vector2 point2;
	Vector2 point3;

	Vector2 getPoint1() const { return point1; }
	void setPoint1(const Vector2& Point1) { point1 = Point1; }
	Vector2 getPoint2() const { return point2; }
	void setPoint2(const Vector2& Point2) { point2 = Point2; }
	Vector2 getPoint3() const { return point3; }
	void setPoint3(const Vector2& Point3) { point3 = Point3; }
};
