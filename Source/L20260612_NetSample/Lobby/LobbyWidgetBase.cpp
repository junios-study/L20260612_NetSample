// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyWidgetBase.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/TextBlock.h"
#include "Components/ScrollBox.h"

void ULobbyWidgetBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();

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
}

void ULobbyWidgetBase::UpdateConnectionCount(const int32 InConnectionCount)
{
}


