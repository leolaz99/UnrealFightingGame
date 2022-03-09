#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LLAttributes.h"
#include "LLEnemy.generated.h"

UCLASS()
class UNREALFIGHTINGGAME_API ALLEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	ALLEnemy();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		UAnimMontage* damageMontage;

	UFUNCTION(BlueprintCallable, Category = LL)
		void TakeDamage();

	void StunTime();

	UFUNCTION(BlueprintCallable, Category = LL)
		void Stun(float stunTime);

	FTimerHandle timerHandle;
	ULLAttributes* attributes;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool attacking;

	bool stunning;
};
