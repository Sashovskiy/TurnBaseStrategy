// Fill out your copyright notice in the Description page of Project Settings.

#include "TitleCollision.h"


// Sets default values
ATitleCollision::ATitleCollision()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATitleCollision::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATitleCollision::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void ATitleCollision::XXX_Implementation(const TArray<FVector>& WayToPoint)
{
	
}
