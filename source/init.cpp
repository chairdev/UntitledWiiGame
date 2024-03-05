#include "main.h"
#include "init.h"

#include "oggplayer.h"

#include "init.h"
#include "init_ogg.h"


GRRLIB_texImg *bg = GRRLIB_LoadTexture(warning);




void Warning()
{
    FadeIn(bg);

    while(!fadeOut) {

        WPAD_ScanPads();  // Scan the Wiimotes

        if(WPAD_ButtonsDown(0) && !fadeOut)  // If the A button is pressed
        {
            PlayOgg(init_ogg, init_ogg_size, 0, OGG_ONE_TIME);
            FadeOut(bg);
            fadeOut = true;
        }
        
    }
}