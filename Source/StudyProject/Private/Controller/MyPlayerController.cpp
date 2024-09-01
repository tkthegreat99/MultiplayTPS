// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/MyPlayerController.h"
#include "UI/SHUD.h"
#include "Game/SPlayerState.h"
#include "Component/SStatComponent.h"
#include "Character/SCharacter.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/UserWidget.h"
#include "Character/SPlayerCharacter.h"

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

    FInputModeGameOnly InputModeGameOnly;
    SetInputMode(InputModeGameOnly);

       
    if (HasAuthority() == true)
    {
        return;
    }
    

    if (IsValid(HUDWidgetClass) == true)
    {
        HUDWidget = CreateWidget<USHUD>(this, HUDWidgetClass);
        if (IsValid(HUDWidget) == true)
        {
            HUDWidget->AddToViewport();

            ASPlayerState* SPlayerState = GetPlayerState<ASPlayerState>();
            if (IsValid(SPlayerState) == true)
            {
                HUDWidget->BindPlayerState(SPlayerState);
            }

            ASCharacter* PC = GetPawn<ASCharacter>();
            if (IsValid(PC) == true)
            {
                USStatComponent* StatComponent = PC->GetStatComponent();
                if (IsValid(StatComponent) == true)
                {
                    HUDWidget->BindStatComponent(StatComponent);
                }
            }
        }
    }

    if (IsValid(InGameMenuClass) == true)
    {
        InGameMenuInstance = CreateWidget<UUserWidget>(this, InGameMenuClass);
        if (IsValid(InGameMenuInstance) == true)
        {
            InGameMenuInstance->AddToViewport(3); // »óÀ§¿¡ ¶ç¿ò.

            InGameMenuInstance->SetVisibility(ESlateVisibility::Collapsed);
        }
    }

    if (IsValid(CrosshairUIClass) == true)
    {
        UUserWidget* CrosshairUIInstance = CreateWidget<UUserWidget>(this, CrosshairUIClass);
        if (IsValid(CrosshairUIInstance) == true)
        {
            CrosshairUIInstance->AddToViewport(1);

            CrosshairUIInstance->SetVisibility(ESlateVisibility::Visible);
        }
    }
}

void AMyPlayerController::ToggleInGameMenu()
{
    checkf(IsValid(InGameMenuInstance) == true, TEXT("Invalid InGameMenuInstance"));

    if (false == bIsInGameMenuOn)
    {
        InGameMenuInstance->SetVisibility(ESlateVisibility::Visible);

        FInputModeUIOnly Mode;
        SetInputMode(Mode);
        Mode.SetWidgetToFocus(InGameMenuInstance->GetCachedWidget());
      
        SetPause(true); 
     
        bShowMouseCursor = true;
    }
    else
    {
        InGameMenuInstance->SetVisibility(ESlateVisibility::Collapsed);

        FInputModeGameOnly InputModeGameOnly;
        SetInputMode(InputModeGameOnly);

        SetPause(false);
        bShowMouseCursor = false;
    }

    bIsInGameMenuOn = !bIsInGameMenuOn;
}
