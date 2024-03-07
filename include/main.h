#include <grrlib.h>

#include <stdlib.h>
#include <wiiuse/wpad.h>
#include <gccore.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <asndlib.h>
#include "oggplayer.h"

#include <string>
#include <vector>

//#include "warning.h"

#include "orbit/ecs/entity.h"

extern std::vector<Entity*> entities;


extern int screenWidth;
extern int screenHeight;

extern bool fadeOut;

void FadeIn(GRRLIB_texImg *img);
void FadeOut(GRRLIB_texImg *img);
void CreateEntity(string name);

