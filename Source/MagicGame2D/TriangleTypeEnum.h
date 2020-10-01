// Fill oTt yoTr copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

enum TriangleType {
    T_TL,
    B_TL,
    T_TR,
    B_TR,
    T_BR,
    B_BR,
    T_BL,
    B_BL
};

//  char * getTriangleTypeName(TriangleType type) {
//     switch (type) {
//     case T_TL: return "Top-TopLeft";
//     case B_TL: return "Bottom-TopLeft";
//     case T_TR: return "Top-TopRight";
//     case B_TR: return "Bottom-TopRight";
//     case T_BR: return "Top-BottomRight";
//     case B_BR: return "Bottom-BottomRight";
//     case T_BL: return "Top-BottomLeft";
//     case B_BL: return "Bottom-BottomLeft";
//     default: return   "Not found";
//     }
// }