#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>

#define WIDTH 900
#define HEIGHT 600
#define TARGET_FPS 60

int main(){
	bool done=false;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *window=SDL_CreateWindow(
		"Ultra pain",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WIDTH,
		HEIGHT,
		0		
	);
	if(window==NULL){
		SDL_LogError(SDL_LOG_CATEGORY_ERROR,"Could not create window: %s\n",SDL_GetError());
		return 1;
	}
	SDL_Surface *surface=SDL_GetWindowSurface(window);
	float delay_millis=(1.0/TARGET_FPS)*1000;
	int x;
	int y;
	bool draw=false;
	while(!done){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_QUIT:
					done=true;
					break;
				case SDL_MOUSEMOTION:
					draw=true;
			}
			if(draw){
				x=event.motion.x;
				y=event.motion.y;
				SDL_Rect rect={x,y,10,10};
                		SDL_FillRect(surface,&rect,0x00FFFF00);
                		SDL_UpdateWindowSurface(window);
			}
		}
		//SDL_Rect rect={50,50,100,100};
        	//SDL_FillRect(surface,&rect,0x00FFFF00);
        	//SDL_UpdateWindowSurface(window);
		SDL_Delay(delay_millis);
		}


}
