// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "Tresure.generated.h"


/**
 * 
 */
UCLASS()
class PROJECTX_API ATresure : public AItem
{
	GENERATED_BODY()
protected:
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	

private:
	UPROPERTY(EditAnywhere, Category = "Treasure Propeties")
	int32 Gold;

public:
	FORCEINLINE int32 GetGold() const { return Gold; }
};