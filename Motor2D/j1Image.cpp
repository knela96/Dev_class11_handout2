#include "j1App.h"
#include "j1Image.h"
#include "j1ElementGUI.h"
#include "j1Render.h"
#include "j1Gui.h"
#include "p2Log.h"

#include "SDL/include/SDL.h"

j1Image::j1Image() : j1ElementGUI()
{
	graphics = (SDL_Texture*)App->gui->GetAtlas();
}


j1Image::~j1Image()
{
	delete rect;
	rect = nullptr;
}

void j1Image::Draw()
{
	App->render->Blit(graphics, position.x, position.y, rect, 0.0f);
	LOG("IMAGE: %f, %f", position.x, position.y);
}
