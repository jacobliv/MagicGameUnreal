// Fill out your copyright notice in the Description page of Project Settings.


#include "ControlNode.h"

#include <memory>

ControlNode::ControlNode(){}

ControlNode::ControlNode(Vector2 position, int material) : Node(position,material)
{
	Vector2 p1 = position.add(Vector2(((float)Globals::SQUARE_SIZE) / 2.0f, 0));
	right = std::make_shared<Node>(p1,material);
	Vector2 p2 = position.add(Vector2(0, (float)(-Globals::SQUARE_SIZE) / 2.0f));	
	below = std::make_shared<Node>(p2,material);
;
}

ControlNode::~ControlNode()
{
}
