#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GameFramework\CharacterMovementComponent.h"
#include "LLAnimInstance.generated.h"

UCLASS()
class UNREALFIGHTINGGAME_API ULLAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	ULLAnimInstance();

	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(BlueprintReadOnly, Category = LL)
		float ActualSpeed;

	UPROPERTY(BlueprintReadOnly, Category = LL)
		float ActualDirection;

	APawn* pawnOwner;
	UCharacterMovementComponent* charMov;
};
