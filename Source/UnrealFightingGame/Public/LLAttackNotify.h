#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "LLPlayer.h"
#include "LLAttack.h"
#include "LLAttackNotify.generated.h"

UCLASS()
class UNREALFIGHTINGGAME_API ULLAttackNotify : public UAnimNotifyState
{
	GENERATED_BODY()

protected:
	virtual void NotifyTick(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation, float FrameDeltaTime) override;

	virtual void NotifyEnd(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation) override;

	ULLAttack* attack;
	APawn* owner;
};
