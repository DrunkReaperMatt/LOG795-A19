// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/EditableTextBox.h"
#include "DialogueWordWidget.generated.h"

/**
 * 
 */
UCLASS()
class ROSETTA_API UDialogueWordWidget : public UUserWidget
{
	GENERATED_BODY()

	class UDictionary* Dictionary;
	class UDialogueWidget* ParentWidget;

	virtual void NativeConstruct() override;

	virtual bool Initialize() override;


	UFUNCTION()
	void OnTranslationHover();

	UFUNCTION()
	void OnTranslationUnhover();

	UFUNCTION()
	void ActivateTranslation();

	UFUNCTION()
	void DeactivateTranslation(const FText& InText, ETextCommit::Type InCommitType);

	void VerifyTranslated();

	UPROPERTY(meta = (BindWidget))
	UButton* TranslationButton;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Original;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Translation;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* TranslationInput;

public:
	void Setup(UDialogueWidget* ParentWidget, UDictionary* Dictionary, FString Original);
	UFUNCTION()
	void UpdateTranslation(FString TranslationString);
	void UpdateTranslation(FText TranslationText);
	void UpdateOriginal(FString OriginalString);
	void UpdateOriginal(FText OriginalText);
};
