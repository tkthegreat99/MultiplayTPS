// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/UW_LobbyLayout.h"
#include "SPlayerCharacterSettings.h"
#include "GameFramework/Character.h"
#include "Components/Button.h"
#include "Components/EditableText.h"
#include "Engine/AssetManager.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/StreamableManager.h"

void UUW_LobbyLayout::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    ACharacter* Character = Cast<ACharacter>(GetOwningPlayerPawn());
    CurrentSkeletalMeshComponent = Character->GetMesh();

    BlackTeamButton.Get()->OnClicked.AddDynamic(this, &ThisClass::OnBlackTeamButtonClicked);
    WhiteTeamButton.Get()->OnClicked.AddDynamic(this, &ThisClass::OnWhiteTeamButtonClicked);
    SubmitButton.Get()->OnClicked.AddDynamic(this, &ThisClass::OnSubmitButtonClicked);

    const USPlayerCharacterSettings* CharacterSettings = GetDefault<USPlayerCharacterSettings>();
    if (IsValid(CharacterSettings) == true)
    {

        
        for (auto Path : CharacterSettings->PlayerCharacterMeshMaterialPaths)
        {
            StreamableHandles.Emplace(UAssetManager::GetStreamableManager().RequestAsyncLoad
            (
                Path,
                FStreamableDelegate::CreateLambda([this, Path]() -> void
            {
                TSoftObjectPtr<UMaterial> LoadedMaterialInstanceAsset(Path);
                LoadedMaterialInstanceAssets.Emplace(LoadedMaterialInstanceAsset);
            })
            )
            );
        }
        
    }
}

void UUW_LobbyLayout::NativeDestruct()
{
    for (auto Handle : StreamableHandles)
    {
        if (Handle.IsValid() == true)
        {
            Handle->ReleaseHandle();
        }
    }

    Super::NativeDestruct();
}

void UUW_LobbyLayout::OnBlackTeamButtonClicked()
{
    CurrentSkeletalMeshComponent->SetMaterial(0, LoadedMaterialInstanceAssets[0].Get());
}

void UUW_LobbyLayout::OnWhiteTeamButtonClicked()
{
    CurrentSkeletalMeshComponent->SetMaterial(0, LoadedMaterialInstanceAssets[1].Get());
}

void UUW_LobbyLayout::OnSubmitButtonClicked()
{
    FString PlayerName = EditPlayerName->GetText().ToString();
    if (PlayerName.Len() <= 0 || 10 <= PlayerName.Len())
    {
        return;
    }

    UGameplayStatics::OpenLevel(GetWorld(), TEXT("Loading"), true, FString(TEXT("NextLevel=Example")));
}
