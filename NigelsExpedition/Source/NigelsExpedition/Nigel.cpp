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


	static ConstructorHelpers::FObjectFinder<USoundCue> Saving_Cue(TEXT("/Game/Sounds/Levels/Saving_Cue.Saving_Cue"));

	Saving = CreateDefaultSubobject<UAudioComponent>(TEXT("Saving"));
	Saving->Activate();
	Saving->SetSound(Saving_Cue.Object);

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
	//GetCharacterMovement()->MaxWalkSpeed = 10.f;

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
	//bNAmericaArtifact = false;


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


	PrimaryActorTick.bTickEvenWhenPaused = true;

	//
	IsPushing = false;

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

	if (MapMenuWidgetClass)
	{
		MapWidget = CreateWidget<UUserWidget>(GetWorld(), MapMenuWidgetClass);
		if (MapWidget)
		{
			MapWidget->AddToViewport();
		}
	}

	if (ArtifactMenuWidgetClass)
	{
		ArtifactWidget = CreateWidget<UUserWidget>(GetWorld(), ArtifactMenuWidgetClass);

		if (ArtifactWidget)
		{
			ArtifactWidget->AddToViewport();
		}
	}

	if(DialogMenuWidgetClass)
	{
		DialogMenuWidget = CreateWidget<UUserWidget>(GetWorld(), DialogMenuWidgetClass);

		if(DialogMenuWidget)
		{
			DialogMenuWidget->AddToViewport();
		}
	}

	if(DialogFirstLocWidgetClass)
	{
		DialogFirstLocWidget = CreateWidget<UUserWidget>(GetWorld(), DialogFirstLocWidgetClass);

		if(DialogFirstLocWidget)
		{
			DialogFirstLocWidget->AddToViewport();
		}
	}
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ANigel::OnOverlapBegin);


	//Load game from game save instance
	LoadGame();

	if (UGameplayStatics::GetCurrentLevelName(this) == "MenuMap"){
		this->SetActorLocation(FVector(72.f, 50.f, 200.f));

		//Log a message
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("MenuMap"));

		if(bCkeckFirstTimeMenuLvl){
			DialogMenuWidget->SetVisibility(ESlateVisibility::Visible);

			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Check widget"));

		}
	}
	if(UGameplayStatics::GetCurrentLevelName(this) == "FirstLocations" && bCheckFirstTimeFLocation){
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Check widget"));
		DialogFirstLocWidget->SetVisibility(ESlateVisibility::Visible);

		
	}
	if (bNAmericaArtifact) {
		//Set first artifact visible(hide foreground layout)
		ArtifactWidget->GetWidgetFromName("ImageFirstBlack")->SetVisibility(ESlateVisibility::Hidden);
	}

}

// Called every frame
void ANigel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(DialogMenuWidget->Visibility == ESlateVisibility::Visible && DialogMenuWidget->GetWidgetFromName("text1")->Visibility == ESlateVisibility::Visible){
		//Set game pause
		//UGameplayStatics::SetGamePaused(GetWorld(), true);

		bDead = true;
	}

	if(DialogFirstLocWidget->Visibility == ESlateVisibility::Visible && DialogFirstLocWidget->GetWidgetFromName("textFloc1")->Visibility == ESlateVisibility::Visible){
		//Set game pause
		//UGameplayStatics::SetGamePaused(GetWorld(), true);

		bDead = true;
	}
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

	PlayerInputComponent->BindAction("ActionEnter", IE_Released, this, &ANigel::OnActionEnter).bExecuteWhenPaused = true;

	//Temporary key actions
	PlayerInputComponent->BindAction("ActionEsc", IE_Released, this, &ANigel::OnActionEsc).bExecuteWhenPaused = true;
	PlayerInputComponent->BindAction("ActionX", IE_Released, this, &ANigel::OnActionX);

	//Jumping
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

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

	if (MapLevels)
	{
		//Set map widget visible
		MapWidget->SetVisibility(ESlateVisibility::Visible);

		//Player controller
		APlayerController* MyController = GetWorld()->GetFirstPlayerController();

		//Set mouse events enable
		MyController->bShowMouseCursor = true;
		MyController->bEnableClickEvents = true;
		MyController->bEnableMouseOverEvents = true;

		//Set game pause
		UGameplayStatics::SetGamePaused(GetWorld(), true);
	}
	if (Artifacts)
	{
		//Set visible widget with artifacts
		ArtifactWidget->SetVisibility(ESlateVisibility::Visible);

		//Player controller
		APlayerController* MyController = GetWorld()->GetFirstPlayerController();

		//Set mouse events enable
		MyController->bEnableClickEvents = true;
		MyController->bEnableMouseOverEvents = true;

		//Set game pause
		UGameplayStatics::SetGamePaused(GetWorld(), true);
	}
}

void ANigel::OnActionEsc() {

	if (MapWidget->Visibility == ESlateVisibility::Visible) {

		//Set Map widget hidden   
		MapWidget->SetVisibility(ESlateVisibility::Hidden);

		//Player controller
		APlayerController* MyController = GetWorld()->GetFirstPlayerController();

		//Setting mouse events disable
		MyController->bShowMouseCursor = false;
		MyController->bEnableClickEvents = false;
		MyController->bEnableMouseOverEvents = false;

		//Set pause false
		UGameplayStatics::SetGamePaused(GetWorld(), false);

		MapLevels->LoadLevel();
	}

	if (ArtifactWidget->Visibility == ESlateVisibility::Visible)
	{
		//Set Artifact widget hidden   
		ArtifactWidget->SetVisibility(ESlateVisibility::Hidden);

		//Player controller
		APlayerController* MyController = GetWorld()->GetFirstPlayerController();

		//Setting mouse events disable
		MyController->bEnableClickEvents = false;
		MyController->bEnableMouseOverEvents = false;

		//Set pause false
		UGameplayStatics::SetGamePaused(GetWorld(), false);
	}

	// if(DialogMenuWidget->Visibility == ESlateVisibility::Visible){
	// 	DialogMenuWidget->SetVisibility(ESlateVisibility::Hidden);
	// }
}

//temporary method to load main manu by x key
void ANigel::OnActionX()
{
	GetWorld()->ServerTravel(FString("/Game/Maps/MainMenu/MenuMap"));
}

void ANigel::OnActionEnter(){
	if(DialogMenuWidget->GetWidgetFromName("text1")->Visibility == ESlateVisibility::Visible){
		DialogMenuWidget->GetWidgetFromName("text1")->SetVisibility(ESlateVisibility::Hidden);
		DialogMenuWidget->GetWidgetFromName("text2")->SetVisibility(ESlateVisibility::Visible);
	}
	else if(DialogMenuWidget->GetWidgetFromName("text2")->Visibility == ESlateVisibility::Visible){
		DialogMenuWidget->GetWidgetFromName("text2")->SetVisibility(ESlateVisibility::Hidden);
		DialogMenuWidget->GetWidgetFromName("text3")->SetVisibility(ESlateVisibility::Visible);
	}
	else if(DialogMenuWidget->GetWidgetFromName("text3")->Visibility == ESlateVisibility::Visible){
		DialogMenuWidget->GetWidgetFromName("text3")->SetVisibility(ESlateVisibility::Hidden);
		DialogMenuWidget->GetWidgetFromName("text4")->SetVisibility(ESlateVisibility::Visible);
	}
	else if(DialogMenuWidget->GetWidgetFromName("text4")->Visibility == ESlateVisibility::Visible){
		DialogMenuWidget->GetWidgetFromName("text4")->SetVisibility(ESlateVisibility::Hidden);
		DialogMenuWidget->GetWidgetFromName("text5")->SetVisibility(ESlateVisibility::Visible);
	}
	else if(DialogMenuWidget->GetWidgetFromName("text5")->Visibility == ESlateVisibility::Visible){
		DialogMenuWidget->SetVisibility(ESlateVisibility::Hidden);

		//Set pause false
		//UGameplayStatics::SetGamePaused(GetWorld(), false);

		bCkeckFirstTimeMenuLvl = false;
		SaveGame();

		bDead = false;
	}

	if(DialogFirstLocWidget->GetWidgetFromName("textFloc1")->Visibility == ESlateVisibility::Visible){
		DialogFirstLocWidget->GetWidgetFromName("textFloc1")->SetVisibility(ESlateVisibility::Hidden);
		DialogFirstLocWidget->GetWidgetFromName("textFloc2")->SetVisibility(ESlateVisibility::Visible);
	}
	else if(DialogFirstLocWidget->GetWidgetFromName("textFloc2")->Visibility == ESlateVisibility::Visible){
		DialogFirstLocWidget->GetWidgetFromName("textFloc2")->SetVisibility(ESlateVisibility::Hidden);
		DialogFirstLocWidget->GetWidgetFromName("textFloc3")->SetVisibility(ESlateVisibility::Visible);
	}
	else if(DialogFirstLocWidget->GetWidgetFromName("textFloc3")->Visibility == ESlateVisibility::Visible){
		DialogFirstLocWidget->GetWidgetFromName("textFloc3")->SetVisibility(ESlateVisibility::Hidden);
		DialogFirstLocWidget->GetWidgetFromName("textFloc4")->SetVisibility(ESlateVisibility::Visible);
	}
	else if(DialogFirstLocWidget->GetWidgetFromName("textFloc4")->Visibility == ESlateVisibility::Visible){
		DialogFirstLocWidget->GetWidgetFromName("textFloc4")->SetVisibility(ESlateVisibility::Hidden);
		DialogFirstLocWidget->GetWidgetFromName("textFloc5")->SetVisibility(ESlateVisibility::Visible);
	}
	else if(DialogFirstLocWidget->GetWidgetFromName("textFloc5")->Visibility == ESlateVisibility::Visible){
		DialogFirstLocWidget->SetVisibility(ESlateVisibility::Hidden);

		bCheckFirstTimeFLocation = false;
		SaveGame();

		bDead = false;
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

	if (OtherActor && OtherActor != this && OtherComp && OtherActor->GetClass()->IsChildOf(AArtifactActor::StaticClass()) && ArtifactWidget->Visibility == ESlateVisibility::Visible)
	{
		DoorWidget->GetWidgetFromName("text_artifacts")->SetVisibility(ESlateVisibility::Hidden);
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

	//check if on actor is NAmerica Artifact
	if (OtherActor->ActorHasTag("NAmericaArtifact"))
	{
		//Destroy actor after pickup and set visible in widget  
		bNAmericaArtifact = true;
		OtherActor->Destroy();
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

	Saving->Play();

	//Create an instance of GameSave class
	UGameSave* GameSaveInstance = Cast<UGameSave>(UGameplayStatics::CreateSaveGameObject(UGameSave::StaticClass()));

	if(UGameplayStatics::GetCurrentLevelName(this) != "MenuMap")
	{
		//Set the save game instance location equal to the players current location
		GameSaveInstance->PlayerLocation = this->GetActorLocation();

		//Set after checkpoint if artifact is pick
		GameSaveInstance->isNAmericaArtifact = this->bNAmericaArtifact;

		GameSaveInstance->isFirstTimeFLocation = true;
	}
	//Set false after first time game
	GameSaveInstance->isFirstTimeMenuMap = this->bCkeckFirstTimeMenuLvl;
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
	GameSaveInstance = Cast<UGameSave>(UGameplayStatics::LoadGameFromSlot("FirstSlot", 0));

	//Set player location to loaded location from save game instance
	this->SetActorLocation(GameSaveInstance->PlayerLocation);

	//Set for player is artifact picked
	this->bNAmericaArtifact = GameSaveInstance->isNAmericaArtifact;

	//Set first time game in game instance
	this->bCkeckFirstTimeMenuLvl = GameSaveInstance->isFirstTimeMenuMap;

	this->bCheckFirstTimeFLocation = true;

	//Log a message
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Loaded"));
}