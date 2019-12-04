// Fill out your copyright notice in the Description page of Project Settings.


#include "Tweener.h"

// Sets default values
ATweener::ATweener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATweener::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATweener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATweener::AddTween(float& var, float to, float time)
{
}

void ATweener::AddTween(float& var, float to, float time, ETransitionsEnum transition)
{
}

void ATweener::AddTween(float& var, float to, float time, ETransitionsEnum transition, float delay)
{
}

void ATweener::AddTween(float& var, float to, float time, ETransitionsEnum transition, float delay, float bezierPoint)
{
}

void ATweener::RemoveTween(float& var)
{
}

void ATweener::SetTimeScale(float scale)
{
}

void ATweener::RemoveAllTweens()
{
}

int32 ATweener::GetTweenCount()
{
	return 0;
}

void ATweener::AddTween(float& var, float to, float time, ETransitionsEnum transition, float delay, float bezierPoint,
	bool useBezier)
{
}

float ATweener::Bezier(float b, float e, float t, float p)
{
	return 0.;
}

