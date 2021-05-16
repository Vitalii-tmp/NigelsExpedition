// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSave.h"
#include "NigelsExpedition.h"

UGameSave::UGameSave()
{
	PlayerLocation = FVector(0.f, 0.f, 0.f);
	isNAmericaArtifact = false;
	isFirstTimeMenuMap = true;
}


