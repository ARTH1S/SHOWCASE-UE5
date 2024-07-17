// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SlashOverlay.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTX_API USlashOverlay : public UUserWidget
{
	GENERATED_BODY()
	
public:

	void SetHealthBarPercent(float Percent);
	void SetStaminaBarPercent(float Percent);
	void SetGold(int32 Gold);
	void SetSouls(int32 Souls);

private:

	UPROPERTY(meta = (BindWidged)) // link to widget in UE, need the same name
	class UProgressBar* HealthProgressBar;

	UPROPERTY(meta = (BindWidged))
	class UProgressBar* StaminaProgressBar;

	UPROPERTY(meta = (BindWidged))
	class UTextBlock* GoldText;

	UPROPERTY(meta = (BindWidged))
	class UTextBlock* SoulsText;
};
