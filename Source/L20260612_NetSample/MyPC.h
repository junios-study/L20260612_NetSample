// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPC.generated.h"

/**
 * 
 */
UCLASS()
class L20260612_NETSAMPLE_API AMyPC : public APlayerController
{
	GENERATED_BODY()
	
public:

	AMyPC();

	virtual void OnPossess(APawn* aPawn) override;

	virtual void BeginPlay() override;


};
