// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyWidgetBase.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/TextBlock.h"
#include "Components/ScrollBox.h"
#include "Animation/WidgetAnimation.h"
#include "LobbyPC.h"
#include "Kismet/GameplayStatics.h"
#include "LobbyGM.h"

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
	ALobbyPC* PC = Cast<ALobbyPC>(GetOwningPlayer());
	if (PC)
	{
		PC->ShowLoadingScreen();
	}

	ALobbyGM* GM = Cast<ALobbyGM>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GM)
	{
		GM->StartGame();
	}
}

void ULobbyWidgetBase::PressSend()
{
	ALobbyPC* PC = Cast<ALobbyPC>(GetOwningPlayer());
	if (PC)
	{
		PC->C2S_SendMessage(InputText->GetText());
		InputText->SetText(FText::GetEmpty());
	}
}

void ULobbyWidgetBase::PressChatTextEnder(const FText& Text, ETextCommit::Type CommitMethod)
{
	ALobbyPC* PC = Cast<ALobbyPC>(GetOwningPlayer());
	
	if (!PC)
	{
		return;
	}

	switch (CommitMethod)
	{
		case ETextCommit::OnEnter:
			PC->C2S_SendMessage(Text);
			InputText->SetText(FText::GetEmpty());
			break;
		case ETextCommit::OnCleared:
			InputText->SetUserFocus(PC);
			break;
	}
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

void ULobbyWidgetBase::AddMessage(const FText& InMessage)
{
	if (ChatBox)
	{
		UTextBlock* NewText = NewObject<UTextBlock>(ChatBox);
		NewText->SetText(InMessage);

		auto CurrentFont = NewText->GetFont();
		CurrentFont.Size = 40;

		NewText->SetFont(CurrentFont);

		ChatBox->AddChild(NewText);
		ChatBox->ScrollToEnd();
	}
}


