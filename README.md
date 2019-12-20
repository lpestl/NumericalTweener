# Numerical Tweener

Numerical Tweener - a set of the 31st mathematical method for smoothly animating a change in a numerical value. The set allows you to simplify the start of animation (tween) of any parameter represented as a floating point number (float), using two nodes: calling the animation manager (Tweener) and starting the animation (AddTween). When launching an animation, it is enough to indicate the variable by reference, the number by which it must change, the time by which it must change, the way of a smooth transition, the delay (if necessary) and bezier. All available nodes are listed in the ["Bluprints nodes"](#Blueprints-nodes) section.

## How To Use

TODO:

## Includes Eases

* Linear;

<img src="Resources/Graphics/EaseInSine.png" width="128">
<img src="Resources/Graphics/EaseOutSine.png" width="128">
<img src="Resources/Graphics/EaseInOutSine.png" width="128">

* EaseInSine;
* EaseOutSine;		
* EaseInOutSine;	

<img src="Resources/Graphics/EaseInCubic.png" width="128">
<img src="Resources/Graphics/EaseOutCubic.png" width="128">
<img src="Resources/Graphics/EaseInOutCubic.png" width="128">

* EaseInCubic;		
* EaseOutCubic;	
* EaseInOutCubic;	

<img src="Resources/Graphics/EaseInQuint.png" width="128">
<img src="Resources/Graphics/EaseOutQuint.png" width="128">
<img src="Resources/Graphics/EaseInOutQuint.png" width="128">

* EaseInQuint;		
* EaseOutQuint;	
* EaseInOutQuint;	

<img src="Resources/Graphics/EaseInCirc.png" width="128">
<img src="Resources/Graphics/EaseOutCirc.png" width="128">
<img src="Resources/Graphics/EaseInOutCirc.png" width="128">

* EaseInCirc;		
* EaseOutCirc;		
* EaseInOutCirc;	

<img src="Resources/Graphics/EaseInBack.png" width="128">
<img src="Resources/Graphics/EaseOutBack.png" width="128">
<img src="Resources/Graphics/EaseInOutBack.png" width="128">

* EaseInBack;		
* EaseOutBack;		
* EaseInOutBack;	

<img src="Resources/Graphics/EaseInQuad.png" width="128">
<img src="Resources/Graphics/EaseOutQuad.png" width="128">
<img src="Resources/Graphics/EaseInOutQuad.png" width="128">

* EaseInQuad;		
* EaseOutQuad;		
* EaseInOutQuad;	

<img src="Resources/Graphics/EaseInQuart.png" width="128">
<img src="Resources/Graphics/EaseOutQuart.png" width="128">
<img src="Resources/Graphics/EaseInOutQuart.png" width="128">

* EaseInQuart;		
* EaseOutQuart;	
* EaseInOutQuart;	

<img src="Resources/Graphics/EaseInExpo.png" width="128">
<img src="Resources/Graphics/EaseOutExpo.png" width="128">
<img src="Resources/Graphics/EaseInOutExpo.png" width="128">

* EaseInExpo;		
* EaseOutExpo;		
* EaseInOutExpo;	

<img src="Resources/Graphics/EaseInElastic.png" width="128">
<img src="Resources/Graphics/EaseOutElastic.png" width="128">
<img src="Resources/Graphics/EaseInOutElastic.png" width="128">

* EaseInElastic;	
* EaseOutElastic;	
* EaseInOutElastic;

<img src="Resources/Graphics/EaseInBounce.png" width="128">
<img src="Resources/Graphics/EaseOutBounce.png" width="128">
<img src="Resources/Graphics/EaseInOutBounce.png" width="128">

* EaseInBounce;	
* EaseOutBounce;	
* EaseInOutBounce;	

## Blueprints nodes

* Transitions:

![Transitions](media/TransitionCasses.png)

* Get tweens manager:

![Get Tweener](media/GetTweener.png)

* Add tween:

![AddTween](media/AvailableTweens.png)

* Remove tweens:

![Remove tweens](media/RemoveTweens.png)

* Change Time scale for all added tweens:

![Time Scale](media/TimeScale.png)