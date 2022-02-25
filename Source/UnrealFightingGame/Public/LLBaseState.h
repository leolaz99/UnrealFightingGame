#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LLBaseState.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UNREALFIGHTINGGAME_API ULLBaseState : public UObject
{
	GENERATED_BODY()

public:
	void Internal_OnEnter(class ULLStateMachine* inComponentOwner);

	UFUNCTION(BlueprintNativeEvent, Category = LL)
		void OnEnter();
	virtual void OnEnter_Implementation();

	UFUNCTION(BlueprintNativeEvent, Category = LL)
		void OnTick();
	virtual void OnTick_Implementation();
	
	UFUNCTION(BlueprintNativeEvent, Category = LL)
		void OnExit();
	virtual void OnExit_Implementation();

protected:
	UPROPERTY(BlueprintReadOnly, Category = LL)
		ULLStateMachine* ComponentOwner;
};
