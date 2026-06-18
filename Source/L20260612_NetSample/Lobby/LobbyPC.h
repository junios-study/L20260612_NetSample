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


	UFUNCTION(BlueprintCallable)
	void Kick();

	//Server to Client(UDP 비연결, 신뢰성 보장 X, 실행 될안 될수도 있어.)
	UFUNCTION(Client, Reliable)
	void S2C_Kick();
	void S2C_Kick_Implementation();


	UFUNCTION(Server, Reliable, WithValidation)
	void C2S_SendMessage(const FText& Message);
	bool C2S_SendMessage_Validate(const FText& Message);
	void C2S_SendMessage_Implementation(const FText& Message);

};
