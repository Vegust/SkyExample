// Copyright Epic Games, Inc. All Rights Reserved.

#include "SkyExampleGameMode.h"
#include "SkyExampleCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "SkyPlugin/SkyActor/SkyActor.h"
#include "SkyPlugin/UI/SkyActorControlWidget.h"
#include "UObject/ConstructorHelpers.h"

ASkyExampleGameMode::ASkyExampleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

// SkyPlugin UI
void ASkyExampleGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* Controller = GetWorld()->GetFirstPlayerController())
	{
		FInputModeGameAndUI InputMode{};
		InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		Controller->SetInputMode(InputMode);
		Controller->bShowMouseCursor = true;
	}
	
	if (ASkyActor* SkyActor = Cast<ASkyActor>(UGameplayStatics::GetActorOfClass(this, ASkyActor::StaticClass())))
	{
		if (USkyActorControlWidget* ControlWidget = SkyActor->CreateControlWidget())
		{
			ControlWidget->AddToViewport(0);
		}
	}
}
