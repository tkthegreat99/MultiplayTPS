// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SWeaponActor.generated.h"

class UAnimMontage;

UCLASS()
class STUDYPROJECT_API ASWeaponActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ASWeaponActor();

	USkeletalMeshComponent* GetMesh() const { return Mesh; }

	UAnimMontage* GetMeleeAttackMontage() const { return MeleeAttackMontage; }
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	TObjectPtr<USkeletalMeshComponent> Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess))
	TObjectPtr<UAnimMontage> MeleeAttackMontage;
};
