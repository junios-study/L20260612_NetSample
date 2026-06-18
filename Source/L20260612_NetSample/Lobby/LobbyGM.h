// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LobbyGM.generated.h"

/**
 * 
 */
UCLASS()
class L20260612_NETSAMPLE_API ALobbyGM : public AGameModeBase
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;


	FTimerHandle LeftTimerHandle;
};
