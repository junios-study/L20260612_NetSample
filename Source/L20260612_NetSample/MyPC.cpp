// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPC.h"
#include "Kismet/KismetSystemLibrary.h"

AMyPC::AMyPC()
{
}

void AMyPC::OnPossess(APawn* aPawn)
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Begin AMyPC::OnPossess"));

	Super::OnPossess(aPawn);

	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("End AMyPC::OnPossess"));
}

void AMyPC::BeginPlay()
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Begin AMyPC::BeginPlay"));

	Super::BeginPlay();

	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("End AMyPC::BeginPlay"));

	FString LocalRoleString = StaticEnum<ENetRole>()->GetDisplayNameTextByValue((int64)GetLocalRole()).ToString();
	FString RemoteRoleString = StaticEnum<ENetRole>()->GetDisplayNameTextByValue((int64)GetRemoteRole()).ToString();


	FString Message = FString::Printf(TEXT("LocalRole : %s, RemoteRole : %s"), *LocalRoleString, *RemoteRoleString);
	UKismetSystemLibrary::PrintString(GetWorld(), Message);

}
