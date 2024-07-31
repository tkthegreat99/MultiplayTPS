// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/SNonPlayerCharacter.h"
#include "Controller/SAIController.h"
#include "GameFramework/CharacterMovementComponent.h"

ASNonPlayerCharacter::ASNonPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	AIControllerClass = ASAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	GetCharacterMovement()->MaxWalkSpeed = 300.f;
}
