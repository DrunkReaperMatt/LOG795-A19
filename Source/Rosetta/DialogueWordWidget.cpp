// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueWordWidget.h"
#include "DialogueWidget.h"
#include "Dictionary.h"
#include "DictionaryEntry.h"

void UDialogueWordWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Bind delegates here.
}

bool UDialogueWordWidget::Initialize()
{
	Super::Initialize();

	TranslationButton->OnHovered.AddDynamic(this, &UDialogueWordWidget::OnTranslationHover);
	TranslationButton->OnUnhovered.AddDynamic(this, &UDialogueWordWidget::OnTranslationUnhover);
	TranslationButton->OnClicked.AddDynamic(this, &UDialogueWordWidget::ActivateTranslation);
	TranslationInput->OnTextCommitted.AddDynamic(this, &UDialogueWordWidget::DeactivateTranslation);

	return true;
}

void UDialogueWordWidget::Setup(UDialogueWidget* ParentWidget, UDictionary* Dictionary, FString Original)
{
	this->Dictionary = Dictionary;
	this->ParentWidget = ParentWidget;
	UpdateOriginal(Original);

	if (Dictionary->Contains(Original))
	{
		Translation->SetText(FText::FromString(Dictionary->GetEntry(Original)->GetTranslation()));
	}
	else
	{
		Translation->SetText(FText::FromString(Original));
	}
	
	UDialogueWordWidget::VerifyTranslated();
}

void UDialogueWordWidget::OnTranslationHover()
{
	Translation->SetColorAndOpacity(FSlateColor(FColor::Purple));
}

void UDialogueWordWidget::OnTranslationUnhover()
{
	Translation->SetColorAndOpacity(FSlateColor(FColor::White));
}

void UDialogueWordWidget::ActivateTranslation()
{
	Translation->SetVisibility(ESlateVisibility::Hidden);
	TranslationInput->SetText(Translation->GetText());
	TranslationInput->SetVisibility(ESlateVisibility::Visible);
	TranslationInput->SetUserFocus(GetWorld()->GetFirstPlayerController());
}

void UDialogueWordWidget::DeactivateTranslation(const FText& InText, ETextCommit::Type InCommitType)
{
	Translation->SetVisibility(ESlateVisibility::Visible);
	UDialogueWordWidget::UpdateTranslation(TranslationInput->GetText());
	TranslationInput->SetVisibility(ESlateVisibility::Hidden);
	UDialogueWordWidget::VerifyTranslated();
}

void UDialogueWordWidget::VerifyTranslated()
{
	if (!Translation->GetText().EqualTo(Original->GetText()))
	{
		Original->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		Original->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UDialogueWordWidget::UpdateTranslation(FString TranslationText)
{
	UDialogueWordWidget::UpdateTranslation(FText::FromString(TranslationText));
}

void UDialogueWordWidget::UpdateTranslation(FText TranslationText)
{
	Translation->SetText(TranslationText);
	FString OriginalString = Original->GetText().ToString();
	FString TranslationString = Translation->GetText().ToString();
	if (Dictionary->Contains(OriginalString))
	{
		Dictionary->UpdateEntryTranslation(OriginalString, TranslationString);
	}
	else
	{
		Dictionary->AddEntry(OriginalString, TranslationString);
	}
	UDialogueWordWidget::VerifyTranslated();
}

void UDialogueWordWidget::UpdateOriginal(FString OriginalText)
{
	UDialogueWordWidget::UpdateOriginal(FText::FromString(OriginalText));
}

void UDialogueWordWidget::UpdateOriginal(FText OriginalText)
{
	Original->SetText(OriginalText);
	UDialogueWordWidget::VerifyTranslated();
}