// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/Item.h"
#include "Map05/DebugMacros.h"


// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	//如果不被指向，由于它不会有任何指向它的指针，GC会回收
	RootComponent = ItemMesh;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

	//SetActorLocation(FVector(0.f,0.f,200.f));
	//SetActorRotation(FRotator(0.f, 45.f, 0.f));
	
	//FVector localPostion = GetActorLocation();
	//FVector endLocalPostion = localPostion + GetActorForwardVector() * 100.f;
	//DRAW_POINT(endLocalPostion);
	//DRAW_LINE(localPostion, endLocalPostion, 1.0f);
	//DRAW_SPHERE(localPostion);
	//DRAW_VECTOR(localPostion, endLocalPostion);

	//int32 AvgInt = Avg<int32>(1, 3);
	//UE_LOG(LogTemp, Warning, TEXT("Avg of 1 and 3: %d"), AvgInt);
}

float AItem::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}


// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Movement rate in units of cm/s
	//float MovementRate = 50.f;
	//float RotationRate = 45.f;
	//MovementRate * DeltaTime(cm/s) * (s/frame) = (cm/frame)
	//AddActorWorldOffset(FVector(MovementRate * DeltaTime, 0.f, 0.f));
	//AddActorWorldRotation(FRotator(0.f, RotationRate * DeltaTime, 0.f));
	
	//FVector localPostion = GetActorLocation();
	//FVector endLocalPostion = localPostion + GetActorForwardVector() * 100.f;
	//DRAW_SPHERE_SingleFrame(localPostion);
	//DRAW_VECTOR_SingleFrame(localPostion, endLocalPostion);

	RunningTime += DeltaTime;
	//float DeltaZ = Amplitude * FMath::Sin(Value * TimeConstant);
	//AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));

	//FVector AvgVector = Avg<FVector>(GetActorLocation(), FVector::ZeroVector);
	//DRAW_POINT_SingleFrame(AvgVector);


}

