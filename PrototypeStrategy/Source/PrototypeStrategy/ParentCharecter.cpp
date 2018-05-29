// Fill out your copyright notice in the Description page of Project Settings.

#include "ParentCharecter.h"


// Sets default values
AParentCharecter::AParentCharecter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AParentCharecter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AParentCharecter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Move actor to next poin
	if (isCanMove)
	{

		this->SetActorLocation(FMath::Lerp(this->GetActorLocation(), mov_NextPoint, v_Alpha));
		v_Alpha += DeltaTime / koef_Speed;
		if (v_Alpha > 1.f)
		{
			isCanMove = false;
		}
	}
}

void AParentCharecter::GoByWay_Implementation(const TArray<FVector>& PointWay)
{	
	if (Move_anim == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Move_anim is empty"));
		return;
	}


	for (FVector Point : PointWay)
	{
		float v_Alpha = 0.f;
		while (v_Alpha <= 1.f)
		{
			this->SetActorLocation(FMath::Lerp(this->GetActorLocation(), Point, v_Alpha));
			v_Alpha += 0.0000001f;
		}
		
	}
	//	double time_alg = FPlatformTime::Seconds();
		//double time_anim = Move_anim;

}

// Called to bind functionality to input
void AParentCharecter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
