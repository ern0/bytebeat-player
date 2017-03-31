const int FREQ = 44100;
const int VOLUME_MUL = 60;
#include "bytebeat-player.cpp"


u32 t;


u32 wg(u32 mul,u32 mask) {

	u32 r = t * mul; 
	r = r >> 8;
	r = r & mask;

	return r;
}


u32 byteBeat(u32 sample) {
	t = sample;

	u32 dr = 888888 / ((t % 40000) | 1) & 0x555;

	u32 ch1 = wg(201,0xf0);

	u32 ch2 = wg(500,0x80) * 0.97;

	u32 ch3 = wg(610,0x80) * 0.98;

	u32 ch4 = wg(720,0x80) * 0.99;

	return (dr + ch1 + ch2 + ch3 + ch4) >> 2 ;

} // byteBeat()	 
