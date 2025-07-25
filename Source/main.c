// C Libraries
#include <math.h>

// Local Libraries
#include "raylib.h"
#include "resources.h"
#include "main_menu.h"
#include "start_screen.h"

// Main Program
int main(void)
{

    InitWindow(0, 0, "Raylib Menu");
    ToggleFullscreen();
    InitResources();
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Handle input
        if (IsKeyPressed(KEY_DOWN)) gSelectedMenu = (gSelectedMenu + 1) % MENU_COUNT;
        if (IsKeyPressed(KEY_UP))   gSelectedMenu = (gSelectedMenu - 1 + MENU_COUNT) % MENU_COUNT;

        if (IsKeyPressed(KEY_ENTER)) {
            switch (gSelectedMenu) {

                case MENU_START:
                    TraceLog(LOG_INFO, "Start selected");
                    // TODO: Add your start logic here
		    CaptureMenuSnapshot();
		    RunStartScreen();
                    break;

                case MENU_CREDITS:
                    TraceLog(LOG_INFO, "Credits selected");
                    // TODO: Show credits screen
                    break;

                case MENU_EXIT:
                    CloseWindow();
                    return 0;
            }
        }
	RunMainMenu();
    }

    UnloadResources();
    CloseWindow();
    return 0;
}

