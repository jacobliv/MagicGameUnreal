// Fill out your copyright notice in the Description page of Project Settings.


#include "Global.h"

// Sets default values
AGlobal::AGlobal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGlobal::BeginPlay()
{
	Super::BeginPlay();
	
}


void AGlobal::PostLoad() {
	Super::PostLoad();
	Globals::SQUARE_SIZE = SQUARE_SIZE;
	Globals::CHUNK_SIZE = CHUNK_SIZE;
	Globals::SMOOTH_ITERATIONS = SMOOTH_ITERATIONS;
	Globals::SMOOTH_WALL_THRESHOLD = SMOOTH_WALL_THRESHOLD;
	Globals::SHOW_CONTROL_NODES = SHOW_CONTROL_NODES;
	Globals::SHOW_AUTOMATA = SHOW_AUTOMATA;
	Globals::SHOW_SQUARES = SHOW_SQUARES;
	Globals::SHOW_TRIANGLES = SHOW_TRIANGLES;
}

// Called every frame
void AGlobal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Globals::SHOW_CONTROL_NODES = SHOW_CONTROL_NODES;
	Globals::SHOW_AUTOMATA = SHOW_AUTOMATA;
	Globals::SHOW_SQUARES = SHOW_SQUARES;


}

