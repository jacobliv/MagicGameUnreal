// Fill out your copyright notice in the Description page of Project Settings.


#include "Square.h"

#include <memory>


Square::Square(std::shared_ptr<ControlNode>  topLeft, std::shared_ptr<ControlNode>  topRight, std::shared_ptr<ControlNode>  bottomRight, std::shared_ptr<ControlNode>  bottomLeft):
topLeft(topLeft), topRight(topRight), bottomRight(bottomRight), bottomLeft(bottomLeft),
centerTop(topLeft->getRight()),
centerRight(topRight->getBelow()),
centerBottom(bottomLeft->getRight()),
centerLeft(topLeft->getBelow()),
center(std::make_shared<Node>(topLeft->getLocation().add(Vector2(Globals::SQUARE_SIZE/2.f,-Globals::SQUARE_SIZE/2.f)),topLeft->getMaterial())),
type(setType())
{

}

Square::~Square()
{
}

int Square::getPointIndex(std::shared_ptr<Node> node) {
    if(node->getLocation() == topLeft->getLocation()) {
        return 1;
    } else if(node->getLocation() == centerTop->getLocation()) {
        return 2;
    } else if(node->getLocation() == topRight->getLocation()) {
        return 3;
    } else if(node->getLocation() == centerRight->getLocation()) {
        return 4;
    } else if(node->getLocation() == bottomRight->getLocation()) {
        return 5;
    } else if(node->getLocation() == centerBottom->getLocation()) {
        return 6;
    } else if(node->getLocation() == bottomLeft->getLocation()) {
        return 7;
    } else if(node->getLocation() == centerLeft->getLocation()) {
        return 8;
    } else if(node->getLocation() == center->getLocation()) {
        return 9;
    }
    return -1;
}

int Square::setType() {
    int t;
    if(topLeft->IsEnabled() && topRight->IsEnabled() && bottomRight->IsEnabled() && bottomLeft->IsEnabled()) {
        t = FULL;
    } else if(topLeft->IsEnabled() && topRight->IsEnabled() && bottomRight->IsEnabled()) {
        t = TL_TR_BR;
    } else if(topRight->IsEnabled() && bottomRight->IsEnabled() && bottomLeft->IsEnabled()) {
        t = TR_BR_BL;
    } else if(topLeft->IsEnabled() && bottomRight->IsEnabled() && bottomLeft->IsEnabled()) {
        t = TL_BR_BL;
    } else if(topLeft->IsEnabled() && topRight->IsEnabled() && bottomLeft->IsEnabled()) {
        t = TL_TR_BL;
    } else if(bottomRight->IsEnabled() && bottomLeft->IsEnabled()) {
        t = BR_BL;
    } else if(topRight->IsEnabled() && bottomLeft->IsEnabled()) {
        t = TR_BL;
    } else if(topRight->IsEnabled() && bottomRight->IsEnabled()) {
        t = TR_BR;
    } else if(topLeft->IsEnabled() && bottomLeft->IsEnabled()) {
        t = TL_BL;
    } else if(topLeft->IsEnabled() && bottomRight->IsEnabled()) {
        t = TL_BR;
    } else if(topLeft->IsEnabled() && topRight->IsEnabled()) {
        t = TL_TR;
    } else if(bottomLeft->IsEnabled()) {
        t = BL;
    } else if(bottomRight->IsEnabled()) {
        t = BR;
    } else if(topRight->IsEnabled()) {
        t = TR;
    } else if(topLeft->IsEnabled()) {
        t = TL;
    } else {
        t = EMPTY;
    }
    return t;
}
