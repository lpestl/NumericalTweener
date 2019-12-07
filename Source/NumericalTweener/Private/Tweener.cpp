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
					case ETransitionsEnum::Linear:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::Linear(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseInSine:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseInSine(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseOutSine: 
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseOutSine(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseInOutSine:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseInOutSine(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseInCubic:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseInCubic(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseOutCubic:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseOutCubic(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseInOutCubic:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseInOutCubic(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseInQuint:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseInQuint(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseOutQuint:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseOutQuint(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseInOutQuint:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseInOutQuint(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseInCirc:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseInCirc(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseOutCirc:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseOutCirc(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseInOutCirc:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseInOutCirc(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseInBack:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseInBack(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseOutBack:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseOutBack(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseInOutBack:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseInOutBack(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseInQuad:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseInQuad(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseOutQuad:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseOutQuad(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseInOutQuad:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseInOutQuad(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseInQuart:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseInQuart(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseOutQuart:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseOutQuart(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseInOutQuart: 
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseInOutQuart(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseInExpo:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseInExpo(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseOutExpo:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseOutExpo(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseInOutExpo:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseInOutExpo(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseInElastic:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseInElastic(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseOutElastic:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseOutElastic(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseInOutElastic:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseInOutElastic(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseInBounce:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseInBounce(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseOutBounce:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseOutBounce(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					case ETransitionsEnum::EaseInOutBounce:
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseInOutBounce(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
						break;
					default: 
						Tweens[i].var[0] = Bezier(
							Tweens[i].from,
							Tweens[i].to,
							UTransitions::EaseOutExpo(float(Tweens[i].timestamp.GetTicks()), 0.f, 1.f, float(Tweens[i].duration)),
							Tweens[i].by);
				}
			}
			else
			{
				//Tweens[i].var[0] = (a.*tweens[i]._easeFunction)(float(tweens[i]._timestamp.elapsed()), tweens[i]._from, tweens[i]._to - tweens[i]._from, float(tweens[i]._duration));
				switch (Tweens[i].easeFunction)
				{
					case ETransitionsEnum::Linear:
						Tweens[i].var[0] = UTransitions::Linear(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseInSine:
						Tweens[i].var[0] = UTransitions::EaseInSine(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseOutSine: 
						Tweens[i].var[0] = UTransitions::EaseOutSine(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration)); 
						break;
					case ETransitionsEnum::EaseInOutSine:
						Tweens[i].var[0] = UTransitions::EaseInOutSine(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseInCubic:
						Tweens[i].var[0] = UTransitions::EaseInCubic(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseOutCubic:
						Tweens[i].var[0] = UTransitions::EaseOutCubic(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseInOutCubic:
						Tweens[i].var[0] = UTransitions::EaseInOutCubic(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseInQuint:
						Tweens[i].var[0] = UTransitions::EaseInQuint(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseOutQuint:
						Tweens[i].var[0] = UTransitions::EaseOutQuint(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseInOutQuint:
						Tweens[i].var[0] = UTransitions::EaseInOutQuint(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseInCirc:
						Tweens[i].var[0] = UTransitions::EaseInCirc(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseOutCirc:
						Tweens[i].var[0] = UTransitions::EaseOutCirc(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseInOutCirc:
						Tweens[i].var[0] = UTransitions::EaseInOutCirc(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseInBack:
						Tweens[i].var[0] = UTransitions::EaseInBack(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseOutBack:
						Tweens[i].var[0] = UTransitions::EaseOutBack(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseInOutBack:
						Tweens[i].var[0] = UTransitions::EaseInOutBack(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseInQuad:
						Tweens[i].var[0] = UTransitions::EaseInQuad(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseOutQuad:
						Tweens[i].var[0] = UTransitions::EaseOutQuad(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseInOutQuad:
						Tweens[i].var[0] = UTransitions::EaseInOutQuad(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseInQuart:
						Tweens[i].var[0] = UTransitions::EaseInQuart(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseOutQuart:
						Tweens[i].var[0] = UTransitions::EaseOutQuart(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseInOutQuart:
						Tweens[i].var[0] = UTransitions::EaseInOutQuart(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseInExpo:
						Tweens[i].var[0] = UTransitions::EaseInExpo(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseOutExpo:
						Tweens[i].var[0] = UTransitions::EaseOutExpo(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseInOutExpo:
						Tweens[i].var[0] = UTransitions::EaseInOutExpo(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseInElastic:
						Tweens[i].var[0] = UTransitions::EaseInElastic(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseOutElastic: 
						Tweens[i].var[0] = UTransitions::EaseOutElastic(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration)); 
						break;
					case ETransitionsEnum::EaseInOutElastic:
						Tweens[i].var[0] = UTransitions::EaseInOutElastic(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseInBounce:
						Tweens[i].var[0] = UTransitions::EaseInBounce(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseOutBounce:
						Tweens[i].var[0] = UTransitions::EaseOutBounce(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					case ETransitionsEnum::EaseInOutBounce:
						Tweens[i].var[0] = UTransitions::EaseInOutBounce(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
						break;
					default:
						Tweens[i].var[0] = UTransitions::EaseOutExpo(float(Tweens[i].timestamp.GetTicks()), Tweens[i].from, Tweens[i].to - Tweens[i].from, float(Tweens[i].duration));
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
	AddTweenFull(var, to, time, ETransitionsEnum::EaseOutExpo, 0, 0, false, callback);
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

