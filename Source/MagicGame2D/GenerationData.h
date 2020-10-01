// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include <map>
#include <memory>



#include "BoundingBox.h"
#include "ControlNode.h"
#include "Square.h"
#include "Tri.h"
#include "Vector2.h"
#include <ProceduralMeshComponent.h>


#include "MaterialDataTableStruct.h"
#include "Engine/DataTable.h"

/**
 * 
 */
class MAGICGAME2D_API GenerationData
{
public:
	GenerationData();
	void setupMaterialMap();
	GenerationData(UDataTable* Materials);
	~GenerationData();
protected:
	std::shared_ptr<std::map<Vector2,int>> automata;
	std::shared_ptr<std::map<Vector2,std::shared_ptr<ControlNode>>> controlNodes;
	std::shared_ptr<std::vector<std::shared_ptr<Square>>> squares;
	std::shared_ptr<BoundingBox> boundingBox;
	std::shared_ptr<std::map<Vector2,std::shared_ptr<std::vector<Tri>>>> triangles;
	std::shared_ptr<UProceduralMeshComponent> terrainMesh;
	UDataTable* materials;
	std::shared_ptr<std::map<int,FMaterialDataTableStruct*>> indexedMaterials;
	std::shared_ptr<std::map<int,FMaterialDataTableStruct*>> baseMaterials;
	std::shared_ptr<std::map<int,FMaterialDataTableStruct*>> ores;
	std::shared_ptr<TArray<FVector>> vertices;

public:
	inline void setVertices(std::shared_ptr<TArray<FVector>> verts){vertices = verts;};
	inline std::shared_ptr<std::map<int,FMaterialDataTableStruct*>> GetBaseMaterials() const { return baseMaterials; }
	inline void SetBaseMaterials(const std::shared_ptr<std::map<int,FMaterialDataTableStruct*>>& BaseMaterials) {baseMaterials = BaseMaterials;}
	inline std::shared_ptr<std::map<int,FMaterialDataTableStruct*>> GetOres() const { return ores; }
	inline void SetOres(const std::shared_ptr<std::map<int,FMaterialDataTableStruct*>>& Ores) { ores = Ores; }
	inline UDataTable* getMaterials() const { return materials; }
	inline void setMaterials(UDataTable* Materials) { materials = Materials; }


	inline std::shared_ptr<std::map<int,FMaterialDataTableStruct*>> GetIndexedMaterials() const { return indexedMaterials; }

	inline void SetIndexedMaterials(const std::shared_ptr<std::map<int,FMaterialDataTableStruct*>>& IndexedMaterials) {
		indexedMaterials = IndexedMaterials;
	}

	inline void setTriangles(
		const std::shared_ptr<std::map<Vector2, std::shared_ptr<std::vector<Tri>>>>& Triangles) {triangles = Triangles;}
	inline std::shared_ptr<std::map<Vector2, std::shared_ptr<std::vector<Tri>>>> getTriangles() const {return triangles;}
	inline std::shared_ptr<UProceduralMeshComponent> getTerrainMesh() {return terrainMesh;}
	inline void setTerrainMesh(std::shared_ptr<UProceduralMeshComponent> tMesh) {terrainMesh = tMesh;}
	
	//getters/setters
	inline std::shared_ptr<std::map<Vector2,int>> getAutomata(){return automata;}
	inline void setAutomata(std::shared_ptr<std::map<Vector2,int>> autom) {this->automata = std::move(autom);};
	inline std::shared_ptr<std::map<Vector2,std::shared_ptr<ControlNode>>> getControlNodes(){return controlNodes;}
	inline void setControlNodes(std::shared_ptr<std::map<Vector2,std::shared_ptr<ControlNode>>> contrlNodes) {this->controlNodes = contrlNodes;};
	inline std::shared_ptr<std::vector<std::shared_ptr<Square>>>getSquares() {return squares;}
	inline void setSquares(std::shared_ptr<std::vector<std::shared_ptr<Square>>> sqrs) {this->squares = sqrs;}
	inline std::shared_ptr<BoundingBox> getBoundingBox() {return boundingBox;};
	inline void setBoundingBox(std::shared_ptr<BoundingBox> boundBox) { this-> boundingBox = boundBox;}
};
