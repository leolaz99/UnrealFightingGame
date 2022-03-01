#include "LLPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"

ALLPlayer::ALLPlayer()
{
	PrimaryActorTick.bCanEverTick = true;
	normalSensitivity = 1.f;
}

void ALLPlayer::BeginPlay()
{
	Super::BeginPlay();	

	playerCamera = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;
	springArm = FindComponentByClass<USpringArmComponent>();
	movComp = GetCharacterMovement();

	GetCharacterMovement()->MaxWalkSpeed = normalSpeed;

	sensitivity = normalSensitivity;
	normalFOV = playerCamera->GetFOVAngle();
}

void ALLPlayer::MoveForward(float verticalAxis)
{
	actualVerticalAxis = verticalAxis;
	
	FRotator rotation = GetControlRotation();
	FRotator direction = FRotator(0.f, rotation.Yaw, 0.f);

	FVector directionVector = UKismetMathLibrary::GetForwardVector(direction);
	movComp->AddInputVector(directionVector * verticalAxis, false);
}

void ALLPlayer::MoveHorizontal(float horizontalAxis)
{
	actualHorizontalAxis = horizontalAxis;

	FRotator rotation = GetControlRotation();
	FRotator direction = FRotator(0.f, rotation.Yaw, 0.f);

	FVector directionVector = UKismetMathLibrary::GetRightVector(direction);
	movComp->AddInputVector(directionVector * horizontalAxis, false);
}

void ALLPlayer::MoveCameraHorizontal(float axisValue)
{
	float horizontalSpeed = axisValue * sensitivity;
	AddControllerYawInput(horizontalSpeed);
}

void ALLPlayer::StartSprint()
{
	if (!rolling && !attacking)
	{
		sprinting = true;
		StopSparring();

		if (!sparring)
		{
			GetCharacterMovement()->MaxWalkSpeed = sprintSpeed;
		}
	}
}

void ALLPlayer::StopSprint()
{
	sprinting = false;

	if (!sparring)
		GetCharacterMovement()->MaxWalkSpeed = normalSpeed;
}

void ALLPlayer::CheckSprint(float verticalAxisValue, float horizontalAxisValue)
{
	if (verticalAxisValue == 0 && horizontalAxisValue == 0 && sprinting == true)
		StopSprint();
}

void ALLPlayer::StartSparring()
{
	sparring = true;
	StopSprint();
	GetCharacterMovement()->MaxWalkSpeed = sparringSpeed;
	GetCharacterMovement()->bOrientRotationToMovement = false;
}

void ALLPlayer::StopSparring()
{
	sparring = false;
	if (!attacking) 
	{
		if (!sprinting)
			GetCharacterMovement()->MaxWalkSpeed = normalSpeed;

		bUseControllerRotationYaw = false;
		sensitivity = normalSensitivity;

		GetCharacterMovement()->bOrientRotationToMovement = true;
	}
}

void ALLPlayer::Rolling()
{
	FVector rollDirection = GetLastMovementInputVector();

	if (rolling == false && !rollDirection.IsZero())
	{
		FRotator MovementRotation = rollDirection.Rotation();
		SetActorRotation(MovementRotation);

		StopSprint();
		StopSparring();
		rolling = true;
	}
}

void ALLPlayer::Attack()
{
	if (sparring && !attacking) 
	{
		attacking = true;
		GetCharacterMovement()->MaxWalkSpeed = 0;
	}		
}

void ALLPlayer::TakeDamage()
{
	PlayAnimMontage(damageMontage, 1.f, FName("Default"));
}

void ALLPlayer::SetNormalSpeed()
{
	if (!sparring) 
	{
		GetCharacterMovement()->MaxWalkSpeed = normalSpeed;
		StopSparring();
	}
		
	else
		GetCharacterMovement()->MaxWalkSpeed = sparringSpeed;
}

void ALLPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckSprint(actualVerticalAxis, actualHorizontalAxis);

	if (sparring && !rolling)
	{
		sensitivity = sparringSensitivity;
		bUseControllerRotationYaw = true;
		float NewFOV = FMath::FInterpTo(playerCamera->GetFOVAngle(), sparringFOV, DeltaTime, fovChangeSpeed);
		playerCamera->SetFOV(NewFOV);
	}

	if (!sparring || rolling)
	{
		float NewFOV = FMath::FInterpTo(playerCamera->GetFOVAngle(), normalFOV, DeltaTime, fovChangeSpeed);
		playerCamera->SetFOV(NewFOV);
	}
}

void ALLPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}