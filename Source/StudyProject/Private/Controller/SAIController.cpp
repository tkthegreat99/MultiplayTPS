// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/SAIController.h"
#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

const float ASAIController::PatrolRepeatInterval(3.f);
const float ASAIController::PatrolRadius(500.f);

ASAIController::ASAIController()
{

}

void ASAIController::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(PatrolTimerHandle, this, &ThisClass::OnPatrolTimerElapsed, PatrolRepeatInterval, true);
}

void ASAIController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetWorld()->GetTimerManager().ClearTimer(PatrolTimerHandle);

	Super::EndPlay(EndPlayReason);
}

void ASAIController::OnPatrolTimerElapsed()
{
	APawn* ControlledPawn = GetPawn();
	if (IsValid(ControlledPawn) == true)
	{
		UNavigationSystemV1* NavigationSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
		if (IsValid(NavigationSystem) == true)
		{
			FVector ActorLocation = ControlledPawn->GetActorLocation();
			FNavLocation NextLocation;
			if (NavigationSystem->GetRandomPointInNavigableRadius(ActorLocation, PatrolRadius, NextLocation) == true)
			{
				UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, NextLocation.Location);
			}
		}
	}
}
