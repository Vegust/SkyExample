// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SkyExampleGameMode.generated.h"

UCLASS(minimalapi)
class ASkyExampleGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASkyExampleGameMode();

	// SkyPlugin UI
	virtual void BeginPlay() override;
};



