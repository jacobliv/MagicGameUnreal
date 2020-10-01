// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include <iosfwd>
#include <map>
#include <memory>
#include <vector>
#include <vector>



#include "ControlNodeTypes.h"
#include "GenerationData.h"
#include "Tri.h"
#include "TriangleTypeEnum.h"

/**
 * 
 */
class MAGICGAME2D_API Triangulator
{
public:
	Triangulator();
	~Triangulator();
	void addTriangles(std::vector<Tri>* tris, const std::shared_ptr<Node>& node, std::map<Vector2, std::shared_ptr<std::vector<Tri>>>* triangles);
	void createTriangles(const std::map<ControlNodeType,
		std::shared_ptr<Node>>& nodes,
		const std::vector<TriangleType>& triAdd,
		const std::vector<TriangleType>& external,
		const std::shared_ptr<Square>& square,
		std::map<Vector2, std::shared_ptr<std::vector<Tri>>>* tris);
	void triangulateSquare	(const std::shared_ptr<Square>& square, std::map<Vector2, std::shared_ptr<std::vector<Tri>>>* triangles);
	void triangulate(GenerationData* data);
};
