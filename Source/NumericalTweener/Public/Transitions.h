// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Transitions.generated.h"

/**
 * 
 */
UCLASS()
class NUMERICALTWEENER_API UTransitions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Linear", Keywords = "Tweener Ease linear"), Category = "Numerical Tweener")
	static float linear(float t, float b, float c, float d);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInSine", Keywords = "Tweener Ease In Sine"), Category = "Numerical Tweener")
	static float easeInSine(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseOutSine", Keywords = "Tweener Ease Out Sine"), Category = "Numerical Tweener")
	static float easeOutSine(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInOutSine", Keywords = "Tweener Ease In Out Sine"), Category = "Numerical Tweener")
	static float easeInOutSine(float t, float b, float c, float d);

	// TODO: Added UF meta

	static float easeInCubic(float t, float b, float c, float d);
	static float easeOutCubic(float t, float b, float c, float d);
	static float easeInOutCubic(float t, float b, float c, float d);
	
	static float easeInQuint(float t, float b, float c, float d);
	static float easeOutQuint(float t, float b, float c, float d);
	static float easeInOutQuint(float t, float b, float c, float d);
	
	static float easeInCirc(float t, float b, float c, float d);
	static float easeOutCirc(float t, float b, float c, float d);
	static float easeInOutCirc(float t, float b, float c, float d);
	
	static float easeInBack(float t, float b, float c, float d);
	static float easeOutBack(float t, float b, float c, float d);
	static float easeInOutBack(float t, float b, float c, float d);
	
	static float easeInQuad(float t, float b, float c, float d);
	static float easeOutQuad(float t, float b, float c, float d);
	static float easeInOutQuad(float t, float b, float c, float d);
	
	static float easeInQuart(float t, float b, float c, float d);
	static float easeOutQuart(float t, float b, float c, float d);
	static float easeInOutQuart(float t, float b, float c, float d);
	
	static float easeInExpo(float t, float b, float c, float d);
	static float easeOutExpo(float t, float b, float c, float d);
	static float easeInOutExpo(float t, float b, float c, float d);
	
	static float easeInElastic(float t, float b, float c, float d);
	static float easeOutElastic(float t, float b, float c, float d);
	static float easeInOutElastic(float t, float b, float c, float d);

	static float easeInBounce(float t, float b, float c, float d);
	static float easeOutBounce(float t, float b, float c, float d);
	static float easeInOutBounce(float t, float b, float c, float d);
};