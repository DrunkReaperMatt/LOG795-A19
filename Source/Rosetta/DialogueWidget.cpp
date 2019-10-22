// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueWidget.h"
#include <Engine/Engine.h>
#include <WidgetBlueprintLibrary.h>
#include <ConstructorHelpers.h>
#include "Blueprint/WidgetTree.h"
#include "DialogueWordWidget.h"
#include "Components/HorizontalBoxSlot.h"
#include "RosettaCharacter.h"

UDialogueWidget::UDialogueWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> DWWClassFinder(TEXT("/Game/UI/DialogueWordWidget"));
	DWWClass = DWWClassFinder.Class;
}

void UDialogueWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Bind delegates here.
}

bool UDialogueWidget::Initialize()
{
	Super::Initialize();
	OkayButton->OnClicked.AddDynamic(this, &UDialogueWidget::OkayPressed);
	ResponseInput->OnTextCommitted.AddDynamic(this, &UDialogueWidget::DeactivateResponse);
	
	UDialogueWidget::Setup();

	UDialogueWidget::GenerateWordWidgets(DialogueIntroLine);
	return true;
}

void UDialogueWidget::Setup()
{
	DialogueStep = 0;

	UWorld* World = GetWorld();
	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;
	PlayerController->bShowMouseCursor = true;
	UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerController);
	ResponseInput->SetVisibility(ESlateVisibility::Hidden);
	Player = Cast<ARosettaCharacter>(PlayerController->GetPawn());
	if (!ensure(Player != nullptr)) return;
}

void UDialogueWidget::GenerateWordWidgets(FString Sentence)
{
	WordsPanel->SetVisibility(ESlateVisibility::Visible);
	WordsPanel->ClearChildren();

	TArray<FString> Words;
	Sentence.ParseIntoArray(Words, TEXT(" "));

	for (FString Word : Words)
	{
		UDialogueWordWidget* DWW = CreateWidget<UDialogueWordWidget>(GetWorld(), DWWClass);
		DWW->SetParentWidget(this);

		DWW->UpdateOriginal(Word);
		if (Player)
		{
			if (!Player->GetDictionary().Contains(Word))
			{
				UDialogueWidget::UpdateDictionary(Word, Word);
			}

			DWW->UpdateTranslation(Player->GetDictionary()[Word]);
		}

		FSlateChildSize Size = FSlateChildSize(ESlateSizeRule::Fill);
		WordsPanel->AddChild(DWW);
		UHorizontalBoxSlot* HBoxSlot = Cast<UHorizontalBoxSlot>(DWW->Slot);
		if (HBoxSlot)
		{
			//UE_LOG(LogTemp, Warning, TEXT("Found box %s"), *HBoxSlot->GetName());
			HBoxSlot->SetSize(Size);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("No box found"));
		}
	}
}

void UDialogueWidget::OkayPressed()
{
	DialogueStep++;

	switch (DialogueStep)
	{
		case 1:
			UDialogueWidget::GenerateWordWidgets(DialogueIntroLine2);
			break;
		case 2:
			UDialogueWidget::GenerateWordWidgets(DialogueIntroLine3);
			break;
		case 3:
			// set up input
			UDialogueWidget::ActivateResponse();
			break;
		case 4:
			// true if the response was "13", "thirteen" or "zvari"
			ResponseInput->SetVisibility(ESlateVisibility::Hidden);
			if (UDialogueWidget::CompareResponse())
			{
				UDialogueWidget::GenerateWordWidgets(DialogueResponseGood);
			}
			else if (UDialogueWidget::ResponseHasNumber())
			{
				UDialogueWidget::GenerateWordWidgets(DialogueResponseBadNumber);
			}
			else
			{
				UDialogueWidget::GenerateWordWidgets(DialogueResponseBad);
			}
			break;
		case 5:
			if (UDialogueWidget::ResponseHasNumber() && !UDialogueWidget::CompareResponse())
			{
				UDialogueWidget::GenerateWordWidgets(DialogueResponseBadNumber2);
			}
			else
			{
				UDialogueWidget::CloseWidget();
			}
			break;
		case 6:
			UDialogueWidget::CloseWidget();
			break;
	}
}

void UDialogueWidget::ActivateResponse()
{
	WordsPanel->SetVisibility(ESlateVisibility::Hidden);
	ResponseInput->SetVisibility(ESlateVisibility::Visible);
	ResponseInput->SetUserFocus(GetWorld()->GetFirstPlayerController());
}

void UDialogueWidget::DeactivateResponse(const FText& InText, ETextCommit::Type InCommitType)
{
	if (InCommitType == ETextCommit::OnEnter)
	{
		//ResponseInput->SetVisibility(ESlateVisibility::Hidden);
		UDialogueWidget::OkayPressed();
	}
}

bool UDialogueWidget::CompareResponse()
{
	FString s = ResponseInput->GetText().ToString();
	
	if (s.Contains("13") || s.Contains("thirteen") || s.Contains("zvari"))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool UDialogueWidget::ResponseHasNumber()
{
	FString s = ResponseInput->GetText().ToString();
	if (
		s.Contains("0") || s.Contains("zero") ||
		s.Contains("1") || s.Contains("one") ||
		s.Contains("2") || s.Contains("two") ||
		s.Contains("3") || s.Contains("three") ||
		s.Contains("4") || s.Contains("four") ||
		s.Contains("5") || s.Contains("five") ||
		s.Contains("6") || s.Contains("six") ||
		s.Contains("7") || s.Contains("seven") ||
		s.Contains("8") || s.Contains("eight") ||
		s.Contains("9") || s.Contains("nine") ||
		s.Contains("10") || s.Contains("ten") ||
		s.Contains("11") || s.Contains("eleven") ||
		s.Contains("12") || s.Contains("twelve") ||
		s.Contains("13") || s.Contains("thirteen") || s.Contains("zvari") ||
		s.Contains("14") || s.Contains("fourteen") ||
		s.Contains("15") || s.Contains("fifteen") ||
		s.Contains("16") || s.Contains("sixteen") ||
		s.Contains("17") || s.Contains("seventeen") ||
		s.Contains("18") || s.Contains("eighteen") ||
		s.Contains("19") || s.Contains("nineteen") ||
		s.Contains("20") || s.Contains("twenty")
		)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void UDialogueWidget::CloseWidget()
{
	UWorld* World = GetWorld();
	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;
	PlayerController->bShowMouseCursor = false;
	UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController);

	//GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, TEXT("Widget closed"));
	RemoveFromParent();
}

void UDialogueWidget::UpdateDictionary(FString OriginalWord, FString NewTranslation)
{
	Player->UpdateDictionary(OriginalWord, NewTranslation);
}