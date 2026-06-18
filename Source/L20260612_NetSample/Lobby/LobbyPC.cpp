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

}

void ALobbyPC::PostInitializeComponents()
{
	Super::PostInitializeComponents();


}
