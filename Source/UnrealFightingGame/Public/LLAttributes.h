#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LLAttributes.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float, newVal);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALFIGHTINGGAME_API ULLAttributes : public UActorComponent
{
	GENERATED_BODY()

public:	
	ULLAttributes();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;	

	UFUNCTION(BlueprintCallable, Category = LL)
		void RemoveHealth(const float value);

	UFUNCTION(BlueprintCallable, Category = LL)
		void RemovePoise(const float value);

	UFUNCTION(BlueprintPure, Category = LL)
	float GetCurrentHealth() const
	{
		return currentHealth;
	}

	UFUNCTION(BlueprintPure, Category = LL)
	float GetCurrentPoise() const
	{
		return poise;
	}

	UFUNCTION(BlueprintPure, Category = LL)
	float GetDamage() const
	{
		return damage;
	}

	UPROPERTY(BlueprintAssignable, Category = LL)
		FOnHealthChanged OnHealthChanged;

	UPROPERTY(EditAnywhere)
		float damage;

	UPROPERTY(EditAnywhere)
		float poise;

	UFUNCTION(BlueprintCallable, Category = LL)
		void CheckLife(FName Map);

protected:
	UPROPERTY(EditAnywhere)
		float currentHealth;
};
