// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Global.h"

/**
 * 
 */
class MAGICGAME2D_API Globals
{
public:

	Globals();
	~Globals();
	static int SQUARE_SIZE;
	static int CHUNK_SIZE;
	static int SMOOTH_ITERATIONS;
	static int SMOOTH_WALL_THRESHOLD;
	static bool SHOW_CONTROL_NODES;
	static bool SHOW_AUTOMATA;
	static bool SHOW_SQUARES;
	static bool SHOW_TRIANGLES;
};
