#include "LLAttributes.h"

ULLAttributes::ULLAttributes()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void ULLAttributes::BeginPlay()
{
	Super::BeginPlay();
}

void ULLAttributes::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void ULLAttributes::RemoveHealth(const float value)
{
	currentHealth -= value;
	OnHealthChanged.Broadcast(value);

	if (FMath::IsNearlyEqual(GetCurrentHealth(), 0, 0.001f))
	{
	}
}
