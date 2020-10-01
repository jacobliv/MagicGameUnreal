// Fill out your copyright notice in the Description page of Project Settings.


#include "Triangulator.h"


#include <memory>
#include <memory>

#define stringify( name ) # name

#include "ControlNodeTypes.h"
#include "MeshTri.h"
#include "Tri.h"
#include "TriangleTypeEnum.h"

Triangulator::Triangulator()
{
}

Triangulator::~Triangulator()
{
}

void Triangulator::triangulate(GenerationData* data) {
    std::map<Vector2, std::shared_ptr<std::vector<Tri>>> tris= std::map<Vector2, std::shared_ptr<std::vector<Tri>>> ();
    
    for(auto &&values : *data->getSquares()) {
        std::map<Vector2, std::shared_ptr<std::vector<Tri>>> triangles;
        UE_LOG(LogTemp, Warning, TEXT("Vert 1: %f %f" ),(*values).topLeft->getLocation().X,(*values).topLeft->getLocation().Z);

        triangulateSquare(values,&triangles);
        tris.insert(triangles.begin(),triangles.end());
    }
    data->setTriangles(std::make_shared<std::map<Vector2, std::shared_ptr<std::vector<Tri>>>>(tris));
}



void Triangulator::triangulateSquare(const std::shared_ptr<Square>& square,
                                     std::map<Vector2, std::shared_ptr<std::vector<Tri>>>* triangles) {
    //UE_LOG(LogTemp, Warning, TEXT("StaRT with generated: %d" ),triangles->size());
    std::map<ControlNodeType,std::shared_ptr<Node>> nodes;
    std::vector<TriangleType> types;
    std::vector<TriangleType> external;

    switch (square->getType()) {
        case TL:
            nodes.emplace(TOP_LEFT,square->topLeft);
            types = {T_TL};
            external = {T_TL};

            break;
        case TR:
            nodes.emplace(TOP_RIGHT,square->topRight);
            types = {T_TR};
            external = {T_TR};

            break;
        case BR:
            nodes.emplace(BOTTOM_RIGHT,square->bottomRight);
            types = {B_BR};
            external = {B_BR};
            break;
        case BL:
            nodes.emplace(BOTTOM_LEFT,square->bottomLeft);
            types = {B_BL};
            external = {B_BL};

            break;
        case TL_TR:
            nodes.emplace(TOP_LEFT,square->topLeft);
            nodes.emplace(TOP_RIGHT,square->topRight);
            types = {T_TL,B_TL,T_TR,B_TR};
            external = {B_TL,B_TR};

            break;
        case TL_BR:
            nodes.emplace(TOP_LEFT,square->topLeft);
            nodes.emplace(BOTTOM_RIGHT,square->bottomRight);
            types = {T_TL,B_TL,B_TR,T_BR,B_BR,T_BL};
            external = {B_TR,T_BL};

            break;
        case TL_BL:
            nodes.emplace(TOP_LEFT,square->topLeft);
            nodes.emplace(BOTTOM_LEFT,square->bottomLeft);
            types = {T_TL,B_TL,T_BL,B_BL};
            external = {B_TL,T_BL};
            break;
        case TR_BR:
            nodes.emplace(TOP_RIGHT,square->topRight);
            nodes.emplace(BOTTOM_RIGHT,square->bottomRight);
            types = {T_TR,B_TR,T_BR,B_BR};
            external = {B_TR,T_BR};

            break;
        case TR_BL:
            nodes.emplace(TOP_RIGHT,square->topRight);
            nodes.emplace(BOTTOM_LEFT,square->bottomLeft);
            types = {T_TR,B_TR,T_BL,B_BL,B_TL,T_BR};
            external = {B_TL,T_BR};

            break;
        case BR_BL:
            nodes.emplace(BOTTOM_RIGHT,square->bottomRight);
            nodes.emplace(BOTTOM_LEFT,square->bottomLeft);
            types = {T_BR,B_BR,T_BL,B_BL};
            external = {T_BR,T_BL};

            break;
        case TL_TR_BR:
            nodes.emplace(TOP_LEFT,square->topLeft);
            nodes.emplace(TOP_RIGHT,square->topRight);
            nodes.emplace(BOTTOM_RIGHT,square->bottomRight);
            types = {T_TL,B_TL,T_TR,B_TR,T_BR,B_BR,T_BL};
            external = {T_BL};

            break;
        case TL_BR_BL:
            nodes.emplace(TOP_LEFT,square->topLeft);
            nodes.emplace(BOTTOM_RIGHT,square->bottomRight);
            nodes.emplace(BOTTOM_LEFT, square->bottomLeft);
            types = {T_TL,B_TL,T_BR,B_BR,T_BL,B_BL,B_TR};
            external = {B_TR};

            break;
        case TR_BR_BL:
            nodes.emplace(TOP_RIGHT,square->topRight);
            nodes.emplace(BOTTOM_RIGHT,square->bottomRight);
            nodes.emplace(BOTTOM_LEFT,square->bottomLeft);
            types = {T_TR,B_TR,T_BR,B_BR,T_BL,B_BL,B_TL};
            external = {B_TL};

            break;
        case TL_TR_BL:
            nodes.emplace(TOP_LEFT,square->topLeft);
            nodes.emplace(TOP_RIGHT,square->topRight);
            nodes.emplace(BOTTOM_LEFT,square->bottomLeft);
            types = {T_TL,B_TL,T_TR,B_TR,T_BL,B_BL,T_BR};
            external = {T_BR};

            break;
        case FULL:
            nodes.emplace(TOP_LEFT,square->topLeft);
            nodes.emplace(TOP_RIGHT,square->topRight);
            nodes.emplace(BOTTOM_RIGHT,square->bottomRight);
            nodes.emplace(BOTTOM_LEFT,square->bottomLeft);
            types = {T_TL,B_TL,T_TR,B_TR,T_BR,B_BR,T_BL,B_BL};
            external = {};
            break;

    }
    createTriangles(nodes,types,external,square, triangles);
}

void Triangulator::createTriangles(const std::map<ControlNodeType,std::shared_ptr<Node>>& nodes,
                                   const std::vector<TriangleType>& triAdd,
                                   const std::vector<TriangleType>& external,
                                   const std::shared_ptr<Square>& square,
                                   std::map<Vector2, std::shared_ptr<std::vector<Tri>>>* tris) {
    std::vector<Tri> triangles;
    for (auto tri : triAdd) {
        switch (tri) {
        case T_TL:

            triangles.push_back(MeshTri((*square).topLeft->getLocation(),
                                         (*square).centerTop->getLocation(),
                                         (*square).centerLeft->getLocation(),
                                         square->getPointIndex(square->topLeft),
                                         square->getPointIndex(square->centerTop),
                                         square->getPointIndex(square->centerLeft)));
                        
            break;
        case B_TL:
            triangles.push_back(MeshTri((*square).centerTop->getLocation(),
                                         (*square).center->getLocation(),
                                         (*square).centerLeft->getLocation(),
                                         square->getPointIndex(square->centerTop),
                                         square->getPointIndex(square->center),
                                         square->getPointIndex(square->centerLeft)));
            break;
        case T_TR:
            triangles.push_back(MeshTri((*square).centerTop->getLocation(),
                                         (*square).topRight->getLocation(),
                                         (*square).centerRight->getLocation(),
                                         square->getPointIndex(square->centerTop),
                                         square->getPointIndex(square->topRight),
                                         square->getPointIndex(square->centerRight)));
            break;
        case B_TR:
            triangles.push_back(Tri((*square).centerTop->getLocation(),
                                         (*square).centerRight->getLocation(),
                                         (*square).center->getLocation()));
            break;
        case T_BR:
            triangles.push_back(Tri((*square).centerRight->getLocation(),
                                         (*square).centerBottom->getLocation(),
                                         (*square).center->getLocation()));
            break;
        case B_BR:
            triangles.push_back(Tri((*square).centerRight->getLocation(),
                                         (*square).bottomRight->getLocation(),
                                         (*square).centerBottom->getLocation()));
            break;
        case T_BL:
            triangles.push_back(Tri((*square).centerBottom->getLocation(),
                                         (*square).centerLeft->getLocation(),
                                         (*square).center->getLocation()));
            break;
        case B_BL:
            triangles.push_back(Tri((*square).centerBottom->getLocation(),
                                         (*square).bottomLeft->getLocation(),
                                         (*square).centerLeft->getLocation()));
            break;
        default: ;
        }
    }
    for (auto values : nodes) {
        std::shared_ptr<Node> node = values.second;
        addTriangles(&triangles,node,tris);
    } 
}

void Triangulator::addTriangles(std::vector<Tri>* tris,
                                const std::shared_ptr<Node>& node,
                                std::map<Vector2,std::shared_ptr<std::vector<Tri>>>* triangles) {
    if(tris->size()>0) {
        std::vector<Tri> newTris;
        if(tris->size() >0) {
            // UE_LOG(LogTemp, Warning, TEXT("Inserting: %d" ),tris->size());
            newTris.insert(newTris.end(),tris->begin(),tris->end());
            // UE_LOG(LogTemp, Warning, TEXT("Now has: %d" ),newTris.size());
        }

        if((*triangles).count(node->getLocation()) != 0) {
            UE_LOG(LogTemp, Warning, TEXT("Already have" ));
            std::shared_ptr<std::vector<Tri>> values = (*triangles).at(node->getLocation());
            newTris.insert(newTris.end(),values->begin(),values->end());
        }
        // UE_LOG(LogTemp, Warning, TEXT("What does this have: %d" ),newTris.size());

        std::shared_ptr<std::vector<Tri>> triPtr = std::make_shared<std::vector<Tri>>(newTris);
 
        triangles->emplace(node->getLocation(),triPtr);

    }
}


