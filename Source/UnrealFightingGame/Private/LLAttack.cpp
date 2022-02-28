#include "LLAttack.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

ULLAttack::ULLAttack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void ULLAttack::BeginPlay()
{
	Super::BeginPlay();

	actorsToIgnore.Add(GetOwner());
	attributes = GetOwner()->FindComponentByClass<ULLAttributes>();
}

void ULLAttack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void ULLAttack::Attack()
{
	skeletalMesh = GetOwner()->FindComponentByClass<USkeletalMeshComponent>();
	SocketLocation1 = skeletalMesh->GetSocketLocation("lowerarm_r");
	SocketLocation2 = skeletalMesh->GetSocketLocation("middle_03_r");

	FCollisionQueryParams params;

	bool isHit = UKismetSystemLibrary::SphereTraceSingle(GetWorld(), SocketLocation1, SocketLocation2, 5.f, UEngineTypes::ConvertToTraceType(ECC_Camera), false, actorsToIgnore,
														 EDrawDebugTrace::ForDuration, hitResult, true, FLinearColor::Red, FLinearColor::Green, 1.f);

	if (isHit)
	{
		if (!isDamaged)
		{
			ULLAttributes* hittedAttributes = hitResult.GetActor()->FindComponentByClass<ULLAttributes>();
			UGameplayStatics::ApplyDamage(hitResult.GetActor(), attributes->damage, NULL, NULL, NULL);

			isDamaged = true;
		}
	}
}

