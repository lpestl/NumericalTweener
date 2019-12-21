// Copyright 2019 Mikhail S. Kataev. All Rights Reserved.

#include "Tweener.h"
#include "Transitions.h"

DEFINE_LOG_CATEGORY(LogTweener);

// Sets default values
ATweener::ATweener()
	: Scale_(1.f)
	, bOverride_(true)
{
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

	for (int i = Tweens_.Num() - 1; i >= 0; --i) 
	{
		Tweens_[i].Timestamp += FTimespan::FromSeconds(DeltaTime);
		
		if (float(Tweens_[i].Timestamp.GetTicks()) >= float(Tweens_[i].Duration))
		{
			//tween is done
			bool found = false;
			if (!bOverride_) 
			{
				//if not found anymore, place on exact place
				for (int j = 0; j < Tweens_.Num(); ++j) 
				{
					if (Tweens_[j].Var == Tweens_[i].Var) 
					{
						found = true;
						break;
					}
				}
			}

			if (!found) 
				Tweens_[i].Var[0] = Tweens_[i].To;
						
			if (Callbacks_.Contains(Tweens_[i].Var))
			{
				FTweenCompletedCallback CallbackAfter;
				Callbacks_.RemoveAndCopyValue(Tweens_[i].Var, CallbackAfter);
				Tweens_.RemoveAt(i);

				if (CallbackAfter.IsBound())
					CallbackAfter.Execute();
			}
			else
			{
				Tweens_.RemoveAt(i);
			}
		}
		else if (float(Tweens_[i].Timestamp.GetTicks()) > 0) 
		{
			//smaller than 0 would be delayed
			if (Tweens_[i].UseBezier)
			{
				switch (Tweens_[i].EaseFunction)
				{
					case ETransitionsEnum::Linear:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::Linear(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseInSine:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseInSine(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseOutSine: 
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseOutSine(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseInOutSine:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseInOutSine(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseInCubic:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseInCubic(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseOutCubic:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseOutCubic(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseInOutCubic:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseInOutCubic(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseInQuint:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseInQuint(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseOutQuint:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseOutQuint(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseInOutQuint:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseInOutQuint(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseInCirc:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseInCirc(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseOutCirc:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseOutCirc(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseInOutCirc:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseInOutCirc(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseInBack:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseInBack(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseOutBack:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseOutBack(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseInOutBack:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseInOutBack(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseInQuad:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseInQuad(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseOutQuad:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseOutQuad(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseInOutQuad:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseInOutQuad(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseInQuart:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseInQuart(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseOutQuart:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseOutQuart(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseInOutQuart: 
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseInOutQuart(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseInExpo:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseInExpo(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseOutExpo:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseOutExpo(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseInOutExpo:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseInOutExpo(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseInElastic:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseInElastic(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseOutElastic:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseOutElastic(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseInOutElastic:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseInOutElastic(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseInBounce:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseInBounce(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseOutBounce:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseOutBounce(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					case ETransitionsEnum::EaseInOutBounce:
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseInOutBounce(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
						break;
					default: 
						Tweens_[i].Var[0] = Bezier(
							Tweens_[i].From,
							Tweens_[i].To,
							UTransitions::EaseOutExpo(float(Tweens_[i].Timestamp.GetTicks()), 0.f, 1.f, float(Tweens_[i].Duration)),
							Tweens_[i].By);
				}
			}
			else
			{
				switch (Tweens_[i].EaseFunction)
				{
					case ETransitionsEnum::Linear:
						Tweens_[i].Var[0] = UTransitions::Linear(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseInSine:
						Tweens_[i].Var[0] = UTransitions::EaseInSine(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseOutSine: 
						Tweens_[i].Var[0] = UTransitions::EaseOutSine(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration)); 
						break;
					case ETransitionsEnum::EaseInOutSine:
						Tweens_[i].Var[0] = UTransitions::EaseInOutSine(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseInCubic:
						Tweens_[i].Var[0] = UTransitions::EaseInCubic(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseOutCubic:
						Tweens_[i].Var[0] = UTransitions::EaseOutCubic(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseInOutCubic:
						Tweens_[i].Var[0] = UTransitions::EaseInOutCubic(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseInQuint:
						Tweens_[i].Var[0] = UTransitions::EaseInQuint(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseOutQuint:
						Tweens_[i].Var[0] = UTransitions::EaseOutQuint(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseInOutQuint:
						Tweens_[i].Var[0] = UTransitions::EaseInOutQuint(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseInCirc:
						Tweens_[i].Var[0] = UTransitions::EaseInCirc(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseOutCirc:
						Tweens_[i].Var[0] = UTransitions::EaseOutCirc(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseInOutCirc:
						Tweens_[i].Var[0] = UTransitions::EaseInOutCirc(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseInBack:
						Tweens_[i].Var[0] = UTransitions::EaseInBack(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseOutBack:
						Tweens_[i].Var[0] = UTransitions::EaseOutBack(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseInOutBack:
						Tweens_[i].Var[0] = UTransitions::EaseInOutBack(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseInQuad:
						Tweens_[i].Var[0] = UTransitions::EaseInQuad(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseOutQuad:
						Tweens_[i].Var[0] = UTransitions::EaseOutQuad(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseInOutQuad:
						Tweens_[i].Var[0] = UTransitions::EaseInOutQuad(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseInQuart:
						Tweens_[i].Var[0] = UTransitions::EaseInQuart(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseOutQuart:
						Tweens_[i].Var[0] = UTransitions::EaseOutQuart(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseInOutQuart:
						Tweens_[i].Var[0] = UTransitions::EaseInOutQuart(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseInExpo:
						Tweens_[i].Var[0] = UTransitions::EaseInExpo(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseOutExpo:
						Tweens_[i].Var[0] = UTransitions::EaseOutExpo(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseInOutExpo:
						Tweens_[i].Var[0] = UTransitions::EaseInOutExpo(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseInElastic:
						Tweens_[i].Var[0] = UTransitions::EaseInElastic(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseOutElastic: 
						Tweens_[i].Var[0] = UTransitions::EaseOutElastic(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration)); 
						break;
					case ETransitionsEnum::EaseInOutElastic:
						Tweens_[i].Var[0] = UTransitions::EaseInOutElastic(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseInBounce:
						Tweens_[i].Var[0] = UTransitions::EaseInBounce(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseOutBounce:
						Tweens_[i].Var[0] = UTransitions::EaseOutBounce(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					case ETransitionsEnum::EaseInOutBounce:
						Tweens_[i].Var[0] = UTransitions::EaseInOutBounce(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
						break;
					default:
						Tweens_[i].Var[0] = UTransitions::EaseOutExpo(float(Tweens_[i].Timestamp.GetTicks()), Tweens_[i].From, Tweens_[i].To - Tweens_[i].From, float(Tweens_[i].Duration));
				}
			}			
		}
	}
}

void ATweener::AddTween(
	float& Var,
	float To, 
	float Time, 
	const FTweenCompletedCallback& Callback)
{
	AddTweenFull(Var, To, Time, ETransitionsEnum::EaseOutExpo, 0, 0, false, Callback);
}

void ATweener::AddEaseTween(
	float& Var, 
	float To, 
	float Time, 
	ETransitionsEnum Transition,
	const FTweenCompletedCallback& Callback)
{
	AddTweenFull(Var, To, Time, Transition, 0, 0, false, Callback);
}

void ATweener::AddDelayTween(
	float& Var, 
	float To, 
	float Time, 
	ETransitionsEnum Transition, 
	float Delay,
	const FTweenCompletedCallback& Callback)
{
	AddTweenFull(Var, To, Time, Transition, Delay, 0, false, Callback);
}

void ATweener::AddBezierTween(
	float& Var, 
	float To, 
	float Time, 
	ETransitionsEnum Transition, 
	float Delay,
	float BezierPoint, 
	const FTweenCompletedCallback& Callback)
{
	AddTweenFull(Var, To, Time, Transition, Delay, BezierPoint, true, Callback);
}

void ATweener::RemoveTween(float& Var)
{
	// Remove callback if exist
	if (Callbacks_.Contains(&Var))
		Callbacks_.Remove(&Var);

	// Find and remove tween
	for (int32 i = 0; i < Tweens_.Num(); ++i)
		if (Tweens_[i].Var == &Var)
		{
			Tweens_.RemoveAt(i);
			break;
		}
}

void ATweener::SetTimeScale(float Scale)
{
	Scale_ = Scale;
}

void ATweener::RemoveAllTweens()
{
	Tweens_.Empty();
}

int32 ATweener::GetTweenCount()
{
	return Tweens_.Num();
}

void ATweener::AddTweenFull(
	float& Var, 
	float To, 
	float Time, 
	ETransitionsEnum Transition, 
	float Delay,
	float BezierPoint, 
	bool bUseBezier, 
	const FTweenCompletedCallback& Callback)
{
	float From = Var;
	float _delay = Delay;
	FDateTime latest = FDateTime(0);

	for (auto& Tween : Tweens_) 
	{
		if (Tween.Var == &Var) 
		{
			// object already tweening, just kill the old one
			if (bOverride_) 
			{
				Tween.From = From;
				Tween.To = To;
				Tween.By = BezierPoint;
				Tween.UseBezier = bUseBezier;
				Tween.EaseFunction = Transition;
				Tween.Timestamp = FDateTime(0) + (Delay / Scale_) * 10000000.0f;
				Tween.Duration = (Time / Scale_) * 10000000.0f;
				return;
			}
			else 
			{
				//sequence mode
				if ((Tween.Timestamp + Tween.Duration) > latest) 
				{
					latest = (Tween.Timestamp + Tween.Duration);
					Delay = _delay + ((Tween.Duration - Tween.Timestamp.GetTicks()) / 10000000.0f);
					From = Tween.To;
				}
			}
		}
	}

	Tween t;

	t.Var = &Var;
	t.From = From;
	t.To = To;
	t.By = BezierPoint;
	t.UseBezier = bUseBezier;
	t.EaseFunction = Transition;
	t.Timestamp = FDateTime(0) + ((Delay / Scale_) * 10000000.0f);
	t.Duration = (Time / Scale_) * 10000000.0f;

	Tweens_.Add(t);

	Callbacks_.Emplace(t.Var, Callback);
}

float ATweener::Bezier(float b, float e, float t, float p)
{
	return b + t * (2 * (1 - t) * (p - b) + t * (e - b));
}

