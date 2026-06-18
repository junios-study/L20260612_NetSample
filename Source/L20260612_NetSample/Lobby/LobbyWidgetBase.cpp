// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyWidgetBase.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/TextBlock.h"
#include "Components/ScrollBox.h"
#include "Animation/WidgetAnimation.h"

void ULobbyWidgetBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	//StartButton = Cast<UButton>(GetWidgetFromName(TEXT("StartButton")));

	//ShowButtonAnimation = Cast<UWidgetAnimation>(GetWidgetFromName(TEXT("StartButton")));

	StartButton->OnClicked.AddDynamic(this, &ULobbyWidgetBase::PressStart);
	if (SendButton)
	{
		SendButton->OnClicked.AddDynamic(this, &ULobbyWidgetBase::PressSend);
	}

	InputText->OnTextCommitted.AddDynamic(this, &ULobbyWidgetBase::PressChatTextEnder);
	InputText->OnTextChanged.AddDynamic(this, &ULobbyWidgetBase::ProcessTextChange);
	

}


void ULobbyWidgetBase::PressStart()
{

}

void ULobbyWidgetBase::PressSend()
{
}

void ULobbyWidgetBase::PressChatTextEnder(const FText& Text, ETextCommit::Type CommitMethod)
{
}

void ULobbyWidgetBase::ProcessTextChange(const FText& Text)
{
}

void ULobbyWidgetBase::UpdateLeftTime(const int32 InLeftTime)
{
	//cp-949(한글만됨) -> utf8 -> utf16
	FString Temp = FString::Printf(TEXT("%d 초"), InLeftTime);
	LeftTime->SetText(FText::FromString(Temp));
}

void ULobbyWidgetBase::UpdateConnectionCount(const int32 InConnectionCount)
{
	FString Temp = FString::Printf(TEXT("%d 명"), InConnectionCount);
	ConnectionCount->SetText(FText::FromString(Temp));
}

void ULobbyWidgetBase::ShowStartButton()
{
	if (ShowButtonAnimation)
	{
		StartButton->SetVisibility(ESlateVisibility::Visible);
		PlayAnimation(ShowButtonAnimation);
	}
}


