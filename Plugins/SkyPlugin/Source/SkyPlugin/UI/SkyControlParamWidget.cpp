#include "SkyControlParamWidget.h"

#include "Components/SpinBox.h"

void USkyControlParamWidget::NativeConstruct()
{
	Super::NativeConstruct();
	Slider->OnValueChanged.AddDynamic(this, &USkyControlParamWidget::OnSkyParamChanged);
}

void USkyControlParamWidget::OnSkyParamChanged(float Value)
{
	OnSkyParamChangedEvent.Broadcast(Value);
}
