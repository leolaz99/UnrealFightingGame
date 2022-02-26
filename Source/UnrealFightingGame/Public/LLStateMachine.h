#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "LLStateMachine.generated.h"


UCLASS( ClassGroup=(LL), meta=(BlueprintSpawnableComponent) )
class UNREALFIGHTINGGAME_API ULLStateMachine : public UActorComponent
{
	GENERATED_BODY()

public:	
	ULLStateMachine();

	UFUNCTION(BlueprintCallable, Category = LL)
		void TriggerTransition(const FGameplayTag stateTag);

	UFUNCTION(BlueprintCallable, Category = LL)
	FGameplayTag GetCurrentState() const 
	{
		return currentStateTag;
	}

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = LL)
		TMap<FGameplayTag, TSubclassOf<class ULLBaseState>> StatesConfig;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;	

	UPROPERTY()
		TMap<FGameplayTag, class ULLBaseState*> States;

	ULLBaseState* currentState;
	FGameplayTag currentStateTag;
};
