// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class ETransitionsEnum : uint8
{
	Linear 				UMETA(DisplayName = "Linear"),

	EaseInSine 			UMETA(DisplayName = "EaseInSine"),
	EaseOutSine			UMETA(DisplayName = "EaseOutSine"),
	EaseInOutSine		UMETA(DisplayName = "EaseInOutSine"),

	EaseInCubic			UMETA(DisplayName = "EaseInCubic"),
	EaseOutCubic		UMETA(DisplayName = "EaseOutCubic"),
	EaseInOutCubic		UMETA(DisplayName = "EaseInOutCubic"),

	EaseInQuint			UMETA(DisplayName = "EaseInQuint"),
	EaseOutQuint		UMETA(DisplayName = "EaseOutQuint"),
	EaseInOutQuint		UMETA(DisplayName = "EaseInOutQuint"),

	EaseInCirc			UMETA(DisplayName = "EaseInCirc"),
	EaseOutCirc			UMETA(DisplayName = "EaseOutCirc"),
	EaseInOutCirc		UMETA(DisplayName = "EaseInOutCirc"),

	EaseInBack			UMETA(DisplayName = "EaseInBack"),
	EaseOutBack			UMETA(DisplayName = "EaseOutBack"),
	EaseInOutBack		UMETA(DisplayName = "EaseInOutBack"),

	EaseInQuad			UMETA(DisplayName = "EaseInQuad"),
	EaseOutQuad			UMETA(DisplayName = "EaseOutQuad"),
	EaseInOutQuad		UMETA(DisplayName = "EaseInOutQuad"),

	EaseInQuart			UMETA(DisplayName = "EaseInQuart"),
	EaseOutQuart		UMETA(DisplayName = "EaseOutQuart"),
	EaseInOutQuart		UMETA(DisplayName = "EaseInOutQuart"),

	EaseInExpo			UMETA(DisplayName = "EaseInExpo"),
	EaseOutExpo			UMETA(DisplayName = "EaseOutExpo"),
	EaseInOutExpo		UMETA(DisplayName = "EaseInOutExpo"),

	EaseInElastic		UMETA(DisplayName = "EaseInElastic"),
	EaseOutElastic		UMETA(DisplayName = "EaseOutElastic"),
	EaseInOutElastic	UMETA(DisplayName = "EaseInOutElastic"),

	EaseInBounce		UMETA(DisplayName = "EaseInBounce"),
	EaseOutBounce		UMETA(DisplayName = "EaseOutBounce"),
	EaseInOutBounce		UMETA(DisplayName = "EaseInOutBounce")
};

