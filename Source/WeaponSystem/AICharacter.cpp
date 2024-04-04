// Fill out your copyright notice in the Description page of Project Settings.


#include "AICharacter.h"
#include "AbilitySystemComponent.h"
#include "BasicCharacterAttributeSet.h"

// Sets default values
AAICharacter::AAICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

// Called when the game starts or when spawned
void AAICharacter::BeginPlay()
{
	Super::BeginPlay();
	
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, TEXT("Attempting to assign BasicAttributeSet!"));
	if(IsValid(AbilitySystemComponent))
	{
		BasicAttributeSet = AbilitySystemComponent->GetSet<UBasicCharacterAttributeSet>();

		if(IsValid(BasicAttributeSet))
		{
			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, TEXT("Successfully assgined BasicAttributeSet!"));
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("Failed to assgined BasicAttributeSet!"));
		}

	}
}

// Called every frame
void AAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

