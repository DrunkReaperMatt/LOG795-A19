// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableActor.h"
#include <Engine/Engine.h>
#include <Kismet/KismetMathLibrary.h>
#include <Kismet/GameplayStatics.h>
#include "RosettaCharacter.h"
#include "InteractionIcon.h"

// Sets default values
AInteractableActor::AInteractableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AInteractableActor::BeginPlay()
{
	Super::BeginPlay();
	UWidgetComponent* FoundUIComp = AInteractableActor::GetInteractionIcon();
	if (FoundUIComp)
	{
		InteractionIcon = FoundUIComp;
		Cast<UInteractionIcon>(GetInteractionIcon()->GetUserWidgetObject())->SetInteractionDescription(GetActionDescription());
	}
	else
	{
		FString ErrorMessage = "Interactable " + GetName() + " has no InteractionIcon!";
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, ErrorMessage);
	}
	Player = Cast<ARosettaCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!Player)
	{
		FString ErrorMessage = "Interactable " + GetName() + " has no Player!";
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, ErrorMessage);
	}
}

// Called every frame
void AInteractableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (InteractionIcon && InteractionIcon->IsVisible())
	{
		AInteractableActor::UpdateInteractionIconToFaceCam();
	}
}

void AInteractableActor::SetInteractionIconVisibility(bool bIsVisible) const
{
	if (InteractionIcon)
	{
		InteractionIcon->SetVisibility(bIsVisible);
	}
}

void AInteractableActor::UpdateInteractionIconToFaceCam() const
{
	APlayerCameraManager* CamManager = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;

	FVector CamLocation = CamManager->GetCameraLocation();
	if (InteractionIcon)
	{
		FVector IconLocation = InteractionIcon->GetComponentLocation();
		FRotator IconRotation = UKismetMathLibrary::FindLookAtRotation(IconLocation, CamLocation);
		InteractionIcon->SetWorldRotation(IconRotation);
	}
}

UWidgetComponent* AInteractableActor::GetInteractionIcon() const
{
	TArray<UWidgetComponent*> UIComps;

	GetComponents<UWidgetComponent>(UIComps);
	if (UIComps.Num() > 0)
	{
		return UIComps[0];
	}
	return nullptr;
}

