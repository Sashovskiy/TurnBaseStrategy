// Fill out your copyright notice in the Description page of Project Settings.

#include "ParentCharecter.h"
#include "Algo/Reverse.h"
#include "MainPlayerController.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"

// Sets default values
AParentCharecter::AParentCharecter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UAnimSequence> idle_temp(TEXT("AnimSequence'/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Idle_Pose.Idle_Pose'"));
	idle_anim = idle_temp.Object;
	static ConstructorHelpers::FObjectFinder<UAnimSequence> Move_temp(TEXT("AnimSequence'/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Sprint_Fwd.Sprint_Fwd'"));
	Move_anim = Move_temp.Object;
}

// Called when the game starts or when spawned
void AParentCharecter::BeginPlay()
{
	Super::BeginPlay();
	
	
	MainMesh = FindComponentByClass<USkeletalMeshComponent>();
	if(MainMesh == nullptr)
		UE_LOG(LogTemp, Warning, TEXT("MainMesh is empty"));

	
	
	
}

// Called every frame
void AParentCharecter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Move actor to next poin
	
	if(isCanMove)
	{

		
		
		this->SetActorLocation(FMath::Lerp(tempThisPos, mov_NextPoint, v_Alpha));
		v_Alpha += DeltaTime / coef_Speed;
		
		if(this->GetActorLocation().Equals(mov_NextPoint, 0.02f))
			UE_LOG(LogTemp, Warning, TEXT("Alpha is: %f, this -> Loc is: | X: %f | Y: %f | Z: %f | and  NextPoint is: | X: %f | Y: %f | Z: %f |"), v_Alpha, this->GetActorLocation().X, this->GetActorLocation().Y, this->GetActorLocation().Z, mov_NextPoint.X, mov_NextPoint.Y, mov_NextPoint.Z);
		if (v_Alpha >= 1.f)
		{
			isCanMove = false;
			
			this->SetActorLocation(mov_NextPoint);
			UE_LOG(LogTemp, Warning, TEXT("Actor location is: X:%f Y:%f Z:%f"), this->GetActorLocation().X, this->GetActorLocation().Y, this->GetActorLocation().Z);
			GetNextPoint();
			UE_LOG(LogTemp, Warning, TEXT("isCanMove set false!"));
		}
	}
}

void AParentCharecter::GoByWay_Implementation(const TArray<FVector>& PointWay, int32 moveCostToDec)
{	
	if (Move_anim == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Move_anim is empty"));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("MovePoint before: %d"), MovePoint);
	MovePoint -= moveCostToDec;
	UE_LOG(LogTemp, Warning, TEXT("moveCostToDec now: %d"), moveCostToDec);
	MovePoint = (MovePoint < 0) ? 0 : MovePoint;
	UE_LOG(LogTemp, Warning, TEXT("MovePoint now: %d"), MovePoint);


	PointWay_temp = PointWay;
	Algo::Reverse(PointWay_temp);
	
	if (PointWay_temp.Num() > 0)
	{
		isCanMove = true;
	}
	MainMesh->PlayAnimation(Move_anim, true);

	GetNextPoint();
}
bool AParentCharecter::GetNextPoint() 
{

	if (PointWay_temp.Num() > 0)
	{
		tempThisPos = this->GetActorLocation();
		bEndOfWay = true;
		
		mov_NextPoint = PointWay_temp.Pop();
		
		this->SetActorRotation(FRotator(0, UKismetMathLibrary::MakeRotFromX(mov_NextPoint - tempThisPos).Yaw, 0));
		
		UE_LOG(LogTemp, Warning, TEXT("mov_NextPoint is X:%f , Y:%f, Z:%f | Array: %d"), mov_NextPoint.X, mov_NextPoint.Y, mov_NextPoint.Z, PointWay_temp.Num());
		mov_NextPoint.Z = this->GetActorLocation().Z;
		v_Alpha = 0.f;
		isCanMove = true;
		return true;
	}

	MainMesh->SetAnimationMode(EAnimationMode::AnimationSingleNode);
	if (bEndOfWay)
	{
		UE_LOG(LogTemp, Warning, TEXT("We in the end of our jorney? | Array: %d"), mov_NextPoint.X, mov_NextPoint.Y, mov_NextPoint.Z, PointWay_temp.Num());
		AMainPlayerController* Con = Cast<AMainPlayerController>(GetWorld()->GetFirstPlayerController());
		if (MovePoint >= 5)
			Con->NewCalculate();
		else
			Con->PointsOver();
	}
	MainMesh->PlayAnimation(idle_anim, true);
	return false;
}



// Called to bind functionality to input
void AParentCharecter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
