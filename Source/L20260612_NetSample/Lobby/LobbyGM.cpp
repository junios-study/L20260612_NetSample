// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGM.h"
#include "TimerManager.h"
#include "LobbyGS.h"

void ALobbyGM::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(
		LeftTimerHandle,
		[&]()
		{
			ALobbyGS* GS = GetGameState<ALobbyGS>();
			if (GS)
			{
				if (GS->LeftTime == 0)
				{
					GetWorld()->GetTimerManager().ClearTimer(LeftTimerHandle);
					StartGame();
				}
				{
					GS->LeftTime--; 
				}
			}
		},
		1,
		true
	);

	ALobbyGS* GS = GetGameState<ALobbyGS>();
	if (GS)
	{
		GS->ConnectionCount = GetNumPlayers();
		GS->OnRep_ConnectionCount();
	}
}

void ALobbyGM::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetWorld()->GetTimerManager().ClearTimer(LeftTimerHandle);

	Super::EndPlay(EndPlayReason);
}

void ALobbyGM::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	ALobbyGS* GS = GetGameState<ALobbyGS>();
	if (GS)
	{
		GS->ConnectionCount = GetNumPlayers();
		GS->OnRep_ConnectionCount();
	}
}

void ALobbyGM::Logout(AController* Exiting)
{
	Super::Logout(Exiting);

	UE_LOG(LogTemp, Warning, TEXT("Logout %s"), *Exiting->GetName());

	ALobbyGS* GS = GetGameState<ALobbyGS>();
	if (GS)
	{
		GS->ConnectionCount = GetNumPlayers() - 1;
		GS->OnRep_ConnectionCount();
	}
}

void ALobbyGM::StartGame()
{
	//Server, GameMode
	GetWorld()->ServerTravel("InGame");
}
