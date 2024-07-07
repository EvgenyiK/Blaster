// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterPlayerController.h"
#include "Blaster/HUD/BlasterHUD.h"
#include "Blaster/HUD/CharacterOverlay.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"


void ABlasterPlayerController::BeginPlay()
{
	Super::BeginPlay();
	BlasterHud = Cast<ABlasterHUD>(GetHUD());
}

void ABlasterPlayerController::SetHUDHealth(float Health, float MaxHealth)
{
	BlasterHud = BlasterHud == nullptr ? Cast<ABlasterHUD>(GetHUD()) : BlasterHud;

	bool bHUDValid = BlasterHud &&
		BlasterHud->CharacterOverlay &&
		BlasterHud->CharacterOverlay->HealthBar &&
		BlasterHud->CharacterOverlay->HealthText;
	if (bHUDValid)
	{
		const float HealthPercent = Health / MaxHealth;
		BlasterHud->CharacterOverlay->HealthBar->SetPercent(HealthPercent);
		FString HeathText = FString::Printf(TEXT("%d/%d"), FMath::CeilToInt(Health), FMath::CeilToInt(MaxHealth));
		BlasterHud->CharacterOverlay->HealthText->SetText(FText::FromString(HeathText));
	}
}
