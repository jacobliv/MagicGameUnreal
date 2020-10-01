// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include <memory>

#include "Node.h"
#include "ControlNode.h"
#include "SquareTypeEnum.h"


/**
 * 
 */
class MAGICGAME2D_API Square
{
public:
	Square(std::shared_ptr<ControlNode> topLeft, std::shared_ptr<ControlNode>  topRight, std::shared_ptr<ControlNode>  bottomRight, std::shared_ptr<ControlNode>  bottomLeft);
	~Square();
	std::shared_ptr<Node> topLeft;
	std::shared_ptr<Node> topRight;
	std::shared_ptr<Node> bottomRight;
	std::shared_ptr<Node> bottomLeft;
	std::shared_ptr<Node> centerTop;
	std::shared_ptr<Node> centerRight;
	std::shared_ptr<Node> centerBottom;
	std::shared_ptr<Node> centerLeft;
	std::shared_ptr<Node> center;

	int getType() const { return type; }
	int getPointIndex(std::shared_ptr<Node> node);
private:
	int setType();
	int type;

};
