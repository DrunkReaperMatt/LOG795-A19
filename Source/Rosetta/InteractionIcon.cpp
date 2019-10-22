// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionIcon.h"

void UInteractionIcon::SetInteractionDescription(const FText ActionDescription)
{
	FString s = "Press E to " + ActionDescription.ToString();
	this->InteractionDescription = FText::FromString(s);
}
