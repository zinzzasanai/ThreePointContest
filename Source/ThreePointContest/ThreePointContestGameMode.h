// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "ThreePointContestGameMode.generated.h"

/**
 * 
 */
UCLASS()
class THREEPOINTCONTEST_API AThreePointContestGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	AThreePointContestGameMode();

	virtual void BeginPlay() override;

	UFUNCTION()
	void ChangeMenuWidget( TSubclassOf<UUserWidget> newWidgetClass );

protected:
	UPROPERTY()
	TSubclassOf<UUserWidget> _startingWidgetClass;

	UPROPERTY()
	UUserWidget* _currentWidget;

};
