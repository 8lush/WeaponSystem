// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponSystemAssetManager.h"
#include "AbilitySystemGlobals.h"

void UWeaponSystemAssetManager::StartInitialLoading()
{
    Super::StartInitialLoading();
    UAbilitySystemGlobals::Get().InitGlobalData();
    UE_LOG(LogTemp, Warning, TEXT("Asset Manager Initialized..."));
}