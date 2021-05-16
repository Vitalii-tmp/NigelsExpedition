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

	// Called when player press key E
	void OnAction();
	void OnActionEsc();
	void OnActionX();
	void OnActionEnter();

	//
	UFUNCTION(BlueprintCallable)
	void RestartLvl();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Function when you on any trigger
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Function when you exit from any trigger
	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);
	

	// Actors for main menu
	class ADoorActor* DoorExit;
	class AMapActor* MapLevels;
	class AArtifactActor* Artifacts;
	class AOptionsActor* Options;

	// Widget for tips
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> HelpWidgetClass;
	class UUserWidget* DoorWidget;

	// Widget for map
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> MapMenuWidgetClass;
	class UUserWidget* MapWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsPushing;

	// Widget for artifacts
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> ArtifactMenuWidgetClass;
	class UUserWidget* ArtifactWidget;

	// Widget for menu dialogs
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> DialogMenuWidgetClass;
	class UUserWidget* DialogMenuWidget;
	
private:
	//dead check
	bool bDead;

	//artifact check
	bool bNAmericaArtifact = false;

	//first time menu map check
	bool bCkeckFirstTimeMenuLvl = false;

	UFUNCTION()
	void SaveGame();

	UFUNCTION()
	void LoadGame();
};
