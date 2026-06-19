// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotateActor.generated.h"

UCLASS()
class L20260612_NETSAMPLE_API ARotateActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARotateActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(ReplicatedUsing = "OnRep_ServerRotationYaw")
	float ServerRotationYaw;

	UFUNCTION()
	void OnRep_ServerRotationYaw();

	float RotateSpeed = 60.0f;

	//클라이언트에서 매 틱마다 회전한 시간(서버에 값을 받은 뒤로)
	float ClientTimeSinceUpdate = 0.0f;

	//서버에서 이전 값을 보내준 시간
	float ClientTimeLastUpdate = 0.0f;


};
