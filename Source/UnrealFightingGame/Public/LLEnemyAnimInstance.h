#pragma once

#include "CoreMinimal.h"
#include "LLAnimInstance.h"
#include "LLEnemy.h"
#include "LLEnemyAnimInstance.generated.h"

UCLASS()
class UNREALFIGHTINGGAME_API ULLEnemyAnimInstance : public ULLAnimInstance
{
	GENERATED_BODY()
	
protected:

	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable, Category = LL)
		void CheckAttack();

	UPROPERTY(BlueprintReadOnly, Category = LL)
	bool isAttacking;

	ALLEnemy* characterInstance;
};
