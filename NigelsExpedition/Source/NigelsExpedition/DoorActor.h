// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundCue.h"
#include "Components/StaticMeshComponent.h"
#include "DoorActor.generated.h"

UCLASS()
class NIGELSEXPEDITION_API ADoorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoorActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Actor components
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* HandMeshComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		class USphereComponent* LightSphere;

	// Function for exit from game
	UFUNCTION(BlueprintCallable, Category = "Components")
		void ExitGame();


	UPROPERTY(EditAnywhere, Category = "Music")
		UAudioComponent* Background;
	UPROPERTY(EditAnywhere, Category = "Sound effects")
		UAudioComponent* DoorOpening;
	UPROPERTY(EditAnywhere, Category = "Sound effects")
		UAudioComponent* Torch;
};
