// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "CharacterAbilitySystemComponent.generated.h"

//DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FReceiveDamageDelegate, UCharacterAbilitySystemComponent*, SourceASC, float, UnmitigatedDamage, float, MitigatedDamage);

/**
 * 
 */
UCLASS()
class WEAPONSYSTEM_API UCharacterAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	//bool CharacterAbilitiesGiven = false;
	//bool StartupEffectsApplied = false;

	//FReceiveDamageDelegate ReceiveDamage;

	//virtual void ReceiveDamage (UCharacterAbilitySystemComponent* SourceASC, float UnmitigatedDamage, float MitigatedDamage);
};
