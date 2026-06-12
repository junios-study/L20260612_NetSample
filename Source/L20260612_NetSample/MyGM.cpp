// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGM.h"
#include "MyPC.h"
#include "Kismet/KismetSystemLibrary.h"
#include "MyPlayer.h"
#include "MyHUD.h"

AMyGM::AMyGM()
{
	PlayerControllerClass = AMyPC::StaticClass();
	DefaultPawnClass = AMyPlayer::StaticClass();
	HUDClass = AMyHUD::StaticClass();
}

void AMyGM::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Begin AMyGM::PreLogin"));

	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);

	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("End AMyGM::PreLogin"));
	
}

APlayerController* AMyGM::Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Begin AMyGM::Login"));

	APlayerController* PC = Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage);

	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("End AMyGM::Login"));

	return PC;
}

void AMyGM::PostLogin(APlayerController* NewPlayer)
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Begin AMyGM::PostLogin"));

	Super::PostLogin(NewPlayer);

	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("End AMyGM::PostLogin"));
}

void AMyGM::StartPlay()
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Begin AMyGM::StartPlay"));

	Super::StartPlay();

	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("End AMyGM::StartPlay"));
}

void AMyGM::BeginPlay()
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Begin AMyGM::BeginPlay"));

	Super::BeginPlay();

	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("End AMyGM::BeginPlay"));
}
