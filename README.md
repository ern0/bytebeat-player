# bytebeat-player

Bytebeat player, using SDL2.

Now playing my "simple house" formula @ 4000 Hz (8000 Hz divided by 2, it was necessary because the JS player's minimum frequency is 8 kHz).

````
/*********************************/(0*(h = t/2)
// simple house - ern0 - 2017.02.07
// bytebeat 8 kHz -> 4 kHz 


)|1*(// drum

	3300 / (h % 2000) * 17

)|1*(// bassline
 
	h % (2000*4) < (2000*1.2) ?(
		h*4
	):0

)|1*(// tune
 
	h % 2000 > (2000*0.55) ?(
		( h*4 ) | ( 4*h * ((t/(2000*8) & 3) + 5) )
	):0 

)
````