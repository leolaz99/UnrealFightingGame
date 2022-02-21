#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "LLPlayer.generated.h"

UCLASS()
class UNREALFIGHTINGGAME_API ALLPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	ALLPlayer();

	bool sparring;

	bool sprinting;

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = LL)
		void MoveForward(float verticalAxis);

	UFUNCTION(BlueprintCallable, Category = LL)
		void MoveHorizontal(float horizontalAxis);

	UFUNCTION(BlueprintCallable, Category = LL)
		void MoveCameraHorizontal(float axisValue);

	UFUNCTION(BlueprintCallable, Category = LL)
		void StartSprint();
	
	UFUNCTION(BlueprintCallable, Category = LL)
		void StopSprint();
	
	UFUNCTION(BlueprintCallable, Category = LL)
		void CheckSprint(float verticalAxisValue, float horizontalAxisValue);
	
	UFUNCTION(BlueprintCallable, Category = LL)
		void StartSparring();
	
	UFUNCTION(BlueprintCallable, Category = LL)
		void StopSparring();
	
	//UFUNCTION(BlueprintCallable, Category = LL)
	//	void Rolling();
	
	UPROPERTY(BlueprintReadOnly, Category = LL)
		float sensitivity;
	
	UPROPERTY(EditAnywhere)
		float normalSpeed;
	
	UPROPERTY(EditAnywhere)
		float normalSensitivity;
	
	UPROPERTY(EditAnywhere)
		float sprintSpeed;
	
	UPROPERTY(EditAnywhere)
		float sparringSpeed;
	
	UPROPERTY(EditAnywhere)
		float sparringSensitivity;
	
	UPROPERTY(EditAnywhere)
		float sparringFOV;
	
	UPROPERTY(EditAnywhere)
		float fovChangeSpeed;

	float actualVerticalAxis;
	
	float actualHorizontalAxis;
	
	float normalFOV;

	APlayerCameraManager* playerCamera;
	USpringArmComponent* springArm;
	UCharacterMovementComponent* movComp;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
