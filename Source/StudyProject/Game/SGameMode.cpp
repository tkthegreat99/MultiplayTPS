// Fill out your copyright notice in the Description page of Project Settings.


#include "SGameMode.h"
#include "Controller/MyPlayerController.h"
#include "Character/SPawn.h"

ASGameMode::ASGameMode()
{
	PlayerControllerClass = AMyPlayerController::StaticClass();
	DefaultPawnClass = ASPawn::StaticClass();
}
