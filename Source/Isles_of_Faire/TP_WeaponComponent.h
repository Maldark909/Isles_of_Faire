// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture2D.h"
#include "Components/StaticMeshComponent.h"
#include "TP_WeaponComponent.generated.h"

class AIsles_of_FaireCharacter;

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ISLES_OF_FAIRE_API UTP_WeaponComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	//Fuck, we're gonna have a hard ass time with animating.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=WeaponVisuals)
	UTexture2D *WeaponIdleTexture;
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=WeaponVisuals)
	UTexture2DArray *WeaponShootAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=WeaponVisuals)
	UTexture2DArray *WeaponReloadAnimation;

	/** Projectile class to spawn */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Projectile)
	TSubclassOf<class AIsles_of_FaireProjectile> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	USoundBase* FireSound;
	
	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UAnimMontage* FireAnimation;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	FVector MuzzleOffset;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputMappingContext* FireMappingContext;

	/** Fire Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* FireAction;

	/** Sets default values for this component's properties */
	UTP_WeaponComponent();

	/** Attaches the actor to a FirstPersonCharacter */
	UFUNCTION(BlueprintCallable, Category="Weapon")
	void AttachWeapon(AIsles_of_FaireCharacter* TargetCharacter);

	/** Make the weapon Fire a Projectile */
	UFUNCTION(BlueprintCallable, Category="Weapon")
	void Fire();

protected:
	/** Ends gameplay for this component. */
	UFUNCTION()
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	/** The Character holding this weapon*/
	AIsles_of_FaireCharacter* Character;
};
