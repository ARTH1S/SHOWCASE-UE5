// Fill out your copyright notice in the Description page of Project Settings.


#include "Breakable/BrekableActor.h"
#include "GeometryCollection/GeometryCollectionComponent.h"
#include "Items/Tresure.h"
#include "Components/CapsuleComponent.h"

ABrekableActor::ABrekableActor()
{
	PrimaryActorTick.bCanEverTick = false;

	GeometryCollection = CreateDefaultSubobject <UGeometryCollectionComponent>(TEXT("GeometryCollection"));
	SetRootComponent(GeometryCollection);
	GeometryCollection->SetGenerateOverlapEvents(true);
	GeometryCollection->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore); 
	GeometryCollection->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore); 

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetupAttachment(GetRootComponent());
	Capsule->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore); 
	Capsule->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block); 
}

void ABrekableActor::BeginPlay()
{
	Super::BeginPlay();
}

void ABrekableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABrekableActor::GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter)
{
	if (bBroken) return;
	bBroken = true;
	UWorld* World = GetWorld();


	if (World && TreasureClasses.Num() > 0) // TreasureClasses.Num() - how elements in array
	{
		FVector Location = GetActorLocation();
		Location.Z += 75.f;

		const int32 Selection = FMath::RandRange(0, TreasureClasses.Num() - 1);

		World->SpawnActor<ATresure>(TreasureClasses[Selection], Location, GetActorRotation()); 
		
	}
}

