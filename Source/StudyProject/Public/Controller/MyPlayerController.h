// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

class USHUD;
/**
 * 
 */
UCLASS()
class STUDYPROJECT_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
		USHUD* GetHUDWidget() const { return HUDWidget; };

		virtual void BeginPlay() override;

		void ToggleInGameMenu();


private:
	UPROPERTY();
	TObjectPtr<USHUD> HUDWidget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess));
	TSubclassOf<USHUD> HUDWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ASPlayerController, Meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> InGameMenuClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = ASPlayerController, Meta = (AllowPrivateAccess))
	TObjectPtr<UUserWidget> InGameMenuInstance;

	bool bIsInGameMenuOn = false;
};
