// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/SCharacter.h"
#include "InputActionValue.h"
#include "SPlayerCharacter.generated.h"


class USpringArmComponent;
class UCameraComponent;
class USInputConfig;
class UInputMappingContext;
//class ASWeaponActor;
class UAnimMontage;
class UParticleSystemComponent;

UENUM(BlueprintType)
enum class EViewMode : uint8
{
	None,
	BackView,
	QuarterView,
	TPSView,
	End
};



/**
 * 
 */
UCLASS()
class STUDYPROJECT_API ASPlayerCharacter : public ASCharacter
{
	GENERATED_BODY()
	
public:

	UParticleSystemComponent* GetParticleSystem() const { return ParticleSystemComponent; }

	/*
	int32 GetMaxKillCount() const { return MaxKillCount; }

	void SetMaxKillCount(int32 InMaxKillCount) { MaxKillCount = InMaxKillCount; }

	int32 GetCurrentKillCount() const { return CurrentKillCount; }

	void AddCurrentKillCount(int32 InCurrentKillCount);
	*/

public:

	//static int32 ShowAttackDebug;

	ASPlayerCharacter();

	virtual void BeginPlay() override;

	virtual void PossessedBy(AController* NewController) override;

	virtual void Tick(float DeltaSeconds) override;

	void SetViewMode(EViewMode InViewMode);

	float GetForwardInputValue() const { return ForwardInputValue; }

	float GetRightInputValue() const { return RightInputValue; }

	//UFUNCTION()
	//void OnMeleeAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	//UFUNCTION()
	//void OnCheckHit();

	//virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;


protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
private:
	void InputMove(const FInputActionValue& InValue);
	void InputLook(const FInputActionValue& InValue);
	void InputChangeView(const FInputActionValue& InValue);
	void InputQuickSlot01(const FInputActionValue& InValue);
	void InputQuickSlot02(const FInputActionValue& InValue);
	void InputAttack(const FInputActionValue& InValue);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	TObjectPtr<USpringArmComponent> SpringArmComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	TObjectPtr<UCameraComponent> CameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	TObjectPtr<USInputConfig> PlayerCharacterInputConfig;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	TObjectPtr<UInputMappingContext> PlayerCharacterInputMappingContext;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	float ForwardInputValue;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Meta = (AllowPrivateAccess))
	float RightInputValue;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	//TSubclassOf<ASWeaponActor> WeaponClass;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	//TObjectPtr<ASWeaponActor> WeaponInstance;

protected:

	EViewMode CurrentViewMode = EViewMode::None;

	FVector DirectionToMove = FVector::ZeroVector;

	float DestArmLength = 0.f;

	float ArmLengthChangeSpeed = 3.f;

	FRotator DestArmRotation = FRotator::ZeroRotator;

	float ArmRotationChangeSpeed = 10.f;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Meta = (AllowPrivateAccess))
	//float MeleeAttackRange = 50.f;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Meta = (AllowPrivateAccess))
	//float MeleeAttackRadius = 20.f;
private:

	//void BeginCombo();

	//UFUNCTION()
	//void OnCheckAttackInput();

	//UFUNCTION()
	//void EndCombo(UAnimMontage* InMontage, bool bInterruped);

private:

	//bool bIsNowAttacking = false;

	//FString AttackAnimMontageSectionName = FString(TEXT("Attack"));

	//int32 MaxComboCount = 3;

	//int32 CurrentComboCount = 0;

	//bool bIsAttackKeyPressed = false;

	//FOnMontageEnded OnMeleeAttackMontageEndedDelegate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Meta = (AllowPrivateAccess))
	TObjectPtr<UParticleSystemComponent> ParticleSystemComponent;

	/*

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Meta = (AllowPrivateAccess = true))
	int32 CurrentKillCount = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Meta = (AllowPrivateAccess = true))
	int32 MaxKillCount = 99;

	*/
};
