

#include "main.h"
#include "init.h"


#include "oggplayer.h"
#include <asndlib.h>

#include "init_ogg.h"

bool fadeOut = false;

#define SYS_NOTSET          -1
#define SYS_RETURNTOHBMENU   7


/**
 * Hardware button state.
 */
s32 HWButton = SYS_NOTSET;

void FadeIn(GRRLIB_texImg *img)
{
    for (int i = 0; i < 255; i+=4)
    {
        GRRLIB_FillScreen(0xFFFFFFFF);
        GRRLIB_DrawImg(0, 0, img, 0, 1, 1, 0xFFFFFF00|i);
        GRRLIB_Render();  // Render the frame buffer to the TV

    }
}

void FadeOut(GRRLIB_texImg *img)
{
    fadeOut = true;
    for (int i = 255; i > 0; i-=4)
    {
        GRRLIB_FillScreen(0xFFFFFFFF);
        GRRLIB_DrawImg(0, 0, img, 0, 1, 1, 0xFFFFFF00|i);
        GRRLIB_Render();  // Render the frame buffer to the TV

    }
}

void WiiPowerPressed()
{
    HWButton = SYS_POWEROFF_STANDBY;
}


int main(int argc, char **argv) {
    // Initialise the audio subsystem
	ASND_Init();

    // Initialise the Graphics & Video subsystem
    GRRLIB_Init();

     // Set the video mode
    GXRModeObj *rmode = VIDEO_GetPreferredMode(NULL);
    VIDEO_Configure(rmode);
    // Tell the video hardware where our display memory is
	VIDEO_SetNextFramebuffer(xfb);

	// Make the display visible
	VIDEO_SetBlack(false);

	// Flush the video register changes to the hardware
	VIDEO_Flush();

	// Wait for Video setup to complete
	VIDEO_WaitVSync();
	if(rmode->viTVMode&VI_NON_INTERLACE) VIDEO_WaitVSync();

    // Initialise the Wiimotes
    WPAD_Init();



    // Initialise system callbacks
    SYS_SetPowerCallback(WiiPowerPressed);

    Warning();
    PlayOgg(init_ogg, init_ogg_size, 0, OGG_ONE_TIME);

    // Loop forever
    while(1) {

        WPAD_ScanPads();  // Scan the Wiimotes

        // If [HOME] was pressed on the first Wiimote, break out of the loop
        if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME)  break;

        

        if (HWButton != SYS_NOTSET)
        {
            break;
        }
        
    }

    GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB
    StopOgg();

    if(HWButton == SYS_POWEROFF_STANDBY)
            SYS_ResetSystem(SYS_POWEROFF_STANDBY, 0, 0);
        else if(HWButton == SYS_RETURNTOHBMENU)
            SYS_ResetSystem(SYS_RETURNTOMENU, 0, 0);

    exit(0);  // Use exit() to exit a program, do not use 'return' from main()
}