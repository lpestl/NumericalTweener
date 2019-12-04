// Fill out your copyright notice in the Description page of Project Settings.


#include "Transitions.h"

float UTransitions::linear(float t, float b, float c, float d)
{
	return c * t / d + b;
}

float UTransitions::easeInSine(float t, float b, float c, float d)
{
	return -c * cos(t / d * (PI / 2)) + c + b;
}

float UTransitions::easeOutSine(float t, float b, float c, float d)
{
	return c * sin(t / d * (PI / 2)) + b;
}

float UTransitions::easeInOutSine(float t, float b, float c, float d)
{
	return -c / 2 * (cos(PI * t / d) - 1) + b;
}

float UTransitions::easeInCubic(float t, float b, float c, float d)
{
	return c * (t /= d) * t * t + b;
}

float UTransitions::easeOutCubic(float t, float b, float c, float d)
{
	return c * ((t = t / d - 1) * t * t + 1) + b;
}

float UTransitions::easeInOutCubic(float t, float b, float c, float d)
{
	if ((t /= d / 2) < 1) 
		return c / 2 * t * t * t + b;
	return c / 2 * ((t -= 2) * t * t + 2) + b;
}

float UTransitions::easeInQuint(float t, float b, float c, float d)
{
	return c * (t /= d) * t * t * t * t + b;
}

float UTransitions::easeOutQuint(float t, float b, float c, float d)
{
	return c * ((t = t / d - 1) * t * t * t * t + 1) + b;
}

float UTransitions::easeInOutQuint(float t, float b, float c, float d)
{
	if ((t /= d / 2) < 1) 
		return c / 2 * t * t * t * t * t + b;
	return c / 2 * ((t -= 2) * t * t * t * t + 2) + b;
}

float UTransitions::easeInCirc(float t, float b, float c, float d)
{
	return -c * (sqrt(1 - (t /= d) * t) - 1) + b;
}

float UTransitions::easeOutCirc(float t, float b, float c, float d)
{
	return c * sqrt(1 - (t = t / d - 1) * t) + b;
}

float UTransitions::easeInOutCirc(float t, float b, float c, float d)
{
	if ((t /= d / 2) < 1) 
		return -c / 2 * (sqrt(1 - t * t) - 1) + b;
	return c / 2 * (sqrt(1 - t * (t -= 2)) + 1) + b;
}

float UTransitions::easeInBack(float t, float b, float c, float d)
{
	float s = 1.70158f;
	float postFix = t /= d;
	return c * (postFix)*t * ((s + 1) * t - s) + b;
}

float UTransitions::easeOutBack(float t, float b, float c, float d)
{
	float s = 1.70158f;
	return c * ((t = t / d - 1) * t * ((s + 1) * t + s) + 1) + b;
}

float UTransitions::easeInOutBack(float t, float b, float c, float d)
{
	float s = 1.70158f;
	if ((t /= d / 2) < 1) return c / 2 * (t * t * (((s *= (1.525f)) + 1) * t - s)) + b;
	float postFix = t -= 2;
	return c / 2 * ((postFix)*t * (((s *= (1.525f)) + 1) * t + s) + 2) + b;
}

float UTransitions::easeInQuad(float t, float b, float c, float d)
{
	return c * (t /= d) * t + b;
}

float UTransitions::easeOutQuad(float t, float b, float c, float d)
{
	return -c * (t /= d) * (t - 2) + b;
}

float UTransitions::easeInOutQuad(float t, float b, float c, float d)
{
	if ((t /= d / 2) < 1) 
		return ((c / 2) * (t * t)) + b;
	return -c / 2 * (((--t) * (t - 2)) - 1) + b;
}

float UTransitions::easeInQuart(float t, float b, float c, float d)
{
	return c * (t /= d) * t * t * t + b;
}

float UTransitions::easeOutQuart(float t, float b, float c, float d)
{
	return -c * ((t = t / d - 1) * t * t * t - 1) + b;
}

float UTransitions::easeInOutQuart(float t, float b, float c, float d)
{
	if ((t /= d / 2) < 1) 
		return c / 2 * t * t * t * t + b;
	return -c / 2 * ((t -= 2) * t * t * t - 2) + b;
}

float UTransitions::easeInExpo(float t, float b, float c, float d)
{
	return (t == 0) ? b : c * pow(2, 10 * (t / d - 1)) + b;
}

float UTransitions::easeOutExpo(float t, float b, float c, float d)
{
	return (t == d) ? b + c : c * (-pow(2, -10 * t / d) + 1) + b;
}

float UTransitions::easeInOutExpo(float t, float b, float c, float d)
{
	if (t == 0) 
		return b;
	if (t == d) 
		return b + c;
	if ((t /= d / 2) < 1) 
		return c / 2 * pow(2, 10 * (t - 1)) + b;
	return c / 2 * (-pow(2, -10 * --t) + 2) + b;
}

float UTransitions::easeInElastic(float t, float b, float c, float d)
{
	if (t == 0) 
		return b;  
	if ((t /= d) == 1) 
		return b + c;

	float p = d * .3f;
	float a = c;
	float s = p / 4;
	float postFix = a * pow(2, 10 * (t -= 1));

	return -(postFix * sin((t * d - s) * (2 * PI) / p)) + b;
}

float UTransitions::easeOutElastic(float t, float b, float c, float d)
{
	if (t == 0) 
		return b;  
	if ((t /= d) == 1) 
		return b + c;

	float p = d * .3f;
	float a = c;
	float s = p / 4;

	return (a * pow(2, -10 * t) * sin((t * d - s) * (2 * PI) / p) + c + b);
}

float UTransitions::easeInOutElastic(float t, float b, float c, float d)
{
	if (t == 0) 
		return b;  
	if ((t /= d / 2) == 2) 
		return b + c;

	float p = d * (.3f * 1.5f);
	float a = c;
	float s = p / 4;

	if (t < 1) 
	{
		float postFix = a * pow(2, 10 * (t -= 1));
		return -.5f * (postFix * sin((t * d - s) * (2 * PI) / p)) + b;
	}

	float postFix = a * pow(2, -10 * (t -= 1));
	return postFix * sin((t * d - s) * (2 * PI) / p) * .5f + c + b;
}

float UTransitions::easeInBounce(float t, float b, float c, float d)
{
	return c - easeOutBounce(d - t, 0, c, d) + b;
}

float UTransitions::easeOutBounce(float t, float b, float c, float d)
{
	if ((t /= d) < (1 / 2.75f)) {
		return c * (7.5625f * t * t) + b;
	}
	else if (t < (2 / 2.75f)) {
		float postFix = t -= (1.5f / 2.75f);
		return c * (7.5625f * (postFix)*t + .75f) + b;
	}
	else if (t < (2.5 / 2.75)) {
		float postFix = t -= (2.25f / 2.75f);
		return c * (7.5625f * (postFix)*t + .9375f) + b;
	}
	else {
		float postFix = t -= (2.625f / 2.75f);
		return c * (7.5625f * (postFix)*t + .984375f) + b;
	}
}

float UTransitions::easeInOutBounce(float t, float b, float c, float d)
{
	if (t < d / 2) 
		return easeInBounce(t * 2, 0, c, d) * .5f + b;
	else 
		return easeOutBounce(t * 2 - d, 0, c, d) * .5f + c * .5f + b;
}


