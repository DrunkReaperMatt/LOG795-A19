// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "DlgDialogueParticipant.h"
#include "DlgDialogue.h"
#include "RosettaCharacter.h"
#include "NonPlayerCharacter.generated.h"

/**
 *
 */
UCLASS()
class ROSETTA_API ANonPlayerCharacter : public AInteractableActor, public IDlgDialogueParticipant
{
	GENERATED_BODY()

		ANonPlayerCharacter();

	UPROPERTY()
		TSubclassOf<class UUserWidget> DWClass;



	//UFUNCTION(BlueprintGetter)
	virtual FText GetActionDescription() override;

	class ARosettaCharacter* player;

public:
	virtual void Interact() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = DialogueData)
		FName npcName = FName("NPC_Dirk");

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DialogueData)
		UDlgDialogue* dialogueData;

	FName GetParticipantName_Implementation() const override { return npcName; };

	UPROPERTY(BlueprintReadOnly)
		float SentimentValueNPC;

	UFUNCTION(BlueprintCallable, Category = "Unreal Python")
		float SetSentimentValueNPC(float SentimentInValuePython);

	UPROPERTY(BlueprintReadOnly)
		FString InputTokenTags;

	UFUNCTION(BlueprintCallable, Category = "Unreal Python")
		FString SetInputTokenTags(FString InputPython);

	UPROPERTY(BlueprintReadOnly)
		bool ShouldNPCGoAway;

};
