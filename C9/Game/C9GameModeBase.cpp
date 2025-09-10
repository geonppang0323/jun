// Fill out your copyright notice in the Description page of Project Settings.


#include "C9GameModeBase.h"
#include "C9GameStateBase.h"
#include "Player/C9PlayerController.h"
#include "EngineUtils.h"
#include "Player/C9PlayerState.h"


void AC9GameModeBase::OnPostLogin(AController* NewPlayer)
{
	Super::OnPostLogin(NewPlayer);

	AC9PlayerController* C9PlayerController = Cast<AC9PlayerController>(NewPlayer);
	if (IsValid(C9PlayerController) == true)
	{
		C9PlayerController->NotificationText = FText::FromString(TEXT("Connected to the game server."));

		AllPlayerControllers.Add(C9PlayerController);

		AC9PlayerState* C9PS = C9PlayerController->GetPlayerState<AC9PlayerState>();
		if (IsValid(C9PS) == true)
		{
			C9PS->PlayerNameString = TEXT("Player") + FString::FromInt(AllPlayerControllers.Num());
		}

		AC9GameStateBase* C9GameStateBase = GetGameState<AC9GameStateBase>();
		if (IsValid(C9GameStateBase) == true)
		{
			C9GameStateBase->MulticastRPCBroadcastLoginMessage(C9PS->PlayerNameString);
		}
	}
}

FString AC9GameModeBase::GenerateSecretNumber()
{
	TArray<int32> Numbers;
	for (int32 i = 1; i <= 9; ++i)
	{
		Numbers.Add(i);
	}

	FMath::RandInit(FDateTime::Now().GetTicks());
	Numbers = Numbers.FilterByPredicate([](int32 Num) { return Num > 0; });

	FString Result;
	for (int32 i = 0; i < 3; ++i)
	{
		int32 Index = FMath::RandRange(0, Numbers.Num() - 1);
		Result.Append(FString::FromInt(Numbers[Index]));
		Numbers.RemoveAt(Index);
	}

	return Result;
}

bool AC9GameModeBase::IsGuessNumberString(const FString& InNumberString)
{
	bool bCanPlay = false;

	do {

		if (InNumberString.Len() != 3)
		{
			break;
		}

		bool bIsUnique = true;
		TSet<TCHAR> UniqueDigits;
		for (TCHAR C : InNumberString)
		{
			if (FChar::IsDigit(C) == false || C == '0')
			{
				bIsUnique = false;
				break;
			}

			UniqueDigits.Add(C);
		}

		if (bIsUnique == false)
		{
			break;
		}

		bCanPlay = true;

	} while (false);

	return bCanPlay;
}

FString AC9GameModeBase::JudgeResult(const FString& InSecretNumberString, const FString& InGuessNumberString)
{
	int32 StrikeCount = 0, BallCount = 0;

	for (int32 i = 0; i < 3; ++i)
	{
		if (InSecretNumberString[i] == InGuessNumberString[i])
		{
			StrikeCount++;
		}
		else
		{
			FString PlayerGuessChar = FString::Printf(TEXT("%c"), InGuessNumberString[i]);
			if (InSecretNumberString.Contains(PlayerGuessChar))
			{
				BallCount++;
			}
		}
	}

	if (StrikeCount == 0 && BallCount == 0)
	{
		return TEXT("OUT");
	}

	return FString::Printf(TEXT("%dS%dB"), StrikeCount, BallCount);
}

void AC9GameModeBase::BeginPlay()
{
	Super::BeginPlay();

	SecretNumberString = GenerateSecretNumber();
}

void AC9GameModeBase::PrintChatMessageString(AC9PlayerController* InChattingPlayerController, const FString& InChatMessageString)
{
	FString ChatMessageString = InChatMessageString;
	int Index = InChatMessageString.Len() - 3;
	FString GuessNumberString = InChatMessageString.RightChop(Index);
	if (IsGuessNumberString(GuessNumberString) == true)
	{
		FString JudgeResultString = JudgeResult(SecretNumberString, GuessNumberString);

		IncreaseGuessCount(InChattingPlayerController);

		for (TActorIterator<AC9PlayerController> It(GetWorld()); It; ++It)
		{
			AC9PlayerController* C9PlayerController = *It;
			if (IsValid(C9PlayerController) == true)
			{
				FString CombinedMessageString = InChatMessageString + TEXT(" -> ") + JudgeResultString;
				C9PlayerController->ClientRPCPrintChatMessageString(CombinedMessageString);

				int32 StrikeCount = FCString::Atoi(*JudgeResultString.Left(1));
				JudgeGame(InChattingPlayerController, StrikeCount);

			}
		}
	}
	else
	{
		for (TActorIterator<AC9PlayerController> It(GetWorld()); It; ++It)
		{
			AC9PlayerController* C9PlayerController = *It;
			if (IsValid(C9PlayerController) == true)
			{
				C9PlayerController->ClientRPCPrintChatMessageString(InChatMessageString);
			}
		}
	}
}

void AC9GameModeBase::IncreaseGuessCount(AC9PlayerController* InChattingPlayerController)
{
	AC9PlayerState* C9PS = InChattingPlayerController->GetPlayerState<AC9PlayerState>();
	if (IsValid(C9PS) == true)
	{
		C9PS->CurrentGuessCount++;
	}
}

void AC9GameModeBase::ResetGame()
{
	SecretNumberString = GenerateSecretNumber();

	for (const auto& CXPlayerController : AllPlayerControllers)
	{
		AC9PlayerState* C9PS = CXPlayerController->GetPlayerState<AC9PlayerState>();
		if (IsValid(C9PS) == true)
		{
			C9PS->CurrentGuessCount = 0;
		}
	}
}

void AC9GameModeBase::JudgeGame(AC9PlayerController* InChattingPlayerController, int InStrikeCount)
{
	if (3 == InStrikeCount)
	{
		AC9PlayerState* C9PS = InChattingPlayerController->GetPlayerState<AC9PlayerState>();
		for (const auto& C9PlayerController : AllPlayerControllers)
		{
			if (IsValid(C9PS) == true)
			{
				FString CombinedMessageString = C9PS->PlayerNameString + TEXT(" has won the game.");
				C9PlayerController->NotificationText = FText::FromString(CombinedMessageString);

				ResetGame();
			}
		}
	}
	else
	{
		bool bIsDraw = true;
		for (const auto& CXPlayerController : AllPlayerControllers)
		{
			AC9PlayerState* C9PS = CXPlayerController->GetPlayerState<AC9PlayerState>();
			if (IsValid(C9PS) == true)
			{
				if (C9PS->CurrentGuessCount < C9PS->MaxGuessCount)
				{
					bIsDraw = false;
					break;
				}
			}
		}

		if (true == bIsDraw)
		{
			for (const auto& C9PlayerController : AllPlayerControllers)
			{
				C9PlayerController->NotificationText = FText::FromString(TEXT("Draw..."));

				ResetGame();
			}
		}
	}
}
