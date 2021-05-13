// Fill out your copyright notice in the Description page of Project Settings.

#include "MapActor.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMapActor::AMapActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set root component mesh
	MapMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Map"));
	RootComponent = MapMeshComponent;

	//Adding box component
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->InitBoxExtent(FVector(3, 20, 10));
	BoxComponent->SetCollisionProfileName(TEXT("Trigger"));
	BoxComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	BoxComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMapActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMapActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//Called to load level
void AMapActor::LoadLevel()
{
	//UGameplayStatics::OpenLevel(GetWorld(), "Game/Maps/Locations/ThirdPersonExampleMap");
	GetWorld()->ServerTravel(FString("/Game/Maps/Locations/FirstLocations"));
}
