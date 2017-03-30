#include <stdio.h>
#include <stdint.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>


	typedef uint32_t u32;
	typedef uint16_t u16;
	typedef uint8_t u8;

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
		want.freq = 44100;
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

		fprintf(stderr,"playing... ");
		SDL_PauseAudioDevice(dev,0);
		SDL_Delay(55000);

		fprintf(stderr,"\n");
		SDL_PauseAudioDevice(dev,1);
		SDL_CloseAudioDevice(dev);

		return 0;
	} // main()


	void audioCallback(void* userdata,unsigned char* stream,int len) {
		uint32_t* samplePtr = (uint32_t*)userdata;

		for (int i = 0; i < len; i += 2) {

			uint32_t sample = *samplePtr / (44100 / FREQ);
			uint32_t result = byteBeat(sample) & 0xFF;

			uint16_t* store = (uint16_t*)&stream[i];
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
