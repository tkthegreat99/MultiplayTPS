// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/SPlayerState.h"
#include "Character/SPlayerCharacter.h"
#include "Particles/ParticleSystemComponent.h"

ASPlayerState::ASPlayerState()
{

}

void ASPlayerState::InitPlayerState()
{
	SetPlayerName(TEXT("Player"));

	CurrentKillCount = 0;
	MaxKillCount = 99;
}

void ASPlayerState::AddCurrentKillCount(int32 InCurrentKillCount)
{
	OnCurrentKillCountChangedDelegate.Broadcast(CurrentKillCount, CurrentKillCount + InCurrentKillCount);

	CurrentKillCount = FMath::Clamp(CurrentKillCount + InCurrentKillCount, 0, MaxKillCount);

	ASPlayerCharacter* PlayerCharacter = Cast<ASPlayerCharacter>(GetPawn());
	checkf(IsValid(PlayerCharacter) == true, TEXT("Invalid PlayerCharacter"));
	PlayerCharacter->GetParticleSystem()->Activate(true);
}
