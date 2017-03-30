#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>


const int FREQ = 44100;
const int VOLUME_MUL = 30;


	uint32_t audioSample = 0;
	
	void audioCallback(void* userdata,unsigned char* stream,int len);
	uint32_t byteBeat(uint32_t sample);


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
		fprintf(stderr,"beep... ");
		SDL_Delay(400);
		fprintf(stderr,"\n");
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


	uint32_t byteBeat(uint32_t t) {


		return t;
	} // byteBeat()
