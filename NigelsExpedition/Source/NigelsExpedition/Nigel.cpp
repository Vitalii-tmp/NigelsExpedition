// Fill out your copyright notice in the Description page of Project Settings.

#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Purple, text)
#define printFString(text, fstring) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Purple, FString::Printf(Text(text), fstring ))


#include "Nigel.h"
#include "MapActor.h"
#include "DoorActor.h"
#include "ArtifactActor.h"
#include "OptionsActor.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "GameSave.h"

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

	//Trigger Capsule size, add to root
	TriggerCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger Capsule"));
	TriggerCapsule->InitCapsuleSize(42.f, 96.f);
	TriggerCapsule->SetCollisionProfileName(TEXT("Trigger"));
	TriggerCapsule->SetupAttachment(RootComponent);

	//Functions
	TriggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &ANigel::OnOverlapBegin);
	TriggerCapsule->OnComponentEndOverlap.AddDynamic(this, &ANigel::OnOverlapEnd);

	//Actors
	DoorExit = NULL;
	MapLevels = NULL;
	Artifacts = NULL;
	Options = NULL;
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


	//Adding widgets to viewport
	if (HelpWidgetClass)
	{
		DoorWidget = CreateWidget<UUserWidget>(GetWorld(), HelpWidgetClass);

		if (DoorWidget)
		{
			DoorWidget->AddToViewport();
		}

	}

	if(MapMenuWidgetClass)
	{
		MapWidget = CreateWidget<UUserWidget>(GetWorld(), MapMenuWidgetClass);;
		if(MapWidget)
		{
			MapWidget->AddToViewport();
		}
	}

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ANigel::OnOverlapBegin);


	//Load game from game save instance
	LoadGame();
	
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

	//E key(using in main menu)
	PlayerInputComponent->BindAction("ActionE", IE_Released, this, &ANigel::OnAction);

	//Jumping
	//PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	//PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	//Moving forward
	PlayerInputComponent->BindAxis("MoveForward", this, &ANigel::MoveForward);

	//Moving right
	PlayerInputComponent->BindAxis("MoveRight", this, &ANigel::MoveRight);
}

// Called when pressed E key
void ANigel::OnAction()
{
	//Checked if actor is existing 
	if (DoorExit)
	{
		//Function for exit
		DoorExit->ExitGame();
	}

	if(MapLevels)
	{
		//Set map widget visible
		MapWidget->GetWidgetFromName("Image_map")->SetVisibility(ESlateVisibility::Visible);
		APlayerController* MyController = GetWorld()->GetFirstPlayerController();

		MyController->bShowMouseCursor = true;
		MyController->bEnableClickEvents = true;
		MyController->bEnableMouseOverEvents = true;

		UGameplayStatics::SetGamePaused(GetWorld(), true);
	}
}

void ANigel::RestartLvl()
{
	//reload current lvl
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName(), false));
}

//Called when trigger capsule is on actor
void ANigel::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Check actor and depend on this set visible some text and set actor not null
	if (OtherActor && OtherActor != this && OtherComp && OtherActor->GetClass()->IsChildOf(ADoorActor::StaticClass()))
	{
		DoorExit = Cast<ADoorActor>(OtherActor);

		DoorWidget->GetWidgetFromName("text_door")->SetVisibility(ESlateVisibility::Visible);
	}

	if (OtherActor && OtherActor != this && OtherComp && OtherActor->GetClass()->IsChildOf(AMapActor::StaticClass()))
	{
		MapLevels = Cast<AMapActor>(OtherActor);

		DoorWidget->GetWidgetFromName("text_map")->SetVisibility(ESlateVisibility::Visible);
	}

	if (OtherActor && OtherActor != this && OtherComp && OtherActor->GetClass()->IsChildOf(AArtifactActor::StaticClass()))
	{
		Artifacts = Cast<AArtifactActor>(OtherActor);

		DoorWidget->GetWidgetFromName("text_artifacts")->SetVisibility(ESlateVisibility::Visible);
	}

	if (OtherActor && OtherActor != this && OtherComp && OtherActor->GetClass()->IsChildOf(AOptionsActor::StaticClass()))
	{
		Options = Cast<AOptionsActor>(OtherActor);
		
		DoorWidget->GetWidgetFromName("text_options")->SetVisibility(ESlateVisibility::Visible);
	}

	if (OtherActor->ActorHasTag("DieSpace"))
	{
		UE_LOG(LogTemp, Warning, TEXT("DieSpace"));
		bDead = true;

		GetMesh()->SetSimulatePhysics(true);

		

		//Restart game but before wait 4s
		FTimerHandle UnsedHandle;
		GetWorldTimerManager().SetTimer(
			UnsedHandle, this, &ANigel::RestartLvl, 2.0f, false);
		
	}

	if (OtherActor->ActorHasTag("CheckPoint"))
	{
		SaveGame();
	}
}

//Called when trigger capsule go from actor
void ANigel::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{	
	if (OtherActor && OtherActor != this && OtherComp)
	{
		//set actors null
		DoorExit = NULL;
		MapLevels = NULL;
		Artifacts = NULL;
		Options = NULL;

		//set all widget hidden
		DoorWidget->GetWidgetFromName("text_door")->SetVisibility(ESlateVisibility::Hidden);
		DoorWidget->GetWidgetFromName("text_map")->SetVisibility(ESlateVisibility::Hidden);
		DoorWidget->GetWidgetFromName("text_options")->SetVisibility(ESlateVisibility::Hidden);
		DoorWidget->GetWidgetFromName("text_artifacts")->SetVisibility(ESlateVisibility::Hidden);
	}

	
}


void ANigel::SaveGame()
{
	//Create an instance of GameSave class
	UGameSave* GameSaveInstance = Cast<UGameSave>(UGameplayStatics::CreateSaveGameObject(UGameSave::StaticClass()));

	//Set the save game instance location equal to the players current location
	GameSaveInstance->PlayerLocation = this->GetActorLocation();

	//Save the game save instance
	UGameplayStatics::SaveGameToSlot(GameSaveInstance, TEXT("FirstSlot"), 0);

	//Log a message
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Saved"));
}

void ANigel::LoadGame()
{
	//Create an instance of GameSave class
	UGameSave* GameSaveInstance = Cast<UGameSave>(UGameplayStatics::CreateSaveGameObject(UGameSave::StaticClass()));

	//Load the saved game into our save game instance
	GameSaveInstance = Cast<UGameSave>(UGameplayStatics::LoadGameFromSlot("FirstSlot",0));

	//Set player location to loaded location from save game instance
	this->SetActorLocation(GameSaveInstance->PlayerLocation);

	//Log a message
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Loaded"));
}