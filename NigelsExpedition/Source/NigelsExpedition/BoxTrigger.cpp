// Fill out your copyright notice in the Description page of Project Settings.

#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1,1.5, FColor::Green, text);
#define printFstring(text, fstring) if(GEngine) GEngine->AddOnScreenDebugMessage(-1,1.5,FColor::Green, FString::Prinf(Text(text), fstring);


#include "BoxTrigger.h"
#include "DrawDebugHelpers.h"


ABoxTrigger::ABoxTrigger()
{
	OnActorBeginOverlap.AddDynamic(this, &ABoxTrigger::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ABoxTrigger::OnOverlapEnd);
}

void ABoxTrigger::OnOverlapBegin(AActor * OverlappedActor, AActor * OtherActor)
{
	if (OtherActor && (OtherActor != this))
	{
		print("Overlap Begin");
		print(*OverlappedActor->GetName());

		if (OtherActor && OtherActor != this)
		{
			ANigel* Character = Cast<ANigel>(GetWorld()->GetFirstPlayerController()->GetCharacter());

			if (Character && LevelSequence)
			{
				if (LevelSequence->SequencePlayer)
				{
					LevelSequence->SequencePlayer->Play();


				}
			}

		}

	}
}

void ABoxTrigger::OnOverlapEnd(AActor * OverlappedActor, AActor * OtherActor)
{
	if (OtherActor && (OtherActor != this))
	{
		print("OverlapEnd");
		print(*OtherActor->GetName());

		if (OtherActor && OtherActor != this)
		{
			ANigel* Character = Cast<ANigel>(GetWorld()->GetFirstPlayerController()->GetCharacter());

			if (Character && LevelSequence)
			{
				if (LevelSequence->SequencePlayer)
				{
					LevelSequence->SequencePlayer->PlayReverse();
				}
			}

		}
	}
}

void ABoxTrigger::BeginPlay()
{
	Super::BeginPlay();

	//	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, -1, 0, 5);

}
