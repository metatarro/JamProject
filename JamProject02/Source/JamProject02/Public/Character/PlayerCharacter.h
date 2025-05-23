// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/HealthComponent.h"

#include "PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class USkeletalMeshComponent;
class UHealthComponent;

struct FInputActionValue;
class UInputMappingContext;
class UInputAction;

UCLASS()
class JAMPROJECT02_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter(const class FObjectInitializer& ObjectInitializer);

	/** Returns ThirdPersonCameraComponent subobject **/
	UCameraComponent* GetTPCComponent() const { return Camera; }

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Defaults | Input")
	UInputAction* Move_Action;

	void Input_Move(const FInputActionValue& InputActionValue);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
	UHealthComponent* HealthComponent;

	virtual void OnDeath(float KillingDamage, FDamageEvent const& DamageEvent, APawn* PawnInstigator, AActor* DamageCauser);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Event for taking damage. Overridden from APawn.*/
	//UFUNCTION(BlueprintCallable, Category = "Health")
	virtual float TakeDamage(float DamageTaken, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UPROPERTY(BlueprintReadOnly)
	bool bIsDying = false;

private:

	UPROPERTY(EditDefaultsOnly, Category = "Defaults | Input")
	UInputMappingContext* InputMappingContext;

};
