// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/C9Pawn.h"
#include "C9.h"
// Sets default values


void ACXPawn::BeginPlay()
{
	Super::BeginPlay();

	FString NetRoleString = C9FunctionLibrary::GetRoleString(this);
	FString CombinedString = FString::Printf(TEXT("CXPawn::BeginPlay() %s [%s]"), *C9FunctionLibrary::GetNetModeString(this), *NetRoleString);
	C9FunctionLibrary::MyPrintString(this, CombinedString, 10.f);
}

void ACXPawn::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	FString NetRoleString = C9FunctionLibrary::GetRoleString(this);
	FString CombinedString = FString::Printf(TEXT("CXPawn::PossessedBy() %s [%s]"), *C9FunctionLibrary::GetNetModeString(this), *NetRoleString);
	C9FunctionLibrary::MyPrintString(this, CombinedString, 10.f);
}


