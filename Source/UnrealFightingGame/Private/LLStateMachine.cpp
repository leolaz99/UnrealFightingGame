#include "LLStateMachine.h"
#include "LLBaseState.h"

ULLStateMachine::ULLStateMachine()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void ULLStateMachine::TriggerTransition(const FGameplayTag stateTag)
{
	if (!States.Contains(stateTag)) 
	{
		return;
	}

	if (currentState) 
	{
		currentState->OnExit();
	}

	ULLBaseState** currentStatePtr = States.Find(stateTag);

	if (currentStatePtr) {
		currentStateTag = stateTag;
		currentState = *currentStatePtr;
		currentState->Internal_OnEnter(this);
		currentState->OnEnter();
	}
}

void ULLStateMachine::BeginPlay()
{
	Super::BeginPlay();

	for (const auto& stateClass : StatesConfig) 
	{
		ULLBaseState* newState = NewObject<ULLBaseState>(this, stateClass.Value);
		States.Add(stateClass.Key, newState);
	}
}

void ULLStateMachine::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (currentState) 
	{
		currentState->OnTick();
	}
}

