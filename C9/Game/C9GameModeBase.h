// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "C9GameModeBase.generated.h"

class AC9PlayerController;
/**
 * 
 */
UCLASS()
class C9_API AC9GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void OnPostLogin(AController* NewPlayer) override;

	FString GenerateSecretNumber();

	bool IsGuessNumberString(const FString& InNumberString);

	FString JudgeResult(const FString& InSecretNumberString, const FString& InGuessNumberString);

	virtual void BeginPlay() override;

	void PrintChatMessageString(AC9PlayerController* InChattingPlayerController, const FString& InChatMessageString);

	void IncreaseGuessCount(AC9PlayerController* InChattingPlayerController);

	void ResetGame();

	void JudgeGame(AC9PlayerController* InChattingPlayerController, int InStrikeCount);


protected:
	FString SecretNumberString;

	TArray<TObjectPtr<AC9PlayerController>> AllPlayerControllers;

};
