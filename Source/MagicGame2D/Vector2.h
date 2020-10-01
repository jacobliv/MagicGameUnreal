// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <stdlib.h>

/**
 * 
 */
class MAGICGAME2D_API Vector2
{
public:
	Vector2(float x, float z);
	Vector2(const Vector2& pos);
	Vector2(FVector pos);
	Vector2();
	float X;
	float Z;
	int hash;
	FVector getFVector();
	Vector2 add(Vector2 value);
	Vector2 cpy();
	FString toString(){return FString::SanitizeFloat(X)+"," + FString::SanitizeFloat(Z);};


protected:

	FVector fVector;

public:
	// friend bool operator< (const Vector2& c2) const;

	friend bool operator< (const Vector2& c1, const Vector2& c2);
	friend bool operator== (const Vector2& c1, const Vector2& c2);
	friend bool operator> (const Vector2& c1, const Vector2& c2);
	friend bool operator!= (const Vector2& c1, const Vector2& c2);
	// friend bool operator<= (const Vector2& c1, const Vector2& c2);
	// friend bool operator>= (const Vector2& c1, const Vector2& c2);

};
