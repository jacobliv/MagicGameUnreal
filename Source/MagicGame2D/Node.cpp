// Fill out your copyright notice in the Description page of Project Settings.


#include "Node.h"

Node::Node()
{
}

Node::Node(Vector2 loc, int mat) : location(loc), material(mat), enabled(mat>0)
{}

Vector2 Node::getLocation()
{
	return location;
}

int Node::getMaterial()
{
	return material;
}

bool operator< (const Node& c1, const Node& c2) {
	return c1.location < c2.location;
}

