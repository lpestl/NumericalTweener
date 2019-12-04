// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TransitionsEnum.h"
#include "Tweener.generated.h"

class Tween
{
public:
	float* var;
	float from, to, duration, by, useBezier;
	ETransitionsEnum easeFunction;
	FDateTime timestamp;
};


UCLASS()
class NUMERICALTWEENER_API ATweener : public AActor
{
	GENERATED_BODY()

	//TODO: Throw it to map and call callbacks
	//DECLARE_DYNAMIC_DELEGATE_OneParam(FTweenComplete, float*, SourceValuePtr)
public:	
	// Sets default values for this actor's properties
	ATweener();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Numerical Tweener")
	void AddTween(float& var, float to, float time /*need callback*/);

	UFUNCTION(BlueprintCallable, Category = "Numerical Tweener")
	void AddTweenWithEase(float& var, float to, float time, ETransitionsEnum transition /*need callback*/);

	UFUNCTION(BlueprintCallable, Category = "Numerical Tweener")
	void AddTweenWithDelay(float& var, float to, float time, ETransitionsEnum transition, float delay /*need callback*/);

	//UFUNCTION(BlueprintCallable, Category = "Numerical Tweener")
	//void AddTween(float& var, float to, float time, ETransitionsEnum transition, float delay, float bezierPoint /*need callback*/);

	UFUNCTION(BlueprintCallable, Category = "Numerical Tweener")
	void RemoveTween(float& var);

	UFUNCTION(BlueprintCallable, Category = "Numerical Tweener")
	void SetTimeScale(float scale);

	UFUNCTION(BlueprintCallable, Category = "Numerical Tweener")
	void RemoveAllTweens();

	UFUNCTION(BlueprintCallable, Category = "Numerical Tweener")
	int32 GetTweenCount();

private:
	UFUNCTION()
	void AddTweenFull(float& var, float to, float time, ETransitionsEnum transition, float delay, float bezierPoint, bool useBezier /*, FTweenComplete OnTweenComplete*/);

	UFUNCTION()
	float Bezier(float b, float e, float t, float p);

private:
	TArray<Tween>	Tweens;
	float			Scale;
	bool			bOverride = true;
	//TMap<float*, FTweenComplete> callbacks;
};
