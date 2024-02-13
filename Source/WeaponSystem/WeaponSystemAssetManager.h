// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "WeaponSystemAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class WEAPONSYSTEM_API UWeaponSystemAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	virtual void StartInitialLoading() override;

};
