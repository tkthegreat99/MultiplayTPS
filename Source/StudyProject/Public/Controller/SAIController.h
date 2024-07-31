// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SAIController.generated.h"

/**
 * 
 */
UCLASS()
class STUDYPROJECT_API ASAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ASAIController();

protected:
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	void OnPatrolTimerElapsed();

public:
	FTimerHandle PatrolTimerHandle = FTimerHandle();

	static const float PatrolRepeatInterval;

	static const float PatrolRadius;

};
