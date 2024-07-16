// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/SAnimInstance.h"
#include "Character/SPlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

USAnimInstance::USAnimInstance()
{

}

void USAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	ASCharacter* OwnerCharacter = Cast<ASCharacter>(TryGetPawnOwner());
	if (IsValid(OwnerCharacter) == true)
	{
		UCharacterMovementComponent* CharacterMovementComponent = OwnerCharacter->GetCharacterMovement();
		if (IsValid(CharacterMovementComponent) == true)
		{
			CurrentSpeed = CharacterMovementComponent->GetLastUpdateVelocity().Size();
		}
	}
}