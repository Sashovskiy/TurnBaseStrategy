// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GridData_st.h"
#include "GameFramework/Actor.h"
#include "MoveZone.generated.h"

UCLASS()
class PROTOTYPESTRATEGY_API AMoveZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoveZone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	void CalcZone(int32 posX, int32 poY);

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FDataGrid1> cells;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 SizeX = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 SizeY = 10;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 SizeBeetwenCells = 130;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int32> test;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int32> test2;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Select Zone")
	void startAlgoritm(int32 posX, int32 posY);
	void startAlgoritm_Implementation(int32 posX, int32 posY);

	
	
};
