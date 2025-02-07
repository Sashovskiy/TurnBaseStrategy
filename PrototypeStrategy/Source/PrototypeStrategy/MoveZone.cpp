// Fill out your copyright notice in the Description page of Project Settings.

#include "MoveZone.h"
#include "CoreMinimal.h"

// Sets default values
AMoveZone::AMoveZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AMoveZone::BeginPlay()
{
	Super::BeginPlay();

	

}

void AMoveZone::CalcZone(int32 posX, int32 posY)
{

	double time_alg = FPlatformTime::Seconds();

	TArray<int32> mapMask ;
	TArray<int32> mapDistance; 
	TArray<int32> mapMarked; 
	TArray<int32> mapActionPoint;
	TArray<int32> list;
	
	
	for (auto& cell : cells)
	{
		cell.WayToPoint.Empty();
		mapMask.Add(0); 
		mapDistance.Add(100000); 
		mapMarked.Add(0); 
		mapActionPoint.Add(80);
	}


	list.Add(posY*SizeX + posX);
	mapActionPoint[posY*SizeX + posX] = 0;
	mapDistance[posY*SizeX + posX] = 0;
	mapMarked[posY*SizeX + posX] = 1;
	mapMask = mapMask_BP;
	do	
	{
	int32  indexToAlg; 
	list.HeapPop(indexToAlg, true);
	
	bool isSeven = false;
	
	if (mapActionPoint[indexToAlg] >= MovePoint)// 
		continue;
	if(mapActionPoint[indexToAlg]+5 > MovePoint)
		continue;
	
	if (mapActionPoint[indexToAlg] + 7 <= MovePoint)
		isSeven = true;
	int32 Px, Py;

	Px = indexToAlg % SizeX;
	Py = indexToAlg / SizeX;
	
	if (isSeven)
	{
		
		if (((Py + 1) < SizeY))// && 
			if(mapMask[(Py + 1)*SizeX + Px] == 0 )
			if((mapDistance[(Py + 1)*SizeX + Px] > (mapDistance[indexToAlg] + 5)) && (mapActionPoint[(Py + 1)*SizeX + Px] > (mapActionPoint[indexToAlg] + 5)))
		{
			list.Add((Py + 1)*SizeX + Px);
			mapDistance[(Py + 1)*SizeX + Px] = (mapDistance[indexToAlg] + 5);
			mapMarked[(Py + 1)*SizeX + Px] = 1;
			mapActionPoint[(Py + 1)*SizeX + Px] = (mapActionPoint[indexToAlg] + 5);
			cells[(Py + 1)*SizeX + Px].WayToPoint = cells[indexToAlg].WayToPoint;
			cells[(Py + 1)*SizeX + Px].WayToPoint.Add(cells[(Py + 1)*SizeX + Px].PointVec);
		}
		if (((Px - 1) >= 0) )//&& 
			if (mapMask[Py*SizeX + (Px - 1)] == 0)
			if((mapDistance[Py*SizeX + (Px - 1)] > (mapDistance[indexToAlg] + 5)) && (mapActionPoint[Py*SizeX + (Px - 1)] > (mapActionPoint[indexToAlg] + 5)))
		{
			list.Add(Py*SizeX + (Px - 1));
			mapDistance[Py*SizeX + (Px - 1)] = (mapDistance[indexToAlg] + 5);
			mapMarked[Py*SizeX + (Px - 1)] = 1;
			mapActionPoint[Py*SizeX + (Px - 1)] = (mapActionPoint[indexToAlg] + 5);
			cells[Py*SizeX + (Px - 1)].WayToPoint = cells[indexToAlg].WayToPoint; 
			cells[Py*SizeX + (Px - 1)].WayToPoint.Add(cells[Py*SizeX + (Px - 1)].PointVec);
		}
		if (((Px + 1) < SizeX)) //&& 
			if (mapMask[Py*SizeX + (Px + 1)] == 0)
			if((mapDistance[Py*SizeX + (Px + 1)] > (mapDistance[indexToAlg] + 5)) && (mapActionPoint[Py*SizeX + (Px + 1)] > (mapActionPoint[indexToAlg] + 5)))
		{
			list.Add(Py*SizeX + (Px + 1));
			mapDistance[Py*SizeX + (Px + 1)] = (mapDistance[indexToAlg] + 5);
			mapMarked[Py*SizeX + (Px + 1)] = 1;
			mapActionPoint[Py*SizeX + (Px + 1)] = (mapActionPoint[indexToAlg] + 5);
			cells[Py*SizeX + (Px + 1)].WayToPoint = cells[indexToAlg].WayToPoint; 
			cells[Py*SizeX + (Px + 1)].WayToPoint.Add(cells[Py*SizeX + (Px + 1)].PointVec);
		}
		if (((Py - 1) >= 0) )//&& 
			if (mapMask[(Py - 1)*SizeX + Px] == 0)
			if((mapDistance[(Py - 1)*SizeX + Px] > (mapDistance[indexToAlg] + 5)) && (mapActionPoint[(Py - 1)*SizeX + Px] > (mapActionPoint[indexToAlg] + 5)))
		{
			list.Add((Py - 1)*SizeX + Px);
			mapDistance[(Py - 1)*SizeX + Px] = (mapDistance[indexToAlg] + 5);
			mapMarked[(Py - 1)*SizeX + Px] = 1;
			mapActionPoint[(Py - 1)*SizeX + Px] = (mapActionPoint[indexToAlg] + 5);
			cells[(Py - 1)*SizeX + Px].WayToPoint = cells[indexToAlg].WayToPoint;
			cells[(Py - 1)*SizeX + Px].WayToPoint.Add(cells[(Py - 1)*SizeX + Px].PointVec);
		}

		
		if (((((Py + 1) < SizeY) && (Px - 1) >= 0)) )//&& 
			if (mapMask[(Py + 1)*SizeX + (Px - 1)] == 0)
			if((mapDistance[(Py + 1)*SizeX + (Px - 1)] > (mapDistance[indexToAlg] + 7)) && (mapActionPoint[(Py + 1)*SizeX + (Px - 1)] > (mapActionPoint[indexToAlg] + 7)) )
		{
			list.Add((Py + 1)*SizeX + (Px - 1));
			mapDistance[(Py + 1)*SizeX + (Px - 1)] = (mapDistance[indexToAlg] + 7);
			mapMarked[(Py + 1)*SizeX + (Px - 1)] = 1;
			mapActionPoint[(Py + 1)*SizeX + (Px - 1)] = (mapActionPoint[indexToAlg] + 7);
			cells[(Py + 1)*SizeX + (Px - 1)].WayToPoint = cells[indexToAlg].WayToPoint;
			cells[(Py + 1)*SizeX + (Px - 1)].WayToPoint.Add(cells[(Py + 1)*SizeX + (Px - 1)].PointVec);
		}
		if (((((Py + 1) < SizeY) && (Px + 1) < SizeX)))// && 
			if (mapMask[(Py + 1)*SizeX + (Px + 1)] == 0)
			if((mapDistance[(Py + 1)*SizeX + (Px + 1)] > (mapDistance[indexToAlg] + 7)) && (mapActionPoint[(Py + 1)*SizeX + (Px + 1)] > (mapActionPoint[indexToAlg] + 7)) )
		{
			list.Add((Py + 1)*SizeX + (Px + 1));
			mapDistance[(Py + 1)*SizeX + (Px + 1)] = (mapDistance[indexToAlg] + 7);
			mapMarked[(Py + 1)*SizeX + (Px + 1)] = 1;
			mapActionPoint[(Py + 1)*SizeX + (Px + 1)] = (mapActionPoint[indexToAlg] + 7);
			cells[(Py + 1)*SizeX + (Px + 1)].WayToPoint = cells[indexToAlg].WayToPoint;
			cells[(Py + 1)*SizeX + (Px + 1)].WayToPoint.Add(cells[(Py + 1)*SizeX + (Px + 1)].PointVec);
		}
		if (((((Py - 1) >= 0) && (Px - 1) >= 0)))// && 
			if (mapMask[(Py - 1)*SizeX + (Px - 1)] == 0)
			if((mapDistance[(Py - 1)*SizeX + (Px - 1)] > (mapDistance[indexToAlg] + 7)) && (mapActionPoint[(Py - 1)*SizeX + (Px - 1)] > (mapActionPoint[indexToAlg] + 7)) )
		{
			list.Add((Py - 1)*SizeX + (Px - 1));
			mapDistance[(Py - 1)*SizeX + (Px - 1)] = (mapDistance[indexToAlg] + 7);
			mapMarked[(Py - 1)*SizeX + (Px - 1)] = 1;
			mapActionPoint[(Py - 1)*SizeX + (Px - 1)] = (mapActionPoint[indexToAlg] + 7);
			cells[(Py - 1)*SizeX + (Px - 1)].WayToPoint = cells[indexToAlg].WayToPoint; 
			cells[(Py - 1)*SizeX + (Px - 1)].WayToPoint.Add(cells[(Py - 1)*SizeX + (Px - 1)].PointVec);
		}
		if (((((Py - 1) >= 0) && (Px + 1) < SizeX)))// &&
			if (mapMask[(Py - 1)*SizeX + (Px + 1)] == 0)
			if((mapDistance[(Py - 1)*SizeX + (Px + 1)] > (mapDistance[indexToAlg] + 7)) && (mapActionPoint[(Py - 1)*SizeX + (Px + 1)] > (mapActionPoint[indexToAlg] + 7)) )
		{
			list.Add(((Py - 1)*SizeX + (Px + 1)));
			mapDistance[(Py - 1)*SizeX + (Px + 1)] = (mapDistance[indexToAlg] + 7);
			mapMarked[(Py - 1)*SizeX + (Px + 1)] = 1;
			mapActionPoint[(Py - 1)*SizeX + (Px + 1)] = (mapActionPoint[indexToAlg] + 7);
			cells[(Py - 1)*SizeX + (Px + 1)].WayToPoint = cells[indexToAlg].WayToPoint; 
			cells[(Py - 1)*SizeX + (Px + 1)].WayToPoint.Add(cells[(Py - 1)*SizeX + (Px + 1)].PointVec);
		}


	}
	else
	{
		
		if (((Py + 1) < SizeY))// && 
			if (mapMask[(Py + 1)*SizeX + Px] == 0)
			if ((mapDistance[(Py + 1)*SizeX + Px] > (mapDistance[indexToAlg] + 5)) && (mapActionPoint[(Py + 1)*SizeX + Px] > (mapActionPoint[indexToAlg] + 5)))
			{
				list.Add((Py + 1)*SizeX + Px);
				mapDistance[(Py + 1)*SizeX + Px] = (mapDistance[indexToAlg] + 5);
				mapMarked[(Py + 1)*SizeX + Px] = 1;
				mapActionPoint[(Py + 1)*SizeX + Px] = (mapActionPoint[indexToAlg] + 5);
				cells[(Py + 1)*SizeX + Px].WayToPoint = cells[indexToAlg].WayToPoint; 
				cells[(Py + 1)*SizeX + Px].WayToPoint.Add(cells[(Py + 1)*SizeX + Px].PointVec);
			}
		if (((Px - 1) >= 0))//&& 
			if (mapMask[Py*SizeX + (Px - 1)] == 0)
			if ((mapDistance[Py*SizeX + (Px - 1)] > (mapDistance[indexToAlg] + 5)) && (mapActionPoint[Py*SizeX + (Px - 1)] > (mapActionPoint[indexToAlg] + 5)))
			{
				list.Add(Py*SizeX + (Px - 1));
				mapDistance[Py*SizeX + (Px - 1)] = (mapDistance[indexToAlg] + 5);
				mapMarked[Py*SizeX + (Px - 1)] = 1;
				mapActionPoint[Py*SizeX + (Px - 1)] = (mapActionPoint[indexToAlg] + 5);
				cells[Py*SizeX + (Px - 1)].WayToPoint = cells[indexToAlg].WayToPoint;
				cells[Py*SizeX + (Px - 1)].WayToPoint.Add(cells[Py*SizeX + (Px - 1)].PointVec);
			}
		if (((Px + 1) < SizeX)) //&& 
			if (mapMask[Py*SizeX + (	Px + 1)] == 0)
			if ((mapDistance[Py*SizeX + (Px + 1)] > (mapDistance[indexToAlg] + 5)) && (mapActionPoint[Py*SizeX + (Px + 1)] > (mapActionPoint[indexToAlg] + 5)))
			{
				list.Add(Py*SizeX + (Px + 1));
				mapDistance[Py*SizeX + (Px + 1)] = (mapDistance[indexToAlg] + 5);
				mapMarked[Py*SizeX + (Px + 1)] = 1;
				mapActionPoint[Py*SizeX + (Px + 1)] = (mapActionPoint[indexToAlg] + 5);
				cells[Py*SizeX + (Px + 1)].WayToPoint = cells[indexToAlg].WayToPoint; 
				cells[Py*SizeX + (Px + 1)].WayToPoint.Add(cells[Py*SizeX + (Px + 1)].PointVec);
			}
		if (((Py - 1) >= 0))//&& 
			if (mapMask[(Py - 1)*SizeX + Px] == 0)
			if ((mapDistance[(Py - 1)*SizeX + Px] > (mapDistance[indexToAlg] + 5)) && (mapActionPoint[(Py - 1)*SizeX + Px] > (mapActionPoint[indexToAlg] + 5)))
			{
				list.Add((Py - 1)*SizeX + Px);
				mapDistance[(Py - 1)*SizeX + Px] = (mapDistance[indexToAlg] + 5);
				mapMarked[(Py - 1)*SizeX + Px] = 1;
				mapActionPoint[(Py - 1)*SizeX + Px] = (mapActionPoint[indexToAlg] + 5);
				cells[(Py - 1)*SizeX + Px].WayToPoint = cells[indexToAlg].WayToPoint;
				cells[(Py - 1)*SizeX + Px].WayToPoint.Add(cells[(Py - 1)*SizeX + Px].PointVec);
			}

	}


	}while (list.Num() > 0);
	
	

	
	test = mapMarked;
	//test2 = mapActionPoint;
	MoveCostToCell = mapActionPoint;
	time_alg = FPlatformTime::Seconds() - time_alg;


	UE_LOG(LogTemp, Warning, TEXT("time: %lf"), time_alg);


}

void AMoveZone::SetMoveZoneData(int32 SizeX, int32 SizeY, int32 SizeBeetwen)
{
	this->SizeBeetwenCells = SizeBeetwenCells;
	this->SizeX = SizeX;
	this->SizeY = SizeY;
}

// Called every frame
void AMoveZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMoveZone::startAlgoritm_Implementation(int32 posX, int32 posY, int32 MoveCostNow)
{
	MovePoint = MoveCostNow;
	if (MovePoint > 0)
	CalcZone(posX, posY);
	else
	UE_LOG(LogTemp, Warning, TEXT("MoveZone.cpp(235): MovePoint <= 0! Look code! MovePoint is %d"), MovePoint);

}

