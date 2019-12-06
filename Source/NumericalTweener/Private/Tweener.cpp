// Fill out your copyright notice in the Description page of Project Settings.


#include "Tweener.h"
#include "Transitions.h"

DEFINE_LOG_CATEGORY(LogTweener);

// Sets default values
ATweener::ATweener()
	: Scale(1.f)
	, bOverride(true)
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

	for (int i = Tweens.Num() - 1; i >= 0; --i) 
	{
		UE_LOG(LogTweener, Log, TEXT("Tick "));
		Tweens[i].timestamp += FTimespan::FromSeconds(DeltaTime);

		float elapsed = float(Tweens[i].timestamp.GetTicks());

		UE_LOG(LogTweener, Log, TEXT("Tick %f"), elapsed);

		if (elapsed >= float(Tweens[i].duration)) 
		{
			//tween is done
			bool found = false;
			if (!bOverride) 
			{
				//if not found anymore, place on exact place
				for (int j = 0; j < Tweens.Num(); ++j) 
				{
					if (Tweens[j].var == Tweens[i].var) 
					{
						found = true;
						break;
					}
				}
			}

			if (!found) 
				Tweens[i].var[0] = Tweens[i].to;

			if (Callbacks.Contains(Tweens[i].var))
			{
				Callbacks[Tweens[i].var].Execute();
				Callbacks.Remove(Tweens[i].var);
			}

			Tweens.RemoveAt(i);
		}
		else if (float(Tweens[i].timestamp.GetTicks()) > 0) 
		{
			//smaller than 0 would be delayed
			if (Tweens[i].useBezier)
			{
				switch (Tweens[i].easeFunction)
				{
					case ETransitionsEnum::TE_Linear:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::linear(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseInSine:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeInSine(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseOutSine: 
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeOutSine(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseInOutSine:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeInOutSine(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseInCubic:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeInCubic(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseOutCubic:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeOutCubic(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseInOutCubic:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeInOutCubic(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseInQuint:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeInQuint(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseOutQuint:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeOutQuint(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseInOutQuint:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeInOutQuint(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseInCirc:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeInCirc(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseOutCirc:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeOutCirc(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseInOutCirc:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeInOutCirc(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseInBack:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeInBack(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseOutBack:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeOutBack(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseInOutBack:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeInOutBack(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseInQuad:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeInQuad(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseOutQuad:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeOutQuad(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseInOutQuad:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeInOutQuad(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseInQuart:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeInQuart(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseOutQuart:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeOutQuart(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseInOutQuart: 
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeInOutQuart(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseInExpo:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeInExpo(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseOutExpo:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeOutExpo(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseInOutExpo:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeInOutExpo(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseInElastic:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeInElastic(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseOutElastic:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeOutElastic(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseInOutElastic:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeInOutElastic(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseInBounce:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeInBounce(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseOutBounce:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeOutBounce(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::TE_EaseInOutBounce:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeInOutBounce(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					default: 
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::easeOutExpo(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
				}
			}
			else
			{
				//Tweens[i].var[0] = (a.*tweens[i]._easeFunction)(float(tweens[i]._timestamp.elapsed()), tweens[i]._from, tweens[i]._to - tweens[i]._from, float(tweens[i]._duration));
				switch (Tweens[i].easeFunction)
				{
					case ETransitionsEnum::TE_Linear:
						Tweens[i].var[0] = UTransitions::linear(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseInSine:
						Tweens[i].var[0] = UTransitions::easeInSine(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseOutSine: 
						Tweens[i].var[0] = UTransitions::easeOutSine(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration)); 
						break;
					case ETransitionsEnum::TE_EaseInOutSine:
						Tweens[i].var[0] = UTransitions::easeInOutSine(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseInCubic:
						Tweens[i].var[0] = UTransitions::easeInCubic(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseOutCubic:
						Tweens[i].var[0] = UTransitions::easeOutCubic(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseInOutCubic:
						Tweens[i].var[0] = UTransitions::easeInOutCubic(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseInQuint:
						Tweens[i].var[0] = UTransitions::easeInQuint(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseOutQuint:
						Tweens[i].var[0] = UTransitions::easeOutQuint(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseInOutQuint:
						Tweens[i].var[0] = UTransitions::easeInOutQuint(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseInCirc:
						Tweens[i].var[0] = UTransitions::easeInCirc(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseOutCirc:
						Tweens[i].var[0] = UTransitions::easeOutCirc(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseInOutCirc:
						Tweens[i].var[0] = UTransitions::easeInOutCirc(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseInBack:
						Tweens[i].var[0] = UTransitions::easeInBack(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseOutBack:
						Tweens[i].var[0] = UTransitions::easeOutBack(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseInOutBack:
						Tweens[i].var[0] = UTransitions::easeInOutBack(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseInQuad:
						Tweens[i].var[0] = UTransitions::easeInQuad(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseOutQuad:
						Tweens[i].var[0] = UTransitions::easeOutQuad(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseInOutQuad:
						Tweens[i].var[0] = UTransitions::easeInOutQuad(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseInQuart:
						Tweens[i].var[0] = UTransitions::easeInQuart(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseOutQuart:
						Tweens[i].var[0] = UTransitions::easeOutQuart(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseInOutQuart:
						Tweens[i].var[0] = UTransitions::easeInOutQuart(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseInExpo:
						Tweens[i].var[0] = UTransitions::easeInExpo(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseOutExpo:
						Tweens[i].var[0] = UTransitions::easeOutExpo(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseInOutExpo:
						Tweens[i].var[0] = UTransitions::easeInOutExpo(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseInElastic:
						Tweens[i].var[0] = UTransitions::easeInElastic(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseOutElastic: 
						Tweens[i].var[0] = UTransitions::easeOutElastic(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration)); 
						break;
					case ETransitionsEnum::TE_EaseInOutElastic:
						Tweens[i].var[0] = UTransitions::easeInOutElastic(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseInBounce:
						Tweens[i].var[0] = UTransitions::easeInBounce(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseOutBounce:
						Tweens[i].var[0] = UTransitions::easeOutBounce(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::TE_EaseInOutBounce:
						Tweens[i].var[0] = UTransitions::easeInOutBounce(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					default:
						Tweens[i].var[0] = UTransitions::easeOutExpo(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
				}
			}			
		}
	}
}

void ATweener::AddTween(
	float& var,
	float to, 
	float time, 
	FTweenCompletedCallback callback)
{
	AddTweenFull(var, to, time, ETransitionsEnum::TE_EaseOutExpo, 0, 0, false, callback);
}

void ATweener::AddEaseTween(
	float& var, 
	float to, 
	float time, 
	ETransitionsEnum transition,
	FTweenCompletedCallback callback)
{
	AddTweenFull(var, to, time, transition, 0, 0, false, callback);
}

void ATweener::AddDelayTween(
	float& var, 
	float to, 
	float time, 
	ETransitionsEnum transition, 
	float delay,
	FTweenCompletedCallback callback)
{
	AddTweenFull(var, to, time, transition, delay, 0, false, callback);
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
	AddTweenFull(var, to, time, transition, delay, bezierPoint, true, callback);
}

void ATweener::RemoveTween(float& var)
{
	// Remove callback if exist
	if (Callbacks.Contains(&var))
		Callbacks.Remove(&var);

	// Find and remove tween
	for (int32 i = 0; i < Tweens.Num(); ++i)
		if (Tweens[i].var == &var)
		{
			Tweens.RemoveAt(i);
			break;
		}
}

void ATweener::SetTimeScale(float scale)
{
	Scale = scale;
}

void ATweener::RemoveAllTweens()
{
	Tweens.Empty();
}

int32 ATweener::GetTweenCount()
{
	return Tweens.Num();
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
	float from = var;
	float _delay = delay;
	FDateTime latest = FDateTime(0);

	for (auto& Tween : Tweens) 
	{
		if (Tween.var == &var) 
		{
			// object already tweening, just kill the old one
			if (bOverride) 
			{
				Tween.from = from;
				Tween.to = to;
				Tween.by = bezierPoint;
				Tween.useBezier = useBezier;
				Tween.easeFunction = transition;
				Tween.timestamp = FDateTime(0) + (delay / Scale) * 100000000.0f;
				Tween.duration = (time / Scale) * 100000000.0f;
				return;
			}
			else 
			{
				//sequence mode
				if ((Tween.timestamp + Tween.duration) > latest) 
				{
					latest = (Tween.timestamp + Tween.duration);
					delay = _delay + ((Tween.duration - Tween.timestamp.GetTicks()) / 100000000.0f);
					from = Tween.to;
				}
			}
		}
	}

	Tween t;

	t.var = &var;
	t.from = from;
	t.to = to;
	t.by = bezierPoint;
	t.useBezier = useBezier;
	t.easeFunction = transition;
	t.timestamp = FDateTime(0) + ((delay / Scale) * 100000000.0f);
	t.duration = (time / Scale) * 100000000.0f;

	Tweens.Add(t);

	Callbacks.Emplace(t.var, callback);
}

float ATweener::Bezier(float b, float e, float t, float p)
{
	return b + t * (2 * (1 - t) * (p - b) + t * (e - b));
}

