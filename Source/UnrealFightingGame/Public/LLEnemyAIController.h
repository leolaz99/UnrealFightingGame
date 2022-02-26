#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "LLEnemyAIController.generated.h"

UCLASS()
class UNREALFIGHTINGGAME_API ALLEnemyAIController : public AAIController
{
	GENERATED_BODY()

public:
	ALLEnemyAIController();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		UBehaviorTree* behaviorTree;

	UBlackboardComponent* myBlackboard;

	UPROPERTY(EditAnywhere)
		float attackRange;

	UPROPERTY(EditAnywhere)
		FName blackboardPlayer;

	UPROPERTY(EditAnywhere)
		FName blackboardPlayerInRange;

public:
	virtual void Tick(float DeltaTime) override;
	
};
