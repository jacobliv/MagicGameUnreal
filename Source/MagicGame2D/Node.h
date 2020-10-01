// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Vector2.h"
#include <stdlib.h>

/**
 * 
 */
class MAGICGAME2D_API Node
{
public:
	Node();
	Node(Vector2 loc, int mat);
	~Node(){};
	Vector2 getLocation();
	int getMaterial();
	friend bool operator< (const Node& c1, const Node& c2);


	bool IsEnabled() const { return enabled; }
protected:
	Vector2 location;
	int material;
	bool enabled;
};
