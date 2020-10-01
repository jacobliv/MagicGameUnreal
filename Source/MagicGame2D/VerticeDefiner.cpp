// Fill out your copyright notice in the Description page of Project Settings.


#include "VerticeDefiner.h"

#include <memory>

VerticeDefiner::VerticeDefiner()
{
}

VerticeDefiner::~VerticeDefiner()
{
}

void VerticeDefiner::addBelow(const std::shared_ptr<ControlNode>& node, TArray<FVector> vertices) {
    if(node->getBelow() != nullptr) {
        add(node->getBelow()->getLocation().getFVector(),vertices);
    }
}

void VerticeDefiner::addCenter(const std::shared_ptr<ControlNode>& node, TArray<FVector> vertices) {
    if(node->getBelow() != nullptr && node->getRight() != nullptr) {
        add(node->getRight()->getLocation().add(Vector2(0,-Globals::SQUARE_SIZE/2.f)).getFVector(), vertices);
    }
}

void VerticeDefiner::addRight(const std::shared_ptr<ControlNode>& node, TArray<FVector> vertices) {
    if(node->getRight() != nullptr) {
        add(node->getRight()->getLocation().getFVector(),vertices);
    }
}

void VerticeDefiner::add(const FVector pos, TArray<FVector> vertices) {
    vertices.Add(pos);
}


void VerticeDefiner::defineVertices(GenerationData* data) {
    TArray<FVector> vertices;
    for (auto values : *(*data).getControlNodes()) {
        std::shared_ptr<ControlNode> node = values.second;
        addBelow(node, vertices);
        addCenter(node, vertices);
        add(node->getLocation().getFVector(), vertices);
        addRight(node, vertices);
    }
    data->setVertices(std::make_shared<TArray<FVector>>(vertices));
}
