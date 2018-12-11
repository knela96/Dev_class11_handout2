#include "j1App.h"
#include "j1Image.h"
#include "j1ElementGUI.h"
#include "j1Render.h"
#include "j1Gui.h"
#include "p2Log.h"

j1Image::j1Image(fPoint position, SDL_Rect* rect, SDL_Texture* graphics, j1ElementGUI* parent, ElementUIType type) :
	rect(rect),
	j1ElementGUI(position, type, graphics, parent) {}


j1Image::~j1Image(){}

void j1Image::Draw()
{
	App->render->Blit(graphics, position.x, position.y, rect, 0.0f);
	//LOG("IMAGE: %f, %f", position.x, position.y);
}
