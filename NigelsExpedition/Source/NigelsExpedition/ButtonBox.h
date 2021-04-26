// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ButtonBox.generated.h"

UCLASS()
class NIGELSEXPEDITION_API AButtonBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AButtonBox();

	UPROPERTY(EditAnywhere, Category = "Components")
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = "Components")
		UBoxComponent* Box;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
