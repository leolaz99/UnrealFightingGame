#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LLAttributes.h"
#include "LLAttack.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALFIGHTINGGAME_API ULLAttack : public UActorComponent
{
	GENERATED_BODY()

public:	
	ULLAttack();

protected:
	virtual void BeginPlay() override;

	USkeletalMeshComponent* skeletalMesh;
	FVector SocketLocation1;
	FVector SocketLocation2;
	TArray<AActor*> actorsToIgnore;
	FHitResult hitResult;
	ULLAttributes* attributes;

	UPROPERTY(EditAnywhere)
		USoundBase* puchSound;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;	

	void Attack();

	bool isDamaged;
};
