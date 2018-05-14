// Fill out your copyright notice in the Description page of Project Settings.

#include "SelectZone.h"
#include "TitleCollision.h"


// Sets default values
ASelectZone::ASelectZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ASelectZone::StartSpawn(int MovePoint, int SizeBeetwen, FVector MyPos)
{
	TArray<FVector> WayToTPoint_null;
	SpawnNextZone(MovePoint, SizeBeetwen, WayToTPoint_null, MyPos);
}

void ASelectZone::SpawnNextZone(int MovePoint, int SizeBeetwen, TArray<FVector> WayToTPoint, FVector MyPos)
{
	//Cheking for how many side to we go
	bool isSeven = false;
	if (MovePoint < 5)
	{

		return ;
	}
		
	else
		if (MovePoint >= 7)
			isSeven = true;
		else
			isSeven = false;



	TArray<FRotator> wayR = WithOrWithOutDiogonak(isSeven);
	int index_Way = 0;
	for(FRotator way : wayR)
	{
		TArray<FVector> Loc_WayToTPoint = WayToTPoint;

		index_Way++;
		FHitResult placeHit;
		FVector startpoint =( FRotationMatrix(way).GetScaledAxis(EAxis::X))*(((index_Way % 2 == 0) && (isSeven)) ? (sqrt(2)*SizeBeetwen) : SizeBeetwen);
		

		startpoint = startpoint + MyPos;
		UE_LOG(LogTemp, Warning, TEXT("Point: %s"),*startpoint.ToString());
		startpoint.Z = 50.f;
		TEnumAsByte<EObjectTypeQuery> ObjectToTrace = EObjectTypeQuery::ObjectTypeQuery7;
		TArray<TEnumAsByte<EObjectTypeQuery> > ObjectsToTraceAsByte;
		ObjectsToTraceAsByte.Add(ObjectToTrace);
		GetWorld()->LineTraceSingleByObjectType(placeHit, startpoint, FVector(startpoint.X, startpoint.Y, -90.f), ObjectsToTraceAsByte);
		ATitleCollision* Title = Cast<ATitleCollision>(placeHit.GetActor());
	//	if(Title != nullptr)
	//	Title->XXX();
		if(auto hitZone = MainGridData.Find(FVector2D(startpoint.X, startpoint.Y)))
			if (!hitZone->isSelect)
			{
				hitZone->MoveCostToThisPoint = MovePoint - (((index_Way % 2 == 0) && (isSeven)) ? 7 : 5);
				TArray<FVector> TEMP_WayToPoint = WayToTPoint;
				TEMP_WayToPoint.Add(startpoint);
				hitZone->WayToPoint = TEMP_WayToPoint;
				SpawnNextZone(hitZone->MoveCostToThisPoint, SizeBeetwen, TEMP_WayToPoint, startpoint);
			}
			else
			{
				if ((hitZone->MoveCostToThisPoint > MovePoint - (((index_Way % 2 == 0) && (isSeven)) ? 7 : 5)))
				{
					hitZone->MoveCostToThisPoint = MovePoint - (((index_Way % 2 == 0) && (isSeven)) ? 7 : 5);
					TArray<FVector> TEMP_WayToPoint = WayToTPoint;
					TEMP_WayToPoint.Add(startpoint);
					hitZone->WayToPoint = TEMP_WayToPoint;
					SpawnNextZone(hitZone->MoveCostToThisPoint, SizeBeetwen, TEMP_WayToPoint, startpoint);
				}
			}




	//TODO Cheking if we can spawn in this place "SelectZoneMesh" 
		
	//TODO Search cell for our point
	//TODO Set Way or  Replace Way if our way cost less
	//TODO Spawn Instance and Change Main Grid Data
	
	}

}

TArray<FRotator> ASelectZone::WithOrWithOutDiogonak(bool check)
{
	
	TArray<FRotator> out;
	if (check)
		for (int i = 0; i < 4; i++)
			out.Add(FRotator(0.f, 90.f*i, 0.f));
	else
		for (int i = 0; i < 8; i++)
			out.Add(FRotator(0.f, 45.f*i, 0.f));
	


	return out;
}

// Called when the game starts or when spawned
void ASelectZone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASelectZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASelectZone::aXXX_Implementation(int MovePoint, int SizeBeetwen, FVector MyPos)
{

	StartSpawn(MovePoint, SizeBeetwen, MyPos);
	
}

