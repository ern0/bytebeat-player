#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>


const int FREQ = 8000;
const int VOLUME_MUL = 50;


	uint32_t audioSample = 0;
	
	void audioCallback(void* userdata,unsigned char* stream,int len);
	uint32_t byteBeat(uint32_t sample);
	uint32_t divnz(uint32_t a,uint32_t b);
	uint32_t modnz(uint32_t a,uint32_t b);


	int main(int argc,char* argv[]) {

		SDL_AudioSpec want;
		SDL_AudioSpec have;
		SDL_AudioDeviceID dev;

		SDL_Init(SDL_INIT_AUDIO);

		SDL_zero(want);
		want.freq = FREQ;
		want.format = AUDIO_S16SYS;
		want.channels = 1;
		want.samples = 4096;
		want.callback = audioCallback;
		want.userdata = (void*)&audioSample;
		dev = SDL_OpenAudioDevice(NULL,0,&want,&have,0);

		if (dev == 0) {
	    SDL_Log("Failed to open audio: %s",SDL_GetError());
	    return 2;
		}

		SDL_PauseAudioDevice(dev,0);
		fprintf(stderr,"playing... ");
		SDL_Delay(30000);
		fprintf(stderr,"\n");
		exit(0);
		
		// was:
		SDL_CloseAudioDevice(dev);
		return 0;
	} // main()


	void audioCallback(void* userdata,unsigned char* stream,int len) {
		uint32_t* samplePtr = (uint32_t*)userdata;

		for (int i = 0; i < len; i += 2) {

			uint32_t sample = *samplePtr;
			uint32_t result = byteBeat(sample) & 0xFF;

			uint32_t* store = (uint32_t*)&stream[i];
			*store = result * VOLUME_MUL;

			(*samplePtr)++;

		} // for stream

	} // audioCallback()


	uint32_t divnz(uint32_t a,uint32_t b) {
		if (b == 0) return 0;
		return a / b;
	} // divnz()


	uint32_t modnz(uint32_t a,uint32_t b) {
		if (b == 0) return 0;
		return a % b;
	} // modnz()


	uint32_t byteBeat(uint32_t t) {
 
		uint32_t h = t / 2;

		uint32_t drum = divnz(3300,modnz(h,2000)) * 17;

		uint32_t bassline = ( modnz(h,2000*4) < (2000*1.2) ? h*4 : 0 );

		uint32_t tunfm = (h*4) | ( 4*h * (( divnz(t,2000*8) & 3) + 5) );
		uint32_t tune = ( modnz(h,2000) > (2000*0.55) ? tunfm : 0 ); 

		return drum | bassline | tune;

	} // byteBeat()
