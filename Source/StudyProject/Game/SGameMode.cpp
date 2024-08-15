// Fill out your copyright notice in the Description page of Project Settings.


#include "SGameMode.h"
#include "Controller/MyPlayerController.h"
#include "Character/SPawn.h"
#include "Game/SPlayerState.h"

ASGameMode::ASGameMode()
{
	PlayerControllerClass = AMyPlayerController::StaticClass();
	DefaultPawnClass = ASPawn::StaticClass();
}

void ASGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	ASPlayerState* PlayerState = NewPlayer->GetPlayerState<ASPlayerState>();
	if (true == ::IsValid(PlayerState))
	{
		PlayerState->InitPlayerState();
	}
}
