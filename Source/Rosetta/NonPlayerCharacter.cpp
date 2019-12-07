// Fill out your copyright notice in the Description page of Project Settings.


#include "NonPlayerCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "DialogueWidget.h"
#include "RosettaCharacter.h"
#include <stdio.h>
#include "DlgManager.h"

ANonPlayerCharacter::ANonPlayerCharacter()
{
	ConstructorHelpers::FClassFinder<UUserWidget> DWClassFinder(TEXT("/Game/UI/DialogueWidget"));
	DWClass = DWClassFinder.Class;
}

void ANonPlayerCharacter::Interact() {
	UE_LOG(LogTemp, Warning, TEXT("Intreact with %s"), *GetParticipantName_Implementation().ToString());
	player = Cast<ARosettaCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());

	player->StartDialogue(dialogueData, this);

	if (!ensure(DWClass != nullptr)) return;

	UDialogueWidget* DialogueWidget = CreateWidget<UDialogueWidget>(GetWorld(), DWClass);
	if (!ensure(DialogueWidget != nullptr)) return;
	DialogueWidget->AddToViewport();
}

FText ANonPlayerCharacter::GetActionDescription()
{
	return FText::FromString("talk");
}

float ANonPlayerCharacter::SetSentimentValueNPC(float SentimentInValuePython)
{
	SentimentValueNPC = SentimentInValuePython;
	return SentimentValueNPC;
}

FString ANonPlayerCharacter::SetInputTokenTags(FString InputPython)
{
	InputTokenTags = InputPython;
	return InputTokenTags;
}