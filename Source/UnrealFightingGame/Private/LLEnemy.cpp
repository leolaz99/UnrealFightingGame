#include "LLEnemy.h"

ALLEnemy::ALLEnemy()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ALLEnemy::BeginPlay()
{
	Super::BeginPlay();

	attributes = FindComponentByClass<ULLAttributes>();
}

void ALLEnemy::TakeDamage()
{
	PlayAnimMontage(damageMontage, 1.f, FName("Default"));
}

void ALLEnemy::StunTime()
{
	stunning = false;
	attributes->poise = 1.f;
}

void ALLEnemy::Stun(float stunTime)
{
	if(FMath::IsNearlyEqual(attributes->GetCurrentPoise(), 0, 0.001f))
		GetWorldTimerManager().SetTimer(timerHandle, this, &ALLEnemy::StunTime, 1.f, false, stunTime);
}

void ALLEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALLEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

