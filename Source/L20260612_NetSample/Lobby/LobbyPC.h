// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LobbyPC.generated.h"


class ULobbyWidgetBase;
/**
 * 
 */
UCLASS()
class L20260612_NETSAMPLE_API ALobbyPC : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;

	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	TSubclassOf<ULobbyWidgetBase> LobbyWidgetTemplate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	TObjectPtr<ULobbyWidgetBase> LobbyWidgetObject;
};
