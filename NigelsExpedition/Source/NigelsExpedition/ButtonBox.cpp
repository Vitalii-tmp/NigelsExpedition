// Fill out your copyright notice in the Description page of Project Settings.


#include "ButtonBox.h"
#include "Nigel.h"
// Sets default values
AButtonBox::AButtonBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create Mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	Mesh->SetEnableGravity(true);
	Mesh->SetSimulatePhysics(true);
	RootComponent = Mesh;

	//Create trigger
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Box->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Box->SetCollisionResponseToAllChannels((ECR_Block));
	Box->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	Box->SetupAttachment(Mesh);
	Box->SetHiddenInGame(false);
		
	
}

// Called when the game starts or when spawned
void AButtonBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AButtonBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AButtonBox::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	ANigel* Nigel = Cast<ANigel>(OtherActor);

	if(Nigel)
	{
		Destroy();

		
	}
}