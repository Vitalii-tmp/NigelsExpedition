// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

#include "Blueprint/UserWidget.h"


#include "Nigel.generated.h"

UCLASS()
class NIGELSEXPEDITION_API ANigel : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANigel();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		USpringArmComponent* CameraBoom;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, Category = "Trigger Capsule")
		class UCapsuleComponent* TriggerCapsule;

	void MoveForward(float Axis);
	void MoveRight(float Axis);

	protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void OnAction();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);

	class ADoorActor* DoorExit;
	class AMapActor* MapLevels;
	class AArtifactActor* Artifacts;
	class AOptionsActor* Options;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> HelpWidgetClass;

	// declare widget
	class UUserWidget* DoorWidget;
private:
	//dead check
	bool bDead;
};
