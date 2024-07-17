// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/HitInterface.h"
#include "BrekableActor.generated.h"

class UGeometryCollectionComponent;

UCLASS()
class PROJECTX_API ABrekableActor : public AActor, public IHitInterface
{
	GENERATED_BODY()
	
public:	
	ABrekableActor();
	virtual void Tick(float DeltaTime) override;

	virtual void GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter) override;
protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UGeometryCollectionComponent* GeometryCollection;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UCapsuleComponent* Capsule;
private:	
	bool bBroken = false;
	UPROPERTY(EditAnywhere, Category = "Brekable Properties")
	TArray<TSubclassOf<class ATresure>> TreasureClasses;
};
