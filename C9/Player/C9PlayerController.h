

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "C9PlayerController.generated.h"

class UC9ChatInput;
class UUserWidget;

/**
 *
 */
UCLASS()
class C9_API AC9PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AC9PlayerController();

	virtual void BeginPlay() override;

	void SetChatMessageString(const FString& InChatMessageString);

	void PrintChatMessageString(const FString& InChatMessageString);

	UFUNCTION(Client, Reliable)
	void ClientRPCPrintChatMessageString(const FString& InChatMessageString);

	UFUNCTION(Server, Reliable)
	void ServerRPCPrintChatMessageString(const FString& InChatMessageString);

	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

	void ClientRPCPrintChatMessageString_Implementation(const FString& InChatMessageString);


protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UC9ChatInput> ChatInputWidgetClass;

	UPROPERTY()
	TObjectPtr<UC9ChatInput> ChatInputWidgetInstance;

	FString ChatMessageString;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> NotificationTextWidgetClass;

	UPROPERTY()
	TObjectPtr<UUserWidget> NotificationTextWidgetInstance;

public:
	UPROPERTY(Replicated, BlueprintReadOnly)
	FText NotificationText;

};