// Fill out your copyright notice in the Description page of Project Settings.


#include "C9PlayerController.h"
#include "C9.h"
#include "UI/C9ChatInput.h"
#include <Kismet/KismetSystemLibrary.h>
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "Game/C9GameModeBase.h"
#include "C9PlayerState.h"
#include "Net/UnrealNetwork.h"


AC9PlayerController::AC9PlayerController()
{
	bReplicates = true;
}

void AC9PlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (IsLocalController() == false)
	{
		return;
	}

	FInputModeUIOnly InputModeUIOnly;
	SetInputMode(InputModeUIOnly);

	if (IsValid(ChatInputWidgetClass) == true)
	{
		ChatInputWidgetInstance = CreateWidget<UC9ChatInput>(this, ChatInputWidgetClass);
		if (IsValid(ChatInputWidgetInstance) == true)
		{
			ChatInputWidgetInstance->AddToViewport();
		}
	}

	if (IsValid(NotificationTextWidgetClass) == true)
	{
		NotificationTextWidgetInstance = CreateWidget<UUserWidget>(this, NotificationTextWidgetClass);
		if (IsValid(NotificationTextWidgetInstance) == true)
		{
			NotificationTextWidgetInstance->AddToViewport();
		}
	}
}

void AC9PlayerController::SetChatMessageString(const FString& InChatMessageString)
{
	ChatMessageString = InChatMessageString;

	//PrintChatMessageString(ChatMessageString);
	if (IsLocalController() == true)
	{
		//ServerRPCPrintChatMessageString(InChatMessageString);

		AC9PlayerState* C9PS = GetPlayerState<AC9PlayerState>();
		if (IsValid(C9PS) == true)
		{
			
			FString CombinedMessageString = C9PS->GetPlayerInfoString() + TEXT(": ") + InChatMessageString;

			ServerRPCPrintChatMessageString(CombinedMessageString);
		}
	}
}

void AC9PlayerController::PrintChatMessageString(const FString& InChatMessageString)
{
	//UKismetSystemLibrary::PrintString(this, ChatMessageString, true, true, FLinearColor::Red, 5.0f);
	/*FString NetModeString = C9FunctionLibrary::GetNetModeString(this);
	FString CombinedMessageString = FString::Printf(TEXT("%s: %s"), *NetModeString, *InChatMessageString);
	C9FunctionLibrary::MyPrintString(this, CombinedMessageString, 10.f);*/
	C9FunctionLibrary::MyPrintString(this, InChatMessageString, 10.f);
}

void AC9PlayerController::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, NotificationText);
}
void AC9PlayerController::ClientRPCPrintChatMessageString_Implementation(const FString& InChatMessageString)
{
	PrintChatMessageString(InChatMessageString);
}

void AC9PlayerController::ServerRPCPrintChatMessageString_Implementation(const FString& InChatMessageString)
{
	AGameModeBase* GM = UGameplayStatics::GetGameMode(this);
	if (IsValid(GM) == true)
	{
		AC9GameModeBase* C9GM = Cast<AC9GameModeBase>(GM);
		if (IsValid(C9GM) == true)
		{
			C9GM->PrintChatMessageString(this, InChatMessageString);
		}
	}
}