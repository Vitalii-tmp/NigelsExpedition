// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/BoxComponent.h"
#include "ArtifactActor.h"

// Sets default values
AArtifactActor::AArtifactActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	BoxComponent->InitBoxExtent(FVector(10, 10, 10));
	BoxComponent->SetCollisionProfileName(TEXT("Trigger"));
	BoxComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);

	RootComponent = BoxComponent;
}

// Called when the game starts or when spawned
void AArtifactActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AArtifactActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

