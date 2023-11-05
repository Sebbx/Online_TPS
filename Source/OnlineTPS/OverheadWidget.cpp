
#include "OverheadWidget.h"

#include "Components/TextBlock.h"

void UOverheadWidget::SetDisplayText(FString TextToDisplay)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	ENetRole LocalRole = InPawn->GetLocalRole();
	FString Role;

	switch (LocalRole)
	{
	case ENetRole::ROLE_Authority:
		Role = FString("Authority"); break;
		
	case ENetRole::ROLE_AutonomousProxy:
		Role = FString("AutonomousProxy"); break;
		
	case ENetRole::ROLE_SimulatedProxy:
		Role = FString("SimulatedProxy"); break;
		
	case ENetRole::ROLE_None:
		Role = FString("None"); break;
		
		default:
			Role = FString("Error, default case"); break;
	}
	FString LocalRoleString = FString::Printf(TEXT("Local Role: %s"), *Role);
	SetDisplayText(LocalRoleString);
}

void UOverheadWidget::NativeDestruct()
{
	RemoveFromParent();
	Super::NativeDestruct();
}
