// Fill out your copyright notice in the Description page of Project Settings.

#include "ThreePointContest.h"
#include "ThreePointContestGameMode.h"

#include "Private/FrontEndPlayerController.h"

AThreePointContestGameMode::AThreePointContestGameMode()
{
	PlayerControllerClass = AFrontEndPlayerController::StaticClass();
	static ConstructorHelpers::FObjectFinder<UClass> mainUIWidgetFinder(TEXT("WidgetBlueprint'/Game/UI/Lobby/Lobby.Lobby_C'"));
	if (mainUIWidgetFinder.Succeeded())
	{
		_startingWidgetClass = mainUIWidgetFinder.Object;
	}
}

void AThreePointContestGameMode::BeginPlay()
{
	Super::BeginPlay();

	ChangeMenuWidget( _startingWidgetClass );
}

void AThreePointContestGameMode::ChangeMenuWidget( TSubclassOf<UUserWidget> newWidgetClass )
{
	if( _currentWidget != nullptr )
	{
		_currentWidget->RemoveFromViewport();
		_currentWidget = nullptr;
	}

	if( newWidgetClass != nullptr )
	{
		_currentWidget = CreateWidget<UUserWidget>( GetWorld(), newWidgetClass );
		if( _currentWidget != nullptr )
		{
			_currentWidget->AddToViewport();
		}
	}
}


