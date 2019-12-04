// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InteractableActor.h"
#include "DlgDialogueParticipant.h"

#include "DialogueWidget.h"

#include "RosettaCharacter.generated.h"

UCLASS(config = Game, Blueprintable)
class ARosettaCharacter : public ACharacter, public IDlgDialogueParticipant
{
	GENERATED_BODY()

		/** Camera boom positioning the camera behind the character */
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;
public:
	ARosettaCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	/** Dictionary Widget */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Widgets)
	TSubclassOf<class UUserWidget> wDictionary;

	UUserWidget* DictionaryWidget;

protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	virtual void Tick(float DeltaTime) override;

	FHitResult GetFirstPhysicsBodyInReach() const;

protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Reach = 100.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float ReachLineHeightFromEyes = 0.f;

	FVector GetReachLineStart() const;

	FVector GetReachLineEnd() const;

	void Interact();
	void OpenDictionary();
private:
	AInteractableActor* CurrentlyHitInteractable = nullptr;

	void OnInteractableInReachStart(AInteractableActor* ActorHit) const;
	void OnInteractableInReachEnd();
	bool IsCurrentlyHitInteractableDirty() const;
	void ResetCurrentlyHitInteractable();

	class UDictionary* Dictionary;
	bool isDictionaryOpen;

public:
	void UpdateDictionary(FString OriginalWord, FString NewTranslation);


	/// DLG Dialogue
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DlgData, meta = (AllowPrivateAccess = "true"))
		FName DlgParticipantName = FName("MyCharacterName");

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DlgData, meta = (AllowPrivateAccess = "true"))
		FText DlgParticipantDisplayName;


	FName GetParticipantName_Implementation() const override { return DlgParticipantName; }
	FText GetParticipantDisplayName_Implementation(FName ActiveSpeaker) const override { return DlgParticipantDisplayName; }

	bool OnDialogueEvent_Implementation(const FName& EventName) override { return false; }
	bool CheckCondition_Implementation(const FName& ConditionName) const override { return false; }

	UFUNCTION(BlueprintCallable, Category = DlgSystem)
		void StartDialogue(class UDlgDialogue* Dialogue, UObject* OtherParticipant);

	UFUNCTION(BlueprintCallable, Category = DlgSystem)
		void SelectDialogueOption(int32 Index);

	UFUNCTION()
		UDlgContext* GetActiveContext() { return ActiveContext; }

private:

	class UDlgContext* ActiveContext = nullptr;

	FString InputString;

public:
	UFUNCTION(BlueprintCallable)
		bool CompareResponse();

	UPROPERTY(BlueprintReadWrite)
		bool bAnswerPrompt = false;

	void SetInputString(FString inputString) { InputString = inputString; }

	FString GetInputString() { return InputString; }

	UDialogueWidget* widget = nullptr;

	UFUNCTION(BlueprintCallable)
		void ResponseResult();

	void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
	UDictionary* GetDictionary();
};
