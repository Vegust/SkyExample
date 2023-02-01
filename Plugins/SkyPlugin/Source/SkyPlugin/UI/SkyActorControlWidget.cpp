#include "SkyActorControlWidget.h"

#include "Components/SpinBox.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"

void USkyActorControlWidget::Init(ASkyActor* InSky)
{
	if (!InSky)
	{
		return;
	}
	
	ControlledSkyActor = InSky;

	AddParameter(FText::FromString("SkyPitch"),ControlledSkyActor->GetSettings().SkyPitch, 0.f, 360.f);
	AddParameter(FText::FromString("SkyYaw"),ControlledSkyActor->GetSettings().SkyYaw, 0.f, 360.f);
	AddParameter(FText::FromString("SunIntensity"),ControlledSkyActor->GetSettings().SunIntensity, 0.f, 10000.f);
}

void USkyActorControlWidget::AddParameter(FText Name, float& ValueRef, float MinValue, float MaxValue)
{
	if (USkyControlParamWidget* ParamWidget = Cast<USkyControlParamWidget>(CreateWidget(this, ParamClass)))
	{
		ParamWidget->GetLabel()->SetText(Name);
		ParamWidget->GetSlider()->SetValue(ValueRef);
		ParamWidget->GetSlider()->SetMinValue(MinValue);
		ParamWidget->GetSlider()->SetMaxValue(MaxValue);

		ParamWidget->OnSkyParamChangedEvent.AddLambda([&ValueRef, this](float Value) mutable
		{
			ValueRef = Value;
			ControlledSkyActor->Update();
		});
		
		ParameterList->AddChildToVerticalBox(ParamWidget);
	}
}
