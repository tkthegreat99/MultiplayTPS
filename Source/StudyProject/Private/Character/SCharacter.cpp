// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/SCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ASCharacter::ASCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	float CharacterHalfHeight = 95.f;
	float CharacterRadius = 20.f;

	GetCapsuleComponent()->InitCapsuleSize(CharacterRadius, CharacterHalfHeight);
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("SCharacter"));

	FVector PivotPosition(0.f, 0.f, -CharacterHalfHeight);
	FRotator PivotRotatioin(0.f, -90.f, 0.f);
	GetMesh()->SetRelativeLocationAndRotation(PivotPosition, PivotRotatioin);

	GetCharacterMovement()->MaxWalkSpeed = 350.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

}

