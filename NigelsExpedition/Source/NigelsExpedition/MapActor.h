// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MapActor.generated.h"

UCLASS()
class NIGELSEXPEDITION_API AMapActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMapActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Components in actor
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* MapMeshComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		class UBoxComponent* BoxComponent;

	// Function to load level
	UFUNCTION(BlueprintCallable, Category = "Components")
		void LoadLevel();
};
