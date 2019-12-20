// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TransitionsEnum.h"
#include "Tweener.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTweener, Log, All);

class Tween
{
public:
	float* Var;
	float From, To, Duration, By, UseBezier;
	ETransitionsEnum EaseFunction;
	FDateTime Timestamp;
};

DECLARE_DYNAMIC_DELEGATE(FTweenCompletedCallback);

UCLASS()
class ATweener : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ATweener();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Numerical Tweener", meta = (AutoCreateRefTerm = "Callback", Keywords = "Add Tween"))
	void AddTween(UPARAM(ref)float& Var, float To, float Time, const FTweenCompletedCallback& Callback);

	UFUNCTION(BlueprintCallable, Category = "Numerical Tweener", meta = (AutoCreateRefTerm = "Callback", Keywords = "Add Ease Tween"))
	void AddEaseTween(UPARAM(ref)float& Var, float To, float Time, ETransitionsEnum Transition, const FTweenCompletedCallback& Callback);

	UFUNCTION(BlueprintCallable, Category = "Numerical Tweener", meta = (AutoCreateRefTerm = "Callback", Keywords = "Add Delay Tween"))
	void AddDelayTween(UPARAM(ref)float& Var, float To, float Time, ETransitionsEnum Transition, float Delay, const FTweenCompletedCallback& Callback);

	UFUNCTION(BlueprintCallable, Category = "Numerical Tweener",  meta = (AutoCreateRefTerm = "Callback", Keywords = "Add Bezier Tween"))
	void AddBezierTween(UPARAM(ref)float& Var, float To, float Time, ETransitionsEnum Transition, float Delay, float BezierPoint, const FTweenCompletedCallback& Callback);

	UFUNCTION(BlueprintCallable, Category = "Numerical Tweener")
	void RemoveTween(UPARAM(ref)float& Var);

	UFUNCTION(BlueprintCallable, Category = "Numerical Tweener")
	void SetTimeScale(float Scale);

	UFUNCTION(BlueprintCallable, Category = "Numerical Tweener")
	void RemoveAllTweens();

	UFUNCTION(BlueprintCallable, Category = "Numerical Tweener")
	int32 GetTweenCount();

private:
	UFUNCTION(meta = (AutoCreateRefTerm = "Callback"))
	void AddTweenFull(UPARAM(ref)float& Var, float To, float Time, ETransitionsEnum Transition, float Delay, float BezierPoint, bool bUseBezier, const FTweenCompletedCallback& Callback);

	static float Bezier(float b, float e, float t, float p);

private:
	TArray<Tween>	Tweens_;
	float			Scale_;
	// TODO: Set mode by enum
	bool			bOverride_;
	TMap<float*, FTweenCompletedCallback> Callbacks_;
};
