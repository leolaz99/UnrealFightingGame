#include "LLEnemyAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "LLEnemy.h"
#include "LLPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

ALLEnemyAIController::ALLEnemyAIController()
{

}

void ALLEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	if (behaviorTree) 
	{
		RunBehaviorTree(behaviorTree);
		myBlackboard = GetBlackboardComponent();
	}	

	TSubclassOf<ALLPlayer> classToFind;
	classToFind = ALLPlayer::StaticClass();
	TArray<AActor*> foundPlayer;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), classToFind, foundPlayer);

	myBlackboard->SetValueAsObject(blackboardPlayer, foundPlayer[0]);
}

void ALLEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APawn* controlledPawn = GetPawn();
	ALLEnemy* owner = Cast<ALLEnemy>(controlledPawn);

	const float distanceToPlayer = controlledPawn->GetDistanceTo(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	if (distanceToPlayer <= attackRange)
	{
		owner->attacking = true;
		myBlackboard->SetValueAsBool(blackboardPlayerInRange, true);
	}
		
	else
	{
		owner->attacking = false;
		myBlackboard->SetValueAsBool(blackboardPlayerInRange, false);
	}	

	myBlackboard->SetValueAsBool(blackboardStunned, owner->stunning);
}
