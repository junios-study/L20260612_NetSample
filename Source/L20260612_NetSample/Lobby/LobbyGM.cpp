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
				GS->LeftTime--; //function();
			}
		},
		1,
		true
	);
}

void ALobbyGM::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetWorld()->GetTimerManager().ClearTimer(LeftTimerHandle);

	Super::EndPlay(EndPlayReason);
}
