#include "LLAttributes.h"
#include "LLEnemy.h"
#include "Kismet/GameplayStatics.h"

ULLAttributes::ULLAttributes()
{
	PrimaryComponentTick.bCanEverTick = false;
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
}

void ULLAttributes::RemovePoise(const float value)
{
	poise -= value;
	if (FMath::IsNearlyEqual(GetCurrentPoise(), 0, 0.001f)) 
	{
		ALLEnemy* enemy = Cast<ALLEnemy>(GetOwner());
		enemy->stunning = true;
	}
}

void ULLAttributes::CheckLife(const FName Map)
{
	if (FMath::IsNearlyEqual(GetCurrentHealth(), 0, 0.001f))
		UGameplayStatics::OpenLevel(this, Map);
}
