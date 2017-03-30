const int FREQ = 1000;
const int VOLUME_MUL = 50;
#include "bytebeat-player.cpp"

u32 byteBeat(u32 t) {

	u32 drum = divnz(512,modnz(t,400)) * 8;
	u32 hihat = divnz(256,modnz(t,200)) & 0x0f * 8;
	static u8 bassdata[] = {
		60,0,60,0,60,56,60,72,
		60,0,60,0,60,56,60,72,
		60,0,60,0,60,56,60,72,
		40,0,40,0,48,40,48,56
	};
	u32 bassline = t / 2 * bassdata[t / 200 & 31];
	static u8 songdata[] = {
		90,0,90,0,0,107,0,107,
		90,0,90,0,0,107,0,107,
		90,0,90,0,0,107,0,90,
		120,0,120,0,136,0,136,0
	};
	u32 song = (t * songdata[t / 200 & 31]) & 0x80;

	return drum | hihat | bassline | song;
} // byteBeat()
