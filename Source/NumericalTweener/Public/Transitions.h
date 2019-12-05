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

public:
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Linear", Keywords = "Tweener Ease linear"), Category = "Numerical Tweener")
	static float linear(float t, float b, float c, float d);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInSine", Keywords = "Tweener Ease In Sine"), Category = "Numerical Tweener")
	static float easeInSine(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseOutSine", Keywords = "Tweener Ease Out Sine"), Category = "Numerical Tweener")
	static float easeOutSine(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInOutSine", Keywords = "Tweener Ease In Out Sine"), Category = "Numerical Tweener")
	static float easeInOutSine(float t, float b, float c, float d);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInCubic", Keywords = "Tweener Ease In Cubic"), Category = "Numerical Tweener")
	static float easeInCubic(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseOutCubic", Keywords = "Tweener Ease Out Cubic"), Category = "Numerical Tweener")
	static float easeOutCubic(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInOutCubic", Keywords = "Tweener Ease In Out Cubic"), Category = "Numerical Tweener")
	static float easeInOutCubic(float t, float b, float c, float d);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInQuint", Keywords = "Tweener Ease In Quint"), Category = "Numerical Tweener")
	static float easeInQuint(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseOutQuint", Keywords = "Tweener Ease Out Quint"), Category = "Numerical Tweener")
	static float easeOutQuint(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInOutQuint", Keywords = "Tweener Ease In Out Quint"), Category = "Numerical Tweener")
	static float easeInOutQuint(float t, float b, float c, float d);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInCirc", Keywords = "Tweener Ease In Circ"), Category = "Numerical Tweener")
	static float easeInCirc(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseOutCirc", Keywords = "Tweener Ease Out Circ"), Category = "Numerical Tweener")
	static float easeOutCirc(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInOutCirc", Keywords = "Tweener Ease In Out Circ"), Category = "Numerical Tweener")
	static float easeInOutCirc(float t, float b, float c, float d);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInBack", Keywords = "Tweener Ease In Back"), Category = "Numerical Tweener")
	static float easeInBack(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseOutBack", Keywords = "Tweener Ease Out Back"), Category = "Numerical Tweener")
	static float easeOutBack(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInOutBack", Keywords = "Tweener Ease In Out Back"), Category = "Numerical Tweener")
	static float easeInOutBack(float t, float b, float c, float d);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInQuad", Keywords = "Tweener Ease In Quad"), Category = "Numerical Tweener")
	static float easeInQuad(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseOutQuad", Keywords = "Tweener Ease Out Quad"), Category = "Numerical Tweener")
	static float easeOutQuad(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInOutQuad", Keywords = "Tweener Ease In Out Quad"), Category = "Numerical Tweener")
	static float easeInOutQuad(float t, float b, float c, float d);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInQuart", Keywords = "Tweener Ease In Quart"), Category = "Numerical Tweener")
	static float easeInQuart(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseOutQuart", Keywords = "Tweener Ease Out Quart"), Category = "Numerical Tweener")
	static float easeOutQuart(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInOutQuart", Keywords = "Tweener Ease In Out Quart"), Category = "Numerical Tweener")
	static float easeInOutQuart(float t, float b, float c, float d);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInExpo", Keywords = "Tweener Ease In Expo"), Category = "Numerical Tweener")
	static float easeInExpo(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseOutExpo", Keywords = "Tweener Ease Out Expo"), Category = "Numerical Tweener")
	static float easeOutExpo(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInOutExpo", Keywords = "Tweener Ease In Out Expo"), Category = "Numerical Tweener")
	static float easeInOutExpo(float t, float b, float c, float d);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInElastic", Keywords = "Tweener Ease In Elastic"), Category = "Numerical Tweener")
	static float easeInElastic(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseOutElastic", Keywords = "Tweener Ease Out Elastic"), Category = "Numerical Tweener")
	static float easeOutElastic(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInOutElastic", Keywords = "Tweener Ease In Out Elastic"), Category = "Numerical Tweener")
	static float easeInOutElastic(float t, float b, float c, float d);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInBounce", Keywords = "Tweener Ease In Bounce"), Category = "Numerical Tweener")
	static float easeInBounce(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseOutBounce", Keywords = "Tweener Ease Out Bounce"), Category = "Numerical Tweener")
	static float easeOutBounce(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInOutBounce", Keywords = "Tweener Ease In Out Bounce"), Category = "Numerical Tweener")
	static float easeInOutBounce(float t, float b, float c, float d);
};
