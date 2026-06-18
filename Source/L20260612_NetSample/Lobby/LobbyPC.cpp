// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPC.h"
#include "LobbyWidgetBase.h"
#include "Kismet/GameplayStatics.h"
#include "LobbyGS.h"


void ALobbyPC::BeginPlay()
{
	Super::BeginPlay();

	//DedicateServer, ListenServer, Client, StandAlone 다 되는 코드를 만들어야 됨
	if (IsLocalPlayerController())
	{
		LobbyWidgetObject = CreateWidget<ULobbyWidgetBase>(this, LobbyWidgetTemplate);
		if (LobbyWidgetObject)
		{
			LobbyWidgetObject->AddToViewport();
			if (HasAuthority()) //Listen Server, 현재 클라이언트 방장일때
			{
				LobbyWidgetObject->ShowStartButton();
				ALobbyGS* GS = Cast<ALobbyGS>(UGameplayStatics::GetGameState(GetWorld()));
				if (GS)
				{
					GS->OnRep_ConnectionCount();
				}
			}
		}
	}

	SetInputMode(FInputModeGameAndUI());
	bShowMouseCursor = true;
}

void ALobbyPC::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}


void ALobbyPC::Kick()
{
	//Server에서만 호출
	S2C_Kick();
}

//execute Client
void ALobbyPC::S2C_Kick_Implementation()
{
	GEngine->HandleDisconnect(GetWorld(), GetWorld()->GetNetDriver());
}

bool ALobbyPC::C2S_SendMessage_Validate(const FText& Message)
{
	//Execute Server

	return true;
}

void ALobbyPC::C2S_SendMessage_Implementation(const FText& Message)
{
	//Execute Server
	for (auto Iter = GetWorld()->GetPlayerControllerIterator(); Iter; Iter++)
	{
		ALobbyPC* OtherPC = Cast<ALobbyPC>(Iter->Get());
		if (OtherPC)
		{
			//call server
			OtherPC->S2C_SendMessage(Message);
		}
	}
}

void ALobbyPC::S2C_SendMessage_Implementation(const FText& Message)
{
	//execute client
	//UI 메세지 추가
	if (LobbyWidgetObject)
	{
		LobbyWidgetObject->AddMessage(Message);
	}
}

void ALobbyPC::ShowLoadingScreen_Implementation()
{
}
