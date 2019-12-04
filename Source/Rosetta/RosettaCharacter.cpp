// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "RosettaCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Blueprint/UserWidget.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include <Kismet/GameplayStatics.h>
#include "Engine.h"
#include "Dictionary.h"

#include "DlgContext.h"
#include "DlgManager.h"

#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>

#define OUT

//////////////////////////////////////////////////////////////////////////
// ARosettaCharacter

ARosettaCharacter::ARosettaCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	isDictionaryOpen = false;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void ARosettaCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &ARosettaCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ARosettaCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ARosettaCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ARosettaCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &ARosettaCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ARosettaCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &ARosettaCharacter::OnResetVR);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ARosettaCharacter::Interact);
	PlayerInputComponent->BindAction("Dictionary", IE_Pressed, this, &ARosettaCharacter::OpenDictionary);
}

#pragma region Template code


void ARosettaCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void ARosettaCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	Jump();
}

void ARosettaCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	StopJumping();
}

void ARosettaCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ARosettaCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ARosettaCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ARosettaCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

#pragma endregion Template code

FVector ARosettaCharacter::GetReachLineStart() const
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	AActor* Avatar = Cast<AActor>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (Avatar)
	{
		const FVector ToPlayer = Avatar->GetActorLocation() - GetActorLocation();
		Avatar->GetActorEyesViewPoint(
			OUT PlayerViewPointLocation,
			OUT PlayerViewPointRotation
		);
	}

	FVector LineStartingPoint = PlayerViewPointLocation - FVector(0.f, 0.f, ReachLineHeightFromEyes);

	return LineStartingPoint;
}

FVector ARosettaCharacter::GetReachLineEnd() const
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	FRotator PlayerRotation;

	AActor* Avatar = Cast<AActor>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (Avatar)
	{
		const FVector ToPlayer = Avatar->GetActorLocation() - GetActorLocation();
		Avatar->GetActorEyesViewPoint(
			OUT PlayerViewPointLocation,
			OUT PlayerViewPointRotation
		);
		PlayerRotation = Avatar->GetActorRotation();
	}

	FVector LineStartingPoint = PlayerViewPointLocation - FVector(0.f, 0.f, ReachLineHeightFromEyes);

	return LineStartingPoint + PlayerRotation.Vector() * Reach;
}

void ARosettaCharacter::OpenDictionary()
{
	// Create Dictionary Widget and store it
	if (wDictionary && !DictionaryWidget) {
		DictionaryWidget = CreateWidget<UUserWidget>(GetWorld(), wDictionary);
	}
	if (DictionaryWidget) {
		if (!isDictionaryOpen) {
			isDictionaryOpen = true;
			DictionaryWidget->AddToViewport();
		}
		else {
			isDictionaryOpen = false;
			DictionaryWidget->RemoveFromParent();
		}
	}
}

void ARosettaCharacter::Interact()
{
	AInteractableActor* InteractableHit = Cast<AInteractableActor>(ARosettaCharacter::GetFirstPhysicsBodyInReach().GetActor());

	if (InteractableHit)
	{
		InteractableHit->Interact();
	}
}

void ARosettaCharacter::OnInteractableInReachStart(AInteractableActor* InteractableHit) const
{
	//FString InReachStartMessage = "Interactable " + InteractableHit->GetName() + " now in reach";
	//GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, InReachStartMessage);

	InteractableHit->SetInteractionIconVisibility(true);
}

void ARosettaCharacter::OnInteractableInReachEnd()
{
	//FString InReachStartMessage = "Interactable " + CurrentlyHitInteractable->GetName() + " no longer in reach";
	//GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, InReachStartMessage);

	CurrentlyHitInteractable->SetInteractionIconVisibility(false);
	ARosettaCharacter::ResetCurrentlyHitInteractable();
}

bool ARosettaCharacter::IsCurrentlyHitInteractableDirty() const
{
	return CurrentlyHitInteractable != nullptr;
}

void ARosettaCharacter::ResetCurrentlyHitInteractable()
{
	CurrentlyHitInteractable = nullptr;
}

void ARosettaCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	AInteractableActor* InteractableHit = Cast<AInteractableActor>(ARosettaCharacter::GetFirstPhysicsBodyInReach().GetActor());

	if (InteractableHit)
	{
		if (!ARosettaCharacter::IsCurrentlyHitInteractableDirty() || InteractableHit->GetName() != CurrentlyHitInteractable->GetName())
		{
			if (ARosettaCharacter::IsCurrentlyHitInteractableDirty())
			{
				ARosettaCharacter::OnInteractableInReachEnd();
			}
			ARosettaCharacter::OnInteractableInReachStart(InteractableHit);
		}
		CurrentlyHitInteractable = InteractableHit;
	}
	else
	{
		if (ARosettaCharacter::IsCurrentlyHitInteractableDirty())
		{
			ARosettaCharacter::OnInteractableInReachEnd();
		}
	}
}

FHitResult ARosettaCharacter::GetFirstPhysicsBodyInReach() const
{
	FHitResult HitResult;
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	//DrawDebugLine(GetWorld(), GetReachLineStart(), GetReachLineEnd(), FColor::Green, false, 1, 0, 1);

	GetWorld()->LineTraceSingleByChannel(
		OUT HitResult,
		GetReachLineStart(),
		GetReachLineEnd(),
		ECollisionChannel::ECC_Visibility,
		TraceParameters
	);

	return HitResult;
}

void ARosettaCharacter::BeginPlay()
{
	Super::BeginPlay();

	Dictionary = NewObject<UDictionary>();
	//if (ARosettaCharacter::GetDictionary().Contains(OriginalWord))
	//{
	//	Dictionary[OriginalWord] = NewTranslation;
	//}
	//else
	//{
	//	Dictionary.Add(OriginalWord, NewTranslation);
	//}
}

UDictionary* ARosettaCharacter::GetDictionary()
{
	return Dictionary;
}


// ...
void ARosettaCharacter::StartDialogue(class UDlgDialogue* Dialogue, UObject* OtherParticipant)
{
	ActiveContext = UDlgManager::StartDialogue2(Dialogue, OtherParticipant, this);
}

void ARosettaCharacter::SelectDialogueOption(int32 Index)
{
	if (ActiveContext == nullptr || Index < 0 || Index >= ActiveContext->GetOptionNum())
		return;

	if (!ActiveContext->ChooseChild(Index))
		ActiveContext = nullptr;
}

bool ARosettaCharacter::CompareResponse() {
	bAnswerPrompt = InputString.Contains("13") || InputString.Contains("thirteen") || InputString.Contains("zvari") ? true : false;

	return bAnswerPrompt;
}

void ARosettaCharacter::ResponseResult() {
	InputString = widget->ResponseInput->GetText().ToString();
}
