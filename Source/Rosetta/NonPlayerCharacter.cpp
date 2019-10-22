// Fill out your copyright notice in the Description page of Project Settings.


#include "NonPlayerCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "DialogueWidget.h"

ANonPlayerCharacter::ANonPlayerCharacter()
{
	ConstructorHelpers::FClassFinder<UUserWidget> DWClassFinder(TEXT("/Game/UI/DialogueWidget"));
	DWClass = DWClassFinder.Class;
}

void ANonPlayerCharacter::Interact()
{
	if (!ensure(DWClass != nullptr)) return;

	UUserWidget* DialogueWidget = CreateWidget<UDialogueWidget>(GetWorld(), DWClass);
	if (!ensure(DialogueWidget != nullptr)) return;

	DialogueWidget->AddToViewport();
}

FText ANonPlayerCharacter::GetActionDescription()
{
	return FText::FromString("talk");
}
