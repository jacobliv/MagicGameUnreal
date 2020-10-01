// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Tri.h"

/**
 * 
 */
class MAGICGAME2D_API MeshTri : public Tri
{
public:
	MeshTri();
	MeshTri(Vector2 p1, Vector2 p2, Vector2 p3, int i1, int i2, int i3);
	~MeshTri();


	int i1() const { return index1; }
	void setI1(int Index1) { index1 = Index1; }
	int i2() const { return index2; }
	void setI2(int Index2) { index2 = Index2; }
	int i3() const { return index3; }
	void setI3(int Index3) { index3 = Index3; }
protected:
	int index1;
	int index2;
	int index3;
};
