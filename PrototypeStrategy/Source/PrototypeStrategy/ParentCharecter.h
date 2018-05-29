// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ParentCharecter.generated.h"

UCLASS()
class PROTOTYPESTRATEGY_API AParentCharecter : public ACharacter
{
	GENERATED_BODY()

		float v_Alpha = 0.f;
		float koef_Speed = 1;
		bool isCanMove = false;
		FVector mov_NextPoint;
public:
	// Sets default values for this character's properties
	AParentCharecter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAnimSequence* Move_anim = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

		UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ZZZ")
	void GoByWay(const TArray<FVector>& PointWay);
	void GoByWay_Implementation(const TArray<FVector>& PointWay);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
