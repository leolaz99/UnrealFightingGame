#include "LLPlayerAnimInstance.h"
#include "LLPlayer.h"

ULLPlayerAnimInstance::ULLPlayerAnimInstance()
{

}

void ULLPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	characterInstance = Cast<ALLPlayer>(pawnOwner);
}

void ULLPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (pawnOwner != nullptr)
	{
		isSparring = characterInstance->sparring;
		isRolling = characterInstance->roll;
	}
}

void ULLPlayerAnimInstance::CheckRoll()
{
	characterInstance->roll = false;
}
