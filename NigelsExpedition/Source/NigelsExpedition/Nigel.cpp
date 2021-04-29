// Fill out your copyright notice in the Description page of Project Settings.


#include "Nigel.h"

#include "DoorActor.h"

// Sets default values
ANigel::ANigel()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set capsule size
	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

	//allow camera move
	//bUseControllerRotationPitch = false;
	//bUseControllerRotationYaw = false;
	//bUseControllerRotationRoll = false;

	//Allow character movement to rotate into direction where it is moving
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);

	//Jump velocity
	//GetCharacterMovement()->JumpZVelocity = 600.0f;

	//how we can control player in air
	//GetCharacterMovement()->AirControl = 0.2f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	//Camera distance to player
	CameraBoom->TargetArmLength = 1100.0f;
	CameraBoom->bUsePawnControlRotation = true;

	//CreateCamera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = true;

	bDead = false;

	TriggerCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger Capsule"));
	TriggerCapsule->InitCapsuleSize(42.f, 96.f);
	TriggerCapsule->SetCollisionProfileName(TEXT("Trigger"));
	TriggerCapsule->SetupAttachment(RootComponent);

	TriggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &ANigel::OnOverlapBegin);
	TriggerCapsule->OnComponentEndOverlap.AddDynamic(this, &ANigel::OnOverlapEnd);

	DoorExit = NULL;
}

void ANigel::MoveForward(float Axis)
{
	
	//if player are not dead moving
		if (!bDead)
		{
			const FRotator Rotation = Controller->GetControlRotation();
			const FRotator YawRotation(0, Rotation.Yaw, 0);

			//move forward
			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
			AddMovementInput(Direction, Axis);
		}
	
}

void ANigel::MoveRight(float Axis)
{
	//if player are not dead moving
	if (!bDead)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		//move right
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Axis);
	}
}

// Called when the game starts or when spawned
void ANigel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANigel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANigel::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//camera turning
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("ActionE", IE_Released, this, &ANigel::OnAction);

	//Jumping
	//PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	//PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	//Moving forward
	PlayerInputComponent->BindAxis("MoveForward", this, &ANigel::MoveForward);

	//Moving right
	PlayerInputComponent->BindAxis("MoveRight", this, &ANigel::MoveRight);
}

void ANigel::OnAction()
{
	if (DoorExit)
	{
		DoorExit->ExitGame();
	}
}

void ANigel::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this && OtherComp && OtherActor->GetClass()->IsChildOf(ADoorActor::StaticClass()))
	{
		DoorExit = Cast<ADoorActor>(OtherActor);
	}
}

void ANigel::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	if (OtherActor && OtherActor != this && OtherComp)
	{
		DoorExit = NULL;
	}
}