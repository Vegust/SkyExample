#include "SkyActor.h"

#include "Blueprint/UserWidget.h"
#include "Engine/DirectionalLight.h"
#include "Kismet/GameplayStatics.h"
#include "SkyPlugin/UI/SkyActorControlWidget.h"

ASkyActor::ASkyActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SkySphere = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, "SkySphere");
	SetRootComponent(SkySphere);
}

void ASkyActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	if (SkyMaterial)
	{
		SkyMaterialInstance =  SkySphere->CreateAndSetMaterialInstanceDynamicFromMaterial(0, SkyMaterial);
	}
}

USkyActorControlWidget* ASkyActor::CreateControlWidget()
{
	if (ControlWidgetClass)
	{
		if (USkyActorControlWidget* ControlWidget = CreateWidget<USkyActorControlWidget>(GetWorld(), ControlWidgetClass))
		{
			ControlWidget->Init(this);
			return ControlWidget;
		}
	}
	return nullptr;
}

void ASkyActor::Update()
{
	if (auto Light = UGameplayStatics::GetActorOfClass(this, ADirectionalLight::StaticClass()))
	{
		const FRotator NewRotator = {-Settings.SkyPitch,Settings.SkyYaw+180.f,0};
		Light->SetActorRotation(NewRotator);
	}

	if (SkyMaterialInstance)
	{
		SkyMaterialInstance->SetScalarParameterValue("SkyPitch", Settings.SkyPitch);
		SkyMaterialInstance->SetScalarParameterValue("SkyYaw", Settings.SkyYaw);
		SkyMaterialInstance->SetScalarParameterValue("SunIntensity", Settings.SunIntensity);
	}
}
