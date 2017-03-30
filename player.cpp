#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>


const int FREQUENCY = 44100;


	int main(int argc,char* argv[]) {

		SDL_Init(SDL_INIT_AUDIO);
		printf("oh, hai \n");
		SDL_Delay(1000);

		return 0;
	} // main()