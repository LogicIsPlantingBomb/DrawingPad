#include <stdio.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define COLOR_WHITE 0xFFFFFFFF
#define COLOR_BLACK 0x00000000
#define COLOR_BLUE 0x34c3eb
#define COLOR_GRAY 0x1f1f1f1f
#define CELL_SIZE 5
#define LINE_WIDTH 2
#define COLUMNS SCREEN_WIDTH / CELL_SIZE
#define ROWS SCREEN_HEIGHT / CELL_SIZE

void draw_grid(SDL_Surface *surface)
{
    for (int i = 0; i < COLUMNS; i++)
    {
        SDL_Rect column = (SDL_Rect){i * CELL_SIZE, 0, LINE_WIDTH, SCREEN_HEIGHT};
        SDL_FillRect(surface, &column, COLOR_GRAY);
    }
    for (int i = 0; i < ROWS; i++)
    {
        SDL_Rect row = (SDL_Rect){0, i * CELL_SIZE, SCREEN_WIDTH, LINE_WIDTH};
        SDL_FillRect(surface, &row, COLOR_GRAY);
    }
}

void color_cell(SDL_Surface *surface, int x, int y)
{
    int pixel_x = x * CELL_SIZE;
    int pixel_y = y * CELL_SIZE;
    SDL_Rect cell_rect = (SDL_Rect){pixel_x, pixel_y, CELL_SIZE, CELL_SIZE};
    SDL_FillRect(surface, &cell_rect, COLOR_WHITE);
}

void clear_surface(SDL_Surface *surface)
{
    SDL_FillRect(surface, NULL, COLOR_BLACK); // Fill screen with black
    draw_grid(surface);                       // Redraw grid
}

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Drawing Pad", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    SDL_Surface *surface = SDL_GetWindowSurface(window);

    clear_surface(surface);
    SDL_UpdateWindowSurface(window);

    int simulation_running = 1;
    SDL_Event event;
    while (simulation_running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                simulation_running = 0;
            }
            if (event.type == SDL_MOUSEMOTION)
            {
                if (event.motion.state != 0)
                {
                    int cell_x = event.motion.x / CELL_SIZE;
                    int cell_y = event.motion.y / CELL_SIZE;
                    color_cell(surface, cell_x, cell_y);
                }
            }
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_r)
                {
                    clear_surface(surface);
                }
            }
        }

        SDL_UpdateWindowSurface(window);
        SDL_Delay(10);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

