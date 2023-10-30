// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"

#include "GameFramework/GameStateBase.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Purple, TEXT("Post Login"));

	int32 NumberOfPlayers =  GameState.Get()->PlayerArray.Num();
	if (NumberOfPlayers == 2)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Post Login, players == 2"));
	
		UWorld* World = GetWorld();
		if (World)
		{
			bUseSeamlessTravel = true;
			World->ServerTravel(FString("/Game/Maps/ShooterMap?listen"));
		}
	}
}
