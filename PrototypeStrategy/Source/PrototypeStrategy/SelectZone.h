// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GridData_st.h"
#include "GameFramework/Actor.h"
#include "SelectZone.generated.h"

UCLASS()
class PROTOTYPESTRATEGY_API ASelectZone : public AActor
{
	GENERATED_BODY()

private:
	void
		SpawnNextZone(int MovePoint, int SizeBeetwen, TArray<FVector> WayToTPoint, FVector MyPos);
public:	
	// Sets default values for this actor's properties
	ASelectZone();
	UFUNCTION(BlueprintCallable)
	void StartSpawn(int MovePoint, int SizeBeetwen, FVector MyPos);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TMap < FVector2D, FDataGrid1> MainGridData;
	TArray<FRotator> WithOrWithOutDiogonak(bool check);
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UInstancedStaticMeshComponent* ZoneMesh;
		
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ZZZ")
		void aXXX(int MovePoint, int SizeBeetwen, FVector MyPos);
	void aXXX_Implementation(int MovePoint, int SizeBeetwen, FVector MyPos);
	
};
