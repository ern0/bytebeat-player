const int FREQ = 4000;
const int VOLUME_MUL = 60;
#include "bytebeat-player.cpp"

u32 byteBeat(u32 t) {

	u32 tempo = 0x0440;

	u32 beat = t & 0x07ff;
	beat = beat | 1;

	u32 drum = tempo / beat;
	drum = drum << 5;

	u32 basswave = t & 0x30;
	basswave = basswave << 2;

	u32 bass = (t & tempo ? basswave : 0);

	return drum | bass;
} // byteBeat()	 
