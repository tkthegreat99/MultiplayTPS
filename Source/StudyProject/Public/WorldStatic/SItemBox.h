// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SItemBox.generated.h"

UCLASS()
class STUDYPROJECT_API ASItemBox : public AActor
{
	GENERATED_BODY()
	
public:	
	ASItemBox();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
