// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"


UCLASS()
class WEAPONSYSTEM_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	// The create blueprint function was made based on a youtube video by Alex Quevillion. https://www.youtube.com/watch?v=eEy2v95pDWw
	UFUNCTION(BlueprintCallable, Category = "Create Asset")
	static UBlueprint* CreateBlueprint(FString BlueprintPath, TSubclassOf<UObject> ParentClass, bool& bOutSuccess, FString& OutInfoMessage);

	// Changes a named property value within a blueprint to the given UObject
	UFUNCTION(BlueprintCallable, Category = "Create Asset")
	static void ChangeProperty(UBlueprint* Blueprint, const FName& PropertyName, UObject* NewValue, bool& bOutSuccess, FString& OutInfoMessage);

};
