// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DrawDebugHelpers.h"

#define DRAW_SPHERE(Location) if(GetWorld()) DrawDebugSphere(GetWorld(),Location,25.f,12,FColor::Red,true);

#define DRAW_LINE(SP,EP,W) if(GetWorld()) DrawDebugLine(GetWorld(),SP,EP,FColor::Red,true,-1.f,0,W);

#define DRAW_POINT(Location) if(GetWorld())  DrawDebugPoint(GetWorld(), Location, 25.f, FColor::Blue, true);