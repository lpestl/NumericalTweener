// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Transitions.h"
#include "Tweener.generated.h"


UENUM(BlueprintType)
enum class ETransitionsEnum : uint8
{
	TE_Linear 			UMETA(DisplayName = "Linear"),

	TE_EaseInSine 		UMETA(DisplayName = "EaseInSine"),
	TE_EaseOutSine		UMETA(DisplayName = "EaseOutSine"),
	TE_EaseInOutSine	UMETA(DisplayName = "EaseInOutSine"),

	TE_EaseInCubic		UMETA(DisplayName = "EaseInCubic"),
	TE_EaseOutCubic		UMETA(DisplayName = "EaseOutCubic"),
	TE_EaseInOutCubic	UMETA(DisplayName = "EaseInOutCubic"),

	TE_EaseInQuint		UMETA(DisplayName = "EaseInQuint"),
	TE_EaseOutQuint		UMETA(DisplayName = "EaseOutQuint"),
	TE_EaseInOutQuint	UMETA(DisplayName = "EaseInOutQuint"),

	TE_EaseInCirc		UMETA(DisplayName = "EaseInCirc"),
	TE_EaseOutCirc		UMETA(DisplayName = "EaseOutCirc"),
	TE_EaseInOutCirc	UMETA(DisplayName = "EaseInOutCirc"),

	TE_EaseInBack		UMETA(DisplayName = "EaseInBack"),
	TE_EaseOutBack		UMETA(DisplayName = "EaseOutBack"),
	TE_EaseInOutBack	UMETA(DisplayName = "EaseInOutBack"),

	TE_EaseInQuad		UMETA(DisplayName = "EaseInQuad"),
	TE_EaseOutQuad		UMETA(DisplayName = "EaseOutQuad"),
	TE_EaseInOutQuad	UMETA(DisplayName = "EaseInOutQuad"),

	TE_EaseInQuart		UMETA(DisplayName = "EaseInQuart"),
	TE_EaseOutQuart		UMETA(DisplayName = "EaseOutQuart"),
	TE_EaseInOutQuart	UMETA(DisplayName = "EaseInOutQuart"),

	TE_EaseInExpo		UMETA(DisplayName = "EaseInExpo"),
	TE_EaseOutExpo		UMETA(DisplayName = "EaseOutExpo"),
	TE_EaseInOutExpo	UMETA(DisplayName = "EaseInOutExpo"),

	TE_EaseInElastic	UMETA(DisplayName = "EaseInElastic"),
	TE_EaseOutElastic	UMETA(DisplayName = "EaseOutElastic"),
	TE_EaseInOutElastic	UMETA(DisplayName = "EaseInOutElastic"),

	TE_EaseInBounce		UMETA(DisplayName = "EaseInBounce"),
	TE_EaseOutBounce	UMETA(DisplayName = "EaseOutBounce"),
	TE_EaseInOutBounce	UMETA(DisplayName = "EaseInOutBounce")
};


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
	void AddTween(float& var, float to, float time, ETransitionsEnum transition /*need callback*/);
	UFUNCTION(BlueprintCallable, Category = "Numerical Tweener")
	void AddTween(float& var, float to, float time, ETransitionsEnum transition, float delay /*need callback*/);
	UFUNCTION(BlueprintCallable, Category = "Numerical Tweener")
	void AddTween(float& var, float to, float time, ETransitionsEnum transition, float delay, float bezierPoint /*need callback*/);

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
	void	AddTween(float &var, float to, float time, ETransitionsEnum transition, float delay, float bezierPoint, bool useBezier /*, FTweenComplete OnTweenComplete*/);

	UFUNCTION()
	float	Bezier(float b, float e, float t, float p);

private:
	float			scale;
	bool			bOverride = true;
	TArray<Tween>	tweens;
	//TMap<float*, FTweenComplete> callbacks;
};
