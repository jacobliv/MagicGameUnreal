// Fill out your copyright notice in the Description page of Project Settings.


#include "Vector2.h"

Vector2::Vector2(float x, float z) {
	X = x;
	Z = z;
	hash = (X*13)+(Z*7);
	fVector = FVector(x, 0, z);
}

Vector2::Vector2(const Vector2& pos){
	X = pos.X;
	Z = pos.Z;
	hash = (X*13)+(Z*7);
	fVector = pos.fVector;
}

Vector2::Vector2(FVector pos) {
	X = pos.X;
	Z = pos.Z;
	hash = (X*13)+(Z*7);
	fVector = pos;
}

Vector2::Vector2() {
	X = 0;
	Z = 0;
	
	fVector = FVector(0, 0, 0);
}

FVector Vector2::getFVector() {
	return fVector;
}

Vector2 Vector2::add(Vector2 value)
{
	Vector2 cpy = this->cpy();
	cpy.X += value.X;
	cpy.Z += value.Z;
	return cpy.cpy();
}

Vector2 Vector2::cpy()
{
	return Vector2(X,Z);
}



bool operator== (const Vector2& c1, const Vector2& c2){
	
	return (c1.X == c2.X &&
		c1.Z == c2.Z);
}

bool operator< (const Vector2& c1, const Vector2& c2) {
	if (c1.X != c2.X) return c1.X < c2.X;
	if (c1.Z != c2.Z) return c1.Z < c2.Z;
	return false;
}

bool operator> (const Vector2& c1, const Vector2& c2)
{
	return (c1.X > c2.X ||
		c1.Z > c2.Z);
}

bool operator!=(const Vector2& c1, const Vector2& c2) {
	return (c1.X != c2.X ||
        c1.Z != c2.Z);
}


