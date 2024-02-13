// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicCharacterAttributeSet.h"
#include "GameplayEffectExtension.h"
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

    void UBasicCharacterAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
    {
        Super::PreAttributeChange(Attribute, NewValue);

        if(Attribute == GetHealthAttribute())
        {
            NewValue = FMath::Clamp(NewValue, 0.f, GetHealthMax());
        }
    }

    void UBasicCharacterAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
    {
        Super::PostGameplayEffectExecute(Data);

        if(Data.EvaluatedData.Attribute == GetDamageAttribute())
        {
            //Store a local copy of the amount of damage done and clear the damage attribute
            const float LocalDamageDone = GetDamage();
            SetDamage(0.f);

            if(LocalDamageDone > 0.0f)
            {
                //Apply the health change and then clamp it
                const float NewHealth = GetHealth() - LocalDamageDone;
                SetHealth(FMath::Clamp(NewHealth, 0.0f, GetHealthMax()));
            }
        }
    }