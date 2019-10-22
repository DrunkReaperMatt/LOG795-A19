// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/HorizontalBox.h"
#include "Components/EditableTextBox.h"
#include "DialogueWidget.generated.h"

/**
 * 
 */
UCLASS()
class ROSETTA_API UDialogueWidget : public UUserWidget
{
	GENERATED_BODY()

	UDialogueWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	virtual bool Initialize() override;

	void Setup();

	void GenerateWordWidgets(FString Sentence);

	UFUNCTION()
	void OkayPressed();

	void ActivateResponse();

	UFUNCTION()
	void DeactivateResponse(const FText& InText, ETextCommit::Type InCommitType);

	bool CompareResponse();

	bool ResponseHasNumber();

	void CloseWidget();

	UPROPERTY(meta = (BindWidget))
	UButton* OkayButton;

	UPROPERTY(meta = (BindWidget))
	UHorizontalBox* WordsPanel;

	UPROPERTY()
	TSubclassOf<class UUserWidget> DWWClass;

	//FString DialogueIntroLine = "Hello there , stranger !";
	//FString DialogueIntroLine2 = "I am blind , and so I cannot count how many buildings";
	//FString DialogueIntroLine3 = "are in town . Could you count them for me ?";
	//FString DialogueResponseGood = "Thirteen ? Wow , that is a lot of buildings ! Thank you for your help .";
	//FString DialogueResponseBad = "I am sorry , but I did not understand what you said .";
	//FString DialogueResponseBadNumber = "Hmm , I seem to recall a different number .";
	//FString DialogueResponseBadNumber2 = "Could you count again , pretty please ?";

	FString DialogueIntroLine = "Grany jweeb , olgada !";
	FString DialogueIntroLine2 = "A zu nasee , iko meh A pandu jojo wa saba kischmet";
	FString DialogueIntroLine3 = "sont nepi mantra . Kozo jula miki jojo jubus tom Da ?";
	FString DialogueResponseGood = "Zvari ? Wow , juba ze ma hünt uve kischmet ! Kula jula lep julan jimji .";
	FString DialogueResponseBad = "A zu ouchi , buta A hua du undami kime jula wawa .";
	FString DialogueResponseBadNumber = "Hmm , A qual ku mul e vuruzu zvarma .";
	FString DialogueResponseBadNumber2 = "Kozo jula jojo luis , jibi miki ?";

	//FString DialogueIntroLine = "Hello there , olgada !";
	//FString DialogueIntroLine2 = "I am blind , and so I cannot jojo how many kischmet";
	//FString DialogueIntroLine3 = "sont in town . Could jula please jojo them for Da ?";
	//FString DialogueResponseGood = "Zvari ? Wow , that is a hünt of kischmet ! Kula jula for your jimji .";
	//FString DialogueResponseBad = "I am ouchi , but I did not undami kime you said .";
	//FString DialogueResponseBadNumber = "Hmm , I seem ku recall a different zvarma .";
	//FString DialogueResponseBadNumber2 = "Could jula jojo again , pretty please ?";

	int DialogueStep;
	
	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* ResponseInput;

	class ARosettaCharacter* Player;

public:
	void UpdateDictionary(FString OriginalWord, FString NewTranslation);
};
