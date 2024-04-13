// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"

//#include "Engine.h"
#include "AssetRegistry/AssetRegistryModule.h" // Asset Registry
#include "Kismet2/KismetEditorUtilities.h" // UnrealEd (Editor Only)
#include "KismetCompilerModule.h" // KismetCompiler (Editor Only)


UBlueprint* UMyBlueprintFunctionLibrary::CreateBlueprint(FString BlueprintPath, TSubclassOf<UObject> ParentClass, bool& bOutSuccess, FString& OutInfoMessage)
{
    // Make sure an asset doesn't already exist with that path
    if (StaticLoadObject(UObject::StaticClass(), nullptr, *BlueprintPath) != nullptr)
    {
        bOutSuccess = false;
        OutInfoMessage = FString::Printf(TEXT("Create Blueprint Failed - An asset already exists at that location. '%s'"), *BlueprintPath);
        return nullptr;
    }

    // Make sure the parent class is valid
    if (!FKismetEditorUtilities::CanCreateBlueprintOfClass(ParentClass))
    {
        bOutSuccess = false;
        OutInfoMessage = FString::Printf(TEXT("Create Blueprint Failed - Parent class is not blueprintable. '%s'"), *BlueprintPath);
        return nullptr;
    }

    // Create asset package
    UPackage* Package = CreatePackage(*BlueprintPath);
    if (Package == nullptr)
    {
        bOutSuccess = false;
        OutInfoMessage = FString::Printf(TEXT("Create Blueprint Failed - Failed to create the asset package. Make sure the path is valid. '%s'"), *BlueprintPath);
        return nullptr;
    }

    // Find the blueprint classes to create
    UClass* BpClass = nullptr;
    UClass* BpGenClass = nullptr;
    FModuleManager::LoadModuleChecked<IKismetCompilerInterface>("KismetCompiler").GetBlueprintTypesForClass(ParentClass, BpClass, BpGenClass);

    // Create asset
    UBlueprint* Blueprint = FKismetEditorUtilities::CreateBlueprint(ParentClass, Package, *FPaths::GetBaseFilename(BlueprintPath), BPTYPE_Normal, BpClass, BpGenClass);

    // Register asset
    FAssetRegistryModule::AssetCreated(Blueprint);
    Blueprint->MarkPackageDirty();

    // Return the asset
    bOutSuccess = true;
    OutInfoMessage = FString::Printf(TEXT("Create Blueprint Succeeded - '%s'"), *BlueprintPath);
    return Blueprint;
}

void UMyBlueprintFunctionLibrary::ChangeProperty(UBlueprint* Blueprint, const FName& PropertyName, UObject* NewValue, bool& bOutSuccess, FString& OutInfoMessage)
{
    UClass* Class = Blueprint->GetClass();
    FObjectProperty* Property = nullptr;   
    TSubclassOf<UObject> GeneratedClassObject = nullptr;

    FString PropertyValue = "null";

    bOutSuccess = false;
    OutInfoMessage = FString::Printf(TEXT("ERROR: Casting to Object Class failed."));

    if (Class)
    {
        GeneratedClassObject = Blueprint->GeneratedClass;
        FString ClassName = GeneratedClassObject->GetClass()->GetName();

        Property = CastField<FObjectProperty>(GeneratedClassObject->FindPropertyByName(PropertyName));

        bOutSuccess = false;
        OutInfoMessage = FString::Printf(TEXT("ERROR: Creating Property failed. '%s'"), *ClassName);
    }

	if (Property)
	{
        UObject* DefaultObject = GeneratedClassObject->GetDefaultObject();

        PropertyValue = DefaultObject->GetName();

        // Crashed unreal when I ran this
        //PropertyValue = FStrProperty::GetPropertyValue(Property->ContainerPtrToValuePtr<void>(DefaultObject));

        // This also crashed unreal
        //void *ValueAddress = Property->ContainerPtrToValuePtr<void>(DefaultObject);
        //PropertyValue = Property->GetPropertyValue(ValueAddress);

        bOutSuccess = false;
        OutInfoMessage = FString::Printf(TEXT("ERROR: Creating DefaultObject failed."));

        if (DefaultObject)
        {
            Property->SetPropertyValue_InContainer(DefaultObject, NewValue);

            bOutSuccess = true;
            OutInfoMessage = FString::Printf(TEXT("Changing Property succeeded. '%s'"), *PropertyValue);
        }  
	}
}
