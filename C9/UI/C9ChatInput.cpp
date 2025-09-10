// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/C9ChatInput.h"
#include "Components/EditableTextBox.h"
#include "Player/C9PlayerController.h"

void UC9ChatInput::NativeConstruct()
{
    Super::NativeConstruct();

    if (EditableTextBox_ChatInput)
    {
        EditableTextBox_ChatInput->OnTextCommitted.RemoveDynamic(
            this, &ThisClass::OnChatInputTextCommitted);
        EditableTextBox_ChatInput->OnTextCommitted.AddDynamic(
            this, &ThisClass::OnChatInputTextCommitted);
    }
}

void UC9ChatInput::NativeDestruct()
{
    if (EditableTextBox_ChatInput)
    {
        EditableTextBox_ChatInput->OnTextCommitted.RemoveDynamic(
            this, &ThisClass::OnChatInputTextCommitted);
    }
    Super::NativeDestruct();
}



void UC9ChatInput::OnChatInputTextCommitted(const FText& Text, ETextCommit::Type CommitMethod)
{
	if (CommitMethod == ETextCommit::OnEnter)
	{
		APlayerController* OwningPlayerController = GetOwningPlayer();
		if (IsValid(OwningPlayerController) == true)
		{
			AC9PlayerController* OwningC9PlayerController = Cast<AC9PlayerController>(OwningPlayerController);
			if (IsValid(OwningC9PlayerController) == true)
			{
				OwningC9PlayerController->SetChatMessageString(Text.ToString());

				EditableTextBox_ChatInput->SetText(FText());
			}
		}
	}
}