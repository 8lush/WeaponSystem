// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AbilitySystemComponent.h"
#include "GameplayAbilitySpec.h"
#include "AbilitySet.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EAbilityInput
{
	None = 0 UMETA(Hidden),
	Jump = 1,
	Primary = 2,
	Secondary = 3,
};

/**
 * 
 */
USTRUCT()
struct FAbilitySetItem
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "Ability")
	TSubclassOf<UGameplayAbility> GameplayAbility;

	UPROPERTY(EditDefaultsOnly, Category = "Ability")
	EAbilityInput InputKey;
};

/**
 * 
 */
UCLASS()
class WEAPONSYSTEM_API UAbilitySet : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "Ability")
	TArray<FAbilitySetItem> AbilitySetItems;

	TArray<FGameplayAbilitySpecHandle> GrantAbilitiesToAbilitySystem(UAbilitySystemComponent* AbilitySystemComponent) const;
};
