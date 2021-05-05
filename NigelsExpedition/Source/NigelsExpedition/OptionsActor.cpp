// Fill out your copyright notice in the Description page of Project Settings.

#include "OptionsActor.h"
#include "Components/BoxComponent.h"

// Sets default values
AOptionsActor::AOptionsActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	BoxComponent->InitBoxExtent(FVector(100, 100, 100));
	BoxComponent->SetCollisionProfileName(TEXT("Trigger"));
	BoxComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);

	RootComponent = BoxComponent;
}

// Called when the game starts or when spawned
void AOptionsActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOptionsActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

