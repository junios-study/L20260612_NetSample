// Fill out your copyright notice in the Description page of Project Settings.


#include "RotateActor.h"
#include "Net/UnrealNetwork.h"


// Sets default values
ARotateActor::ARotateActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;
	SetNetUpdateFrequency(3.0f);
	SetReplicateMovement(false);

}

// Called when the game starts or when spawned
void ARotateActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotateActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		AddActorLocalRotation(FRotator(0, RotateSpeed * DeltaTime, 0));
		ServerRotationYaw = GetActorRotation().Yaw;
	}
	else
	{
		ClientTimeSinceUpdate += DeltaTime;
		if (ClientTimeLastUpdate < UE_KINDA_SMALL_NUMBER)
		{
			//ClientTimeLastUpdate 너무 작아서 0이면 다음 프레임 계산하자
			return;
		}

		float CalculateRotationYaw = ServerRotationYaw + (RotateSpeed * ClientTimeLastUpdate);
		float LerpAlpha = ClientTimeSinceUpdate / ClientTimeLastUpdate;

		//선형 보간법
		float ClientNewYaw = FMath::Lerp(ServerRotationYaw, CalculateRotationYaw, LerpAlpha);
		SetActorRotation(FRotator(0, ClientNewYaw, 0));

		//회전 보간을 사용한 방법
		//FRotator TargetRotation(GetActorRotation().Pitch, CalculateRotationYaw, GetActorRotation().Roll);

		//float InterpSpeed = 5.f;
		//FRotator NewRotation = FMath::RInterpTo(GetActorRotation(), TargetRotation, DeltaTime, InterpSpeed);
		//SetActorRotation(NewRotation);
	}

}

void ARotateActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ARotateActor, ServerRotationYaw);

}

void ARotateActor::OnRep_ServerRotationYaw()
{
	UE_LOG(LogTemp, Warning, TEXT("OnRep_ServerRotationYaw %f"), ServerRotationYaw);

	SetActorRotation(FRotator(0, ServerRotationYaw, 0));


	ClientTimeLastUpdate = ClientTimeSinceUpdate;
	ClientTimeSinceUpdate = 0;
}

