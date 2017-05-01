# bytebeat-player


## What is it?
It's a very simple **bytebeat** player, using SDL2 (tested on MacOS and Linux/Ubuntu). 
 
Bytebeat is a method for producing music. The music is produced by a function, which calculates the actual sample value from the time tick value:

````
byte sample = funct(int tick)
````
You can read more about it in post: [Algorithmic symphonies from one line of code -- how and why?](http://countercomplex.blogspot.hu/2011/10/algorithmic-symphonies-from-one-line-of.html) - Don't miss the videos!


## Create your own music!

**Step 1**: Create your music as a separate `.cpp` file in `song/` directory. This is my "simple house" formula, you can find it in `song/simple_house.cpp`:
````
const int FREQ = 4000;
const int VOLUME_MUL = 50;

#include "bytebeat-player.cpp"

u32 byteBeat(u32 t) {

  u32 drum = divnz(3300,modnz(t,2000)) * 17;
  u32 bassline = ( modnz(t,2000*4) < (2000*1.2) ? t*4 : 0 );
  u32 tunfm = (t*4) | ( 4*t * (( divnz(t,2000*8) & 3) + 5) );
  u32 tune = ( modnz(t,2000) > (2000*0.55) ? tunfm : 0 );

  return drum | bassline | tune;
} 
````
Frequency value should be 44100 for best result. As you see, I've defined a short `u32` alias for `uint32_t`.

**Step 2:** modify launcher script file called `s`, change the name of the executable to your source file name, but without `.cpp` extension:
````
#/bin/bash
bin/simple_house
````

**Step 3:** Compile by executing script called `p`. It will parse script `s` to find out which song to include, and will create the result in the `bin/` directory.

Note the size of the result!
````
ern0@optiplex:~/work/bytebeat-player$ ll bin/simple_house
-rwxrwxr-x 1 ern0 ern0 14K May  1 19:02 bin/simple_house*
````

**Step 4:** Launch your music by executing script `s` - enjoy!

````
ern0@optiplex:~/work/bytebeat-player$ s
playing...
````

## See also

There is a HTML5 web player: [Simple House, web version](http://greggman.com/downloads/examples/html5bytebeat/html5bytebeat.html#t=0&e=0&s=44100&bb=5d000001001e0100000000000000178ab30e178a76cebf472739cb3983b85915a749da626ff6b08ea8be9ce41f78fa969f4c48c4487ee686a6425ffdcaad464a2f34fe3631c8898fcb400ad94ccc34a751ebbd51fee1f872df7a89aec6060df43d5196dc3a87b33cacb5380d1d55ee7b2b20b443e564eee08357f13d627ac2598b26b72231bccfc2ee96705d20db438e36785354f576a99296177c946c4ef71f49d643c0256cda84335688b66d2437cf44f91486efb44fc32e1b139338fe6682f1a99566440ffff98eb200)