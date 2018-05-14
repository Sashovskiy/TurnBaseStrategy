// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
#include "Engine.h"

#include "GridData_st.generated.h"


/**
 * 
 
class PROTOTYPESTRATEGY_API GridData_st
{
public:
	GridData_st();
	~GridData_st();
};*/

USTRUCT(BlueprintType)
struct FDataGrid1
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 MoveCost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FVector> WayToPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isSelect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 MoveCostToThisPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector PointVec;

	 void copyMydata(FDataGrid1 &other)  
	{
		 this->MoveCost = other.MoveCost;
		 this->isSelect = other.isSelect;
		 this->MoveCostToThisPoint = other.MoveCostToThisPoint;
	
	}

	FDataGrid1()
	{
		MoveCost = 0;
		isSelect = false;
		MoveCostToThisPoint = 0;

	}

	FDataGrid1(int MC_c, TArray<FVector> WTP_c, bool iS_c, int32 MCTTP_c)
	{
		MoveCost = MC_c;
		WayToPoint = WTP_c;
		isSelect = iS_c;
		MoveCostToThisPoint = MCTTP_c;

	}

};