// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/Item.h"
#include "Map05/Map05.h"


DEFINE_LOG_CATEGORY(ItemLog);


// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

	FVector localPostion = GetActorLocation();
	FVector endLocalPostion = localPostion + GetActorForwardVector() * 100.f;
	//DRAW_POINT(endLocalPostion);
	//DRAW_LINE(localPostion, endLocalPostion, 1.0f);
	//DRAW_SPHERE(localPostion);
	DRAW_VECTOR(localPostion, endLocalPostion)
}


// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

