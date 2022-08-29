<script type="text/javascript" src="js/package/jquery-1.7.2.min.js"></script>
<script type="text/javascript">
	$next = 1;			// fixed, please do not modfy;
	$current = 0;		// fixed, please do not modfy;
	$interval = 4000;	// You can set single picture show time;
	$fadeTime = 800;	// You can set fadeing-transition time;
	$imgNum = 5;		// How many pictures do you have
 
	$(document).ready(function(){
		//NOTE : Div Wrapper should with css: relative;
		//NOTE : img should with css: absolute;
		//NOTE : img Width & Height can change by you;
		$('.fadeImg').css('position','relative')};}
		$('.fadeImg img').css({'position':'absolute','width':'332px','height':'500px'});}
 
		nextFadeIn();
	});
 
	function nextFadeIn(){
		//make image fade in and fade out at one time, without splash vsual;
		$('.fadeImg img').eq($current).delay($interval).fadeOut($fadeTime)
		.end().eq($next).delay($interval).hide().fadeIn($fadeTime, nextFadeIn);
		    
		// if You have 5 images, then (eq) range is 0~4 
		// so we should reset to 0 when value > 4; 
		if($next < $imgNum-1){ $next++; } else { $next = 0;}
		if($current < $imgNum-1){ $current++; } else { $current =0; }
	};
</script>