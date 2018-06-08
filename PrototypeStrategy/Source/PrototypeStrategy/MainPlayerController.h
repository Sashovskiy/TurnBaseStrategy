// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PROTOTYPESTRATEGY_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:		
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MoveAndCalculate")
	void NewCalculate();
	void NewCalculate_Implementation();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MoveAndCalculate")
		void PointsOver();
	void PointsOver_Implementation();
	UFUNCTION(BlueprintCallable, BlueprintPure , Category = "Sec")
		float GetSec();
};
