#include <gccore.h>
#include <wiiuse/wpad.h>
#include <grrlib.h>

#include "Player.h"

int main(int argc, char **argv)
{
    GRRLIB_Init();
    WPAD_Init();

    Player player;

    bool menu = true;

    while (1)
    {
        WPAD_ScanPads();

        u32 pressed = WPAD_ButtonsDown(0);
        u32 held = WPAD_ButtonsHeld(0);

        if (pressed & WPAD_BUTTON_HOME)
            break;

        GRRLIB_FillScreen(0x87CEEBFF);

        if (menu)
        {
            GRRLIB_Printf(220, 150, NULL, 0xFFFFFFFF, 2.0f,
                          "WIIFORMER");

            GRRLIB_Printf(180, 250, NULL, 0xFFFFFFFF, 1.5f,
                          "Pressione A para iniciar");

            if (pressed & WPAD_BUTTON_A)
                menu = false;
        }
        else
        {
            if (held & WPAD_BUTTON_LEFT)
                player.MoveLeft();

            if (held & WPAD_BUTTON_RIGHT)
                player.MoveRight();

            if (pressed & WPAD_BUTTON_A)
                player.Jump();

            player.Update();

            // Chao
            GRRLIB_Rectangle(
                0, 400,
                640, 80,
                0x00AA00FF,
                true);

            // Jogador
            GRRLIB_Rectangle(
                player.x,
                player.y,
                32,
                32,
                0xFF0000FF,
                true);
        }

        GRRLIB_Render();
    }

    GRRLIB_Exit();
    return 0;
}
