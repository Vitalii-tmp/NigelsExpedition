// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Nigel.h"
#include "LevelSequence/Public/LevelSequenceActor.h"
#include "LevelSequence/Public/LevelSequencePlayer.h"
#include "BoxTrigger.generated.h"

/**
 * 
 */
UCLASS()
class NIGELSEXPEDITION_API ABoxTrigger : public ATriggerBox
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;



public:

	ABoxTrigger();


	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

	//UFUNCTION()
	//	void PlayAnimation(class AActor* OverlappedActor, class AActor* OtherActor);

	UPROPERTY(EditAnywhere, Category = "Animation")
		ALevelSequenceActor* LevelSequence;
};
