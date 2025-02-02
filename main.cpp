#include <pspkernel.h>
#include <pspaudio.h>
#include <pspaudiolib.h>
#include <SDL.h>
#include <SDL_mixer.h>
void setupPSP() {
    pspDebugScreenInit();
    pspAudioInit();
}
int main(int argc,char *argv[]) {
    setupPSP();
    SDL_Init(SDL_INIT_AUDIO);
    Mix_OpenAudio(22050,AUDIO_S16SYS,2,512);

    Mix_Music *music = Mix_LoadMUS("test.mp3");
    if (!music) {
        pspDebugScreenPrintf("Error: Failed to load music: %\n",Mix_GetError());
        return 1;
    }
    Mix_PlayMusic(music,-1);
    pspDebugScreenPrintf("Playing TEST.mp3 Press [X] to exit\n");
    
    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym ==SDLK_x) {
                    running = 0;
                }
            }
        }
        SDL_Delay(50);
    }
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();
    pspAudioEnd();
    sceKernelExitGame();
    return 0;
}