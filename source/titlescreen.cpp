#include "main.h"
#include "titlescreen.h"

#include "SolProBold_ttf.h"

void TitleScreen()
{
     // Load the font from memory
    GRRLIB_ttfFont *titleFont = GRRLIB_LoadTTF(SolProBold_ttf, SolProBold_ttf_size);

    //FadeIn(bg);
    //GRRLIB_SetBackgroundColour(0x00, 0x00, 0x00, 0xFF);

    int textWidth = GRRLIB_WidthTTF(titleFont, "Untitled Wii Game", 32);

    while(1) {

        WPAD_ScanPads();  // Scan the Wiimotes

        if(WPAD_ButtonsDown(0) && !fadeOut)  // If the A button is pressed
        {
          
        }
        
        
        GRRLIB_PrintfTTF(screenHeight/2, (screenWidth/2)-textWidth, titleFont, "Untitled Wii Game", 32, 0xFFFFFFFF);
        GRRLIB_Render();  // Render the frame buffer to the TV
    }
}