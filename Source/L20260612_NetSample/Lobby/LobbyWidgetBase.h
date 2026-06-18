// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LobbyWidgetBase.generated.h"


class UButton;
class UEditableTextBox;
class UTextBlock;
class UScrollBox;

/**
 *
 */
UCLASS()
class L20260612_NETSAMPLE_API ULobbyWidgetBase : public UUserWidget
{
	GENERATED_BODY()
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (BindWidget))
	TObjectPtr<UButton> StartButton;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (BindWidgetOptional))
	TObjectPtr<UButton> SendButton;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (BindWidget))
	TObjectPtr<UTextBlock> LeftTime;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (BindWidget))
	TObjectPtr<UTextBlock> ConnectionCount;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (BindWidget))
	TObjectPtr<UScrollBox> ChatBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (BindWidget))
	TObjectPtr<UEditableTextBox> InputText;

	virtual void NativeOnInitialized() override;

	UFUNCTION()
	void PressStart();

	UFUNCTION()
	void PressSend();

	UFUNCTION()
	void PressChatTextEnder(const FText& Text, ETextCommit::Type CommitMethod);

	UFUNCTION()
	void ProcessTextChange(const FText& Text);

	UFUNCTION(BlueprintCallable)
	void UpdateLeftTime(const int32 InLeftTime);

	UFUNCTION(BlueprintCallable)
	void UpdateConnectionCount(const int32 InConnectionCount);

	UFUNCTION(BlueprintCallable)
	void ShowStartButton();

	UFUNCTION(BlueprintCallable)
	void AddMessage(const FText& InMessage);

	UPROPERTY(Transient, meta=(BindWidgetAnimOptional))
	TObjectPtr<UWidgetAnimation> ShowButtonAnimation;

};
