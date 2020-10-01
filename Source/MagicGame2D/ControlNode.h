// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Node.h"
#include "Globals.h"
#include "CoreMinimal.h"

/**
 * 
 */
class MAGICGAME2D_API ControlNode : public Node
{
public:
	ControlNode();
	ControlNode(Vector2 position, int material);
	~ControlNode();

protected:
	std::shared_ptr<Node> right;
	std::shared_ptr<Node> below;
public:
	std::shared_ptr<Node> getRight() { return right; }
	std::shared_ptr<Node> getBelow() { return below; }
};
