// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

#include "ParentCharecter.generated.h"


UCLASS()
class PROTOTYPESTRATEGY_API AParentCharecter : public ACharacter
{
	GENERATED_BODY()



private:
		float v_Alpha = 0.f; //Alpha for lerp
		float coef_Speed = 1.f; //Speed Coefficient, 1 or more - slower, 0.1 or less - faster
		bool isCanMove = false; // if true char move, if false char no move! it simply
		
private:
		bool GetNextPoint(); // chek if we have point to go, if yes set nextpoint and isCanMove
private:
		FVector mov_NextPoint;
		FVector tempThisPos = this->GetActorLocation();
		TArray<FVector> PointWay_temp;
private:
		USkeletalMeshComponent* MainMesh = nullptr; 
		UAnimSequence* idle_anim = nullptr;
		UAnimSequence* Move_anim = nullptr;
public:
	// Sets default values for this character's properties
	AParentCharecter();
	UPROPERTY(BlueprintReadOnly)
	int32 MovePoint = 70;
		

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
		UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ZZZ")
	void GoByWay(const TArray<FVector>& PointWay, int32 moveCostToDec);
	void GoByWay_Implementation(const TArray<FVector>& PointWay, int32 moveCostToDec);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
