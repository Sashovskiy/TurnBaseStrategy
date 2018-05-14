// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TitleCollision.generated.h"

UCLASS()
class PROTOTYPESTRATEGY_API ATitleCollision : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATitleCollision();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ZZZ")
	void XXX(const TArray<FVector>& WayToPoint);
	void XXX_Implementation(const TArray<FVector>& WayToPoint);
	
	
};
