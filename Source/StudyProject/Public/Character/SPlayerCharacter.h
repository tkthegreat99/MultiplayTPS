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
class UAnimMontage;
class UParticleSystemComponent;
struct FStreamableHandle;

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

public:

	ASPlayerCharacter();

	virtual void BeginPlay() override;

	virtual void PossessedBy(AController* NewController) override;

	virtual void Tick(float DeltaSeconds) override;

	void SetViewMode(EViewMode InViewMode);

	float GetForwardInputValue() const { return ForwardInputValue; }

	float GetRightInputValue() const { return RightInputValue; }

	float GetCurrentAimPitch() const { return CurrentAimPitch; }

	float GetCurrentAimYaw() const { return CurrentAimYaw; }

	bool GetCurrentWeaponState() const { return bHasWeapon;  }

protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
private:
	void InputMove(const FInputActionValue& InValue);
	void InputLook(const FInputActionValue& InValue);
	void InputChangeView(const FInputActionValue& InValue);
	void InputQuickSlot01(const FInputActionValue& InValue);
	void InputQuickSlot02(const FInputActionValue& InValue);
	void InputAttack(const FInputActionValue& InValue);
	void InputMenu(const FInputActionValue& InValue);
	void StartIronSight(const FInputActionValue& InValue);
	void EndIronSight(const FInputActionValue& InValue);
	void ToggleTrigger(const FInputActionValue& InValue);
	void StartFire(const FInputActionValue& InValue);
	void StopFire(const FInputActionValue& InValue);


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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = ASPlayerCharacter, Meta = (AllowPrivateAccess = true))
	TSubclassOf<UCameraShakeBase> FireShake;

protected:

	EViewMode CurrentViewMode = EViewMode::None;

	FVector DirectionToMove = FVector::ZeroVector;

	float DestArmLength = 0.f;

	float ArmLengthChangeSpeed = 3.f;

	FRotator DestArmRotation = FRotator::ZeroRotator;

	float ArmRotationChangeSpeed = 10.f;

	FSoftObjectPath CurrentPlayerCharacterMeshMaterialPath = FSoftObjectPath();

	TSharedPtr<FStreamableHandle> AssetStreamableHandle = nullptr;

	float TargetFOV = 70.f;

	float CurrentFOV = 70.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Meta = (AllowPrivateAccess))
	float FirePerMinute = 1200;

	bool bIsTriggerToggle = false;

	FTimerHandle BetweenShotsTimer;

	float TimeBetweenFire;

	float CurrentAimPitch = 0.f;

	float CurrentAimYaw = 0.f;

	bool bHasWeapon = false;

private:
	void TryFire();

	


private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Meta = (AllowPrivateAccess))
	TObjectPtr<UParticleSystemComponent> ParticleSystemComponent;

	

};
