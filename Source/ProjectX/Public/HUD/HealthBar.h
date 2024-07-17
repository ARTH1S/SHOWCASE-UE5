// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBar.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTX_API UHealthBar : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// cpp variable will be link with BP variable. name has to match!
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* HealthBar;
};
