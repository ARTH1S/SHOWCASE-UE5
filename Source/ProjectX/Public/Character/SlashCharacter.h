// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "CharacterTypes.h"
#include "Interfaces/PickupInterface.h"
#include "SlashCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class AItem;
class UAnimMontage;
class USlashOverlay;
class ASoul;
class ATresure;

UCLASS()
class PROJECTX_API ASlashCharacter : public ABaseCharacter, public IPickupInterface
{
	GENERATED_BODY()

public:
	ASlashCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void  Jump() override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	virtual void GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter) override;
	virtual void SetOverlappingItem(class AItem* Item) override;
	virtual void AddSouls(ASoul* Soul) override;
	virtual void AddGold(ATresure* Treasure) override;

protected:
	virtual void BeginPlay() override;

	/* Callbacks for input */
	void MoveForward(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void MoveSide(float Value);
	void EKeyPressed();
	virtual void Attack() override;
	void Dodge();



	/* Combat */
	void EquipWeapon(AWeapon* Weapon);
	virtual void AttackEnd() override;
	virtual void DodgeEnd() override;
	virtual bool CanAttack() override;
	void PlayEquipMontage(const FName& SectionName);
	bool CanDisarm();
	bool CanArm();
	void Disarm();
	void Arm();
	virtual void Die() override;
	bool HasEnoughStamina();
	bool IsOccupied();

	UFUNCTION(BlueprintCallable)
	void AttachWeaponToBack();

	UFUNCTION(BlueprintCallable)
	void AttachWeaponToHand();

	UFUNCTION(BlueprintCallable)
	void FinishEquipping();

	UFUNCTION(BlueprintCallable)
	void HitReactEnd();

private:
	/* Character components */
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;

	UPROPERTY(VisibleInstanceOnly)
	AItem* OverlappingItem;

	UPROPERTY(EditDefaultsOnly, Category = Montages)
	UAnimMontage* EquipMontage;

	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	EActionState ActionState = EActionState::EAS_Unoccupied;

	UPROPERTY()
	USlashOverlay* SlashOverlay;

	void InitializeSlashOverlay();
	void SetHUDHealth();
	bool IsUnoccupied();

public:

	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }
	FORCEINLINE EActionState GetActionState() const { return ActionState; }
};
