// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MyDataAsset.generated.h"

/**
 * 
 */
USTRUCT()
struct FMyAssetInfo {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere)
    FString AssetName;

    UPROPERTY(EditAnywhere)
    UTexture2D* AssetThumbnail;

    UPROPERTY(EditAnywhere)
    UStaticMesh* AssetStaticMesh; 
};

/**
 * 
 */
UCLASS()
class WEAPONSYSTEM_API UMyDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
    TArray<FMyAssetInfo> AssetItems;
};
