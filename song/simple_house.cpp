const int FREQ = 4000;
const int VOLUME_MUL = 50;
#include "bytebeat-player.cpp"

u32 byteBeat(u32 t) {

	u32 drum = divnz(3300,modnz(t,2000)) * 17;

	u32 bassline = ( modnz(t,2000*4) < (2000*1.2) ? t*4 : 0 );

	u32 tunfm = (t*4) | ( 4*t * (( divnz(t,2000*8) & 3) + 5) );
	u32 tune = ( modnz(t,2000) > (2000*0.55) ? tunfm : 0 ); 

	return drum | bassline | tune;

} // byteBeat()
