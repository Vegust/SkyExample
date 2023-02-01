#pragma once

#include "CoreMinimal.h"
#include "SkyActor.generated.h"

class USkyActorControlWidget;

USTRUCT(BlueprintType)
struct FSkyActorSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float SkyPitch = 45.f;
	
	UPROPERTY(EditAnywhere)
	float SkyYaw = 45.f;

	UPROPERTY(EditAnywhere)
	float SunIntensity = 20.f;
};

UCLASS()
class SKYPLUGIN_API ASkyActor : public AActor
{
	GENERATED_BODY()

public:

	FSkyActorSettings& GetSettings() { return Settings; }
	void SetSettings(const FSkyActorSettings& InSettings) { Settings = InSettings; Update(); }
	void Update();
	USkyActorControlWidget* CreateControlWidget();
	
protected:
	ASkyActor(const FObjectInitializer& ObjectInitializer);
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override { Update(); }

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* SkySphere;

	UPROPERTY(EditAnywhere)
	TSubclassOf<USkyActorControlWidget> ControlWidgetClass;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* SkyMaterial;

	UPROPERTY()
	UMaterialInstanceDynamic* SkyMaterialInstance;

	UPROPERTY(EditAnywhere)
	FSkyActorSettings Settings;
};
