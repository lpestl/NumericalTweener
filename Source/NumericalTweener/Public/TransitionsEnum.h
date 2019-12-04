// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

/**
 * 
 */
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

