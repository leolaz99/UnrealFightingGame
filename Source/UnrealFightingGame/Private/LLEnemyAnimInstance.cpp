#include "LLEnemyAnimInstance.h"

void ULLEnemyAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
}

void ULLEnemyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	characterInstance = Cast<ALLEnemy>(pawnOwner);

	if (pawnOwner != nullptr)
	{
		isAttacking = characterInstance->attacking;
	}
}

void ULLEnemyAnimInstance::CheckAttack()
{

}
