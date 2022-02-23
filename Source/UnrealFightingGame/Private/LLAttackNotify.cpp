#include "LLAttackNotify.h"
#include "LLAttack.h"

void ULLAttackNotify::NotifyTick(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation, float FrameDeltaTime)
{
	owner = Cast<ALLPlayer>(MeshComp->GetOwner());
	if (owner)
	{
		attack = owner->FindComponentByClass<ULLAttack>();
		attack->Attack();
	}
}

void ULLAttackNotify::NotifyEnd(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation)
{
	owner = Cast<ALLPlayer>(MeshComp->GetOwner());
	if (owner)
	{
		attack = owner->FindComponentByClass<ULLAttack>();
		attack->isDamaged = false;
	}
}
