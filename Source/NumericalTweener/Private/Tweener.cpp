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

void ATweener::AddTween(
	float& var, 
	float to, 
	float time, 
	FTweenCompletedCallback callback)
{
}

void ATweener::AddEaseTween(
	float& var, 
	float to, 
	float time, 
	ETransitionsEnum transition,
	FTweenCompletedCallback callback)
{
}

void ATweener::AddDelayTween(
	float& var, 
	float to, 
	float time, 
	ETransitionsEnum transition, 
	float delay,
	FTweenCompletedCallback callback)
{
}

void ATweener::AddBezierTween(
	float& var, 
	float to, 
	float time, 
	ETransitionsEnum transition, 
	float delay,
	float bezierPoint, 
	FTweenCompletedCallback callback)
{
}


void ATweener::RemoveTween(float& var)
{
	// TODO:
}

void ATweener::SetTimeScale(float scale)
{
	// TODO:
}

void ATweener::RemoveAllTweens()
{
	// TODO:
}

int32 ATweener::GetTweenCount()
{
	// TODO:
	return 0;
}

void ATweener::AddTweenFull(
	float& var, 
	float to, 
	float time, 
	ETransitionsEnum transition, 
	float delay,
	float bezierPoint, 
	bool useBezier, 
	FTweenCompletedCallback callback)
{
}

float ATweener::Bezier(float b, float e, float t, float p)
{
	// TODO:
	return 0.;
}

