// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorActor.h"
#include "Components/SphereComponent.h"

// Sets default values
ADoorActor::ADoorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	
	RootComponent = MeshComponent;

	LightSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Light Sphere Camp"));
	LightSphere->InitSphereRadius(20.f);
	LightSphere->SetCollisionProfileName(TEXT("Trigger"));
	LightSphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	LightSphere->SetupAttachment(RootComponent);

	HandMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Hand"));
	HandMeshComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ADoorActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ADoorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called when player press e to exit from game
void ADoorActor::ExitGame()
{
	FGenericPlatformMisc::RequestExit(true);
}