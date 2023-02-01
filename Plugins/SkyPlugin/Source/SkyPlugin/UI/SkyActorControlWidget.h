#pragma once

#include "CoreMinimal.h"
#include "SkyControlParamWidget.h"
#include "Blueprint/UserWidget.h"
#include "SkyPlugin/SkyActor/SkyActor.h"
#include "SkyActorControlWidget.generated.h"

class UVerticalBox;

UCLASS()
class SKYPLUGIN_API USkyActorControlWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void Init(ASkyActor* InSky);

	void AddParameter(FText Name, float& ValueRef, float MinValue, float MaxValue);

	UPROPERTY()
	ASkyActor* ControlledSkyActor;

	UPROPERTY(meta=(BindWidget))
	UVerticalBox* ParameterList;

	UPROPERTY(EditAnywhere)
	TSubclassOf<USkyControlParamWidget> ParamClass;
};
