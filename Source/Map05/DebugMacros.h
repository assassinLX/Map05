#pragma once

#include "DrawDebugHelpers.h"

#define DRAW_SPHERE(Location) if(GetWorld()) DrawDebugSphere(GetWorld(),Location,25.f,12,FColor::Red,true);
#define DRAW_SPHERE_SingleFrame(Location) if(GetWorld()) DrawDebugSphere(GetWorld(),Location,25.f,12,FColor::Red,false,-1.f)

#define DRAW_LINE(StartLocation,EndLocation,Width) if(GetWorld()) DrawDebugLine(GetWorld(),StartLocation,EndLocation,FColor::Red,true,-1.f,0,Width);
#define DRAW_LINE_SingleFrame(StartLocation,EndLocation,Width) if(GetWorld()) DrawDebugLine(GetWorld(),StartLocation,EndLocation,FColor::Red,false,-1.f,0,Width);

#define DRAW_POINT(Location) if(GetWorld())  DrawDebugPoint(GetWorld(), Location, 25.f, FColor::Blue, true);
#define DRAW_POINT_SingleFrame(Location) if(GetWorld())  DrawDebugPoint(GetWorld(), Location, 25.f, FColor::Blue, false,-1.f);

#define DRAW_VECTOR(StartLocation,EndLocation) if(GetWorld())\
	{\
		DrawDebugPoint(GetWorld(), StartLocation, 10.f, FColor::Red, true);\
		DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 3.0f);\
	}
#define DRAW_VECTOR_SingleFrame(StartLocation,EndLocation) if(GetWorld())\
	{\
		DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, -1.f, 0, 3.0f);\
		DrawDebugPoint(GetWorld(), StartLocation, 10.f, FColor::Red, false,-1.f);\
	}