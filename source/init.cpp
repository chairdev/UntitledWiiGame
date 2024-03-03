#include "main.h"
#include "init.h"

#include "gfx/init/warning.h"

GRRLIB_texImg *bg = GRRLIB_LoadTexture(warning);

void Warning()
{
    FadeIn(bg);

    while(!fadeOut) {

        WPAD_ScanPads();  // Scan the Wiimotes

        if(WPAD_ButtonsDown(0) && !fadeOut)  // If the A button is pressed
        {
            FadeOut(bg);
            fadeOut = true;
        }
        
    }
}