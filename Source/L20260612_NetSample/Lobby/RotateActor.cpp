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

	//float 4 * 3 = 12byte  * 3 = 36byte;

	//4byte
}

