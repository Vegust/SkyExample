#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SkyControlParamWidget.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnSkyParamChanged, float);

class USpinBox;
class UTextBlock;

UCLASS()
class SKYPLUGIN_API USkyControlParamWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UTextBlock* GetLabel() const { return Label; }
	USpinBox* GetSlider() const { return Slider; }
	
	FOnSkyParamChanged OnSkyParamChangedEvent;
	
protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnSkyParamChanged(float Value);
	
	UPROPERTY(meta=(BindWidget))
	UTextBlock* Label;

	UPROPERTY(meta=(BindWidget))
	USpinBox* Slider;
};
