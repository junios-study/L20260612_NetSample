// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "LobbyGS.generated.h"

/**
 * 
 */
UCLASS()
class L20260612_NETSAMPLE_API ALobbyGS : public AGameStateBase
{
	GENERATED_BODY()
	
public:

	ALobbyGS();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Time", Replicated)
	int32 LeftTime = 180;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Time", Replicated)
	int32 ConnectionCount = 0;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void Tick(float DeltaSeconds) override;
};
