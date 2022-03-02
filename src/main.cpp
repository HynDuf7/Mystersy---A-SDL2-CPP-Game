#include <SDL.h>
#include <game.h>
#include <SDL.h>

const int FPS = 60;
const int FRAME_MAX_DELAY = 1000 / FPS;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 640;
const Uint8 *keyboard_state = SDL_GetKeyboardState(NULL);
Game *game = nullptr;
Uint32 frame_start;
int frame_time;
int main(int argc, char *argv[])
{
    game = new Game();
    game->Init("Knighty", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);
    while (game->Running())
    {
        frame_start = SDL_GetTicks();
        game->HandleEvents();
        game->Update(); 
        game->Render();
        frame_time = SDL_GetTicks() - frame_start;
        if (frame_time < FRAME_MAX_DELAY)
        {
            SDL_Delay(FRAME_MAX_DELAY - frame_time);
        }
    }
    game->Clean();
    return 0;
}