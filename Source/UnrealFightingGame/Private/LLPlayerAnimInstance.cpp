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
}
