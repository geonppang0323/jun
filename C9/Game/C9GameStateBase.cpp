// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/C9GameStateBase.h"
#include "Kismet/GameplayStatics.h"
#include "Player/C9PlayerController.h"

void AC9GameStateBase::MulticastRPCBroadcastLoginMessage_Implementation(const FString& InNameString)
{
	if (HasAuthority() == false)
	{
		APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		if (IsValid(PC) == true)
		{
			AC9PlayerController* C9PC = Cast<AC9PlayerController>(PC);
			if (IsValid(C9PC) == true)
			{
				FString NotificationString = InNameString + TEXT(" has joined the game.");
				C9PC->PrintChatMessageString(NotificationString);
			}
		}
	}
}