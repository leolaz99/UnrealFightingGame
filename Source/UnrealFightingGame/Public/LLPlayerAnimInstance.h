#pragma once

#include "CoreMinimal.h"
#include "LLAnimInstance.h"
#include "LLPlayer.h"
#include "LLPlayerAnimInstance.generated.h"

UCLASS()
class UNREALFIGHTINGGAME_API ULLPlayerAnimInstance : public ULLAnimInstance
{
	GENERATED_BODY()

protected:
	ULLPlayerAnimInstance();

	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable, Category = LL)
		void CheckRoll();

	UFUNCTION(BlueprintCallable, Category = LL)
		void CheckAttack();

	UPROPERTY(BlueprintReadOnly, Category = LL)
		bool isSparring;

	UPROPERTY(BlueprintReadOnly, Category = LL)
		bool isRolling;

	UPROPERTY(BlueprintReadOnly, Category = LL)
		bool isAttacking;

	ALLPlayer* characterInstance;
};
