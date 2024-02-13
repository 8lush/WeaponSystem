// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicCharacterAttributeSet.h"
#include "Net/UnrealNetwork.h"

	void UBasicCharacterAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
    {
        GAMEPLAYATTRIBUTE_REPNOTIFY(UBasicCharacterAttributeSet, Health, OldHealth);
    }

	void UBasicCharacterAttributeSet::OnRep_HealthMax(const FGameplayAttributeData& OldHealthMax)	
    {
        GAMEPLAYATTRIBUTE_REPNOTIFY(UBasicCharacterAttributeSet, HealthMax, OldHealthMax);
    }

	void UBasicCharacterAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const 
    {
        Super::GetLifetimeReplicatedProps(OutLifetimeProps);

        DOREPLIFETIME_CONDITION_NOTIFY(UBasicCharacterAttributeSet, Health, COND_None, REPNOTIFY_Always);
        DOREPLIFETIME_CONDITION_NOTIFY(UBasicCharacterAttributeSet, HealthMax, COND_None, REPNOTIFY_Always);
    }