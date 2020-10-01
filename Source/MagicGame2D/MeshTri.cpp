// Fill out your copyright notice in the Description page of Project Settings.


#include "MeshTri.h"

MeshTri::MeshTri()
{
}

MeshTri::MeshTri(Vector2 p1, Vector2 p2, Vector2 p3, int i1, int i2, int i3): Tri(p1,p2,p3), index1(i1), index2(i2), index3(i3)
{}

MeshTri::~MeshTri()
{
}
