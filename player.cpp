#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>


const int FREQ = 44100;


	void audioCallback(void* userdata,Uint8* stream,int len);


	int main(int argc,char* argv[]) {

		SDL_AudioSpec want;
		SDL_AudioSpec have;
		SDL_AudioDeviceID dev;

		SDL_Init(SDL_INIT_AUDIO);

		SDL_zero(want);
		want.freq = FREQ;
		want.format = AUDIO_U8;
		want.channels = 1;
		want.samples = 4096;
		want.callback = audioCallback;
		dev = SDL_OpenAudioDevice(NULL,0,&want,&have,0);

		if (dev == 0) {
	    SDL_Log("Failed to open audio: %s",SDL_GetError());
	    return 2;
		}

		SDL_PauseAudioDevice(dev,0);
		SDL_Delay(1000);
		SDL_CloseAudioDevice(dev);

		return 0;
	} // main()


	void audioCallback(void* userdata,Uint8* stream,int len) {

	} // audioCallback()
