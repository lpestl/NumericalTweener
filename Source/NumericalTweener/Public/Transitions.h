// Copyright 2019 Mikhail S. Kataev. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Transitions.generated.h"

/**
 * Transition Functions
 */
UCLASS()
class UTransitions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Linear", Keywords = "Tweener Ease linear"), Category = "Numerical Tweener")
	static float Linear(float t, float b, float c, float d);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInSine", Keywords = "Tweener Ease In Sine"), Category = "Numerical Tweener")
	static float EaseInSine(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseOutSine", Keywords = "Tweener Ease Out Sine"), Category = "Numerical Tweener")
	static float EaseOutSine(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInOutSine", Keywords = "Tweener Ease In Out Sine"), Category = "Numerical Tweener")
	static float EaseInOutSine(float t, float b, float c, float d);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInCubic", Keywords = "Tweener Ease In Cubic"), Category = "Numerical Tweener")
	static float EaseInCubic(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseOutCubic", Keywords = "Tweener Ease Out Cubic"), Category = "Numerical Tweener")
	static float EaseOutCubic(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInOutCubic", Keywords = "Tweener Ease In Out Cubic"), Category = "Numerical Tweener")
	static float EaseInOutCubic(float t, float b, float c, float d);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInQuint", Keywords = "Tweener Ease In Quint"), Category = "Numerical Tweener")
	static float EaseInQuint(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseOutQuint", Keywords = "Tweener Ease Out Quint"), Category = "Numerical Tweener")
	static float EaseOutQuint(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInOutQuint", Keywords = "Tweener Ease In Out Quint"), Category = "Numerical Tweener")
	static float EaseInOutQuint(float t, float b, float c, float d);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInCirc", Keywords = "Tweener Ease In Circ"), Category = "Numerical Tweener")
	static float EaseInCirc(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseOutCirc", Keywords = "Tweener Ease Out Circ"), Category = "Numerical Tweener")
	static float EaseOutCirc(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInOutCirc", Keywords = "Tweener Ease In Out Circ"), Category = "Numerical Tweener")
	static float EaseInOutCirc(float t, float b, float c, float d);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInBack", Keywords = "Tweener Ease In Back"), Category = "Numerical Tweener")
	static float EaseInBack(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseOutBack", Keywords = "Tweener Ease Out Back"), Category = "Numerical Tweener")
	static float EaseOutBack(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInOutBack", Keywords = "Tweener Ease In Out Back"), Category = "Numerical Tweener")
	static float EaseInOutBack(float t, float b, float c, float d);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInQuad", Keywords = "Tweener Ease In Quad"), Category = "Numerical Tweener")
	static float EaseInQuad(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseOutQuad", Keywords = "Tweener Ease Out Quad"), Category = "Numerical Tweener")
	static float EaseOutQuad(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInOutQuad", Keywords = "Tweener Ease In Out Quad"), Category = "Numerical Tweener")
	static float EaseInOutQuad(float t, float b, float c, float d);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInQuart", Keywords = "Tweener Ease In Quart"), Category = "Numerical Tweener")
	static float EaseInQuart(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseOutQuart", Keywords = "Tweener Ease Out Quart"), Category = "Numerical Tweener")
	static float EaseOutQuart(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInOutQuart", Keywords = "Tweener Ease In Out Quart"), Category = "Numerical Tweener")
	static float EaseInOutQuart(float t, float b, float c, float d);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInExpo", Keywords = "Tweener Ease In Expo"), Category = "Numerical Tweener")
	static float EaseInExpo(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseOutExpo", Keywords = "Tweener Ease Out Expo"), Category = "Numerical Tweener")
	static float EaseOutExpo(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInOutExpo", Keywords = "Tweener Ease In Out Expo"), Category = "Numerical Tweener")
	static float EaseInOutExpo(float t, float b, float c, float d);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInElastic", Keywords = "Tweener Ease In Elastic"), Category = "Numerical Tweener")
	static float EaseInElastic(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseOutElastic", Keywords = "Tweener Ease Out Elastic"), Category = "Numerical Tweener")
	static float EaseOutElastic(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInOutElastic", Keywords = "Tweener Ease In Out Elastic"), Category = "Numerical Tweener")
	static float EaseInOutElastic(float t, float b, float c, float d);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInBounce", Keywords = "Tweener Ease In Bounce"), Category = "Numerical Tweener")
	static float EaseInBounce(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseOutBounce", Keywords = "Tweener Ease Out Bounce"), Category = "Numerical Tweener")
	static float EaseOutBounce(float t, float b, float c, float d);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "EaseInOutBounce", Keywords = "Tweener Ease In Out Bounce"), Category = "Numerical Tweener")
	static float EaseInOutBounce(float t, float b, float c, float d);
};
