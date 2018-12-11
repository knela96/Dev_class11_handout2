#include "j1App.h"
#include "j1Render.h"
#include "j1Label.h"
#include "j1Fonts.h"
#include "p2Log.h"


j1Label::j1Label(fPoint position, p2SString text, SDL_Texture* graphics, j1ElementGUI* parent, ElementUIType type) :
	text(text),
	j1ElementGUI(position,type,graphics,parent)
{
	this->graphics = App->font->Print(text.GetString());
	App->font->CalcSize(text.GetString(), width, height);
}


j1Label::~j1Label()
{}

void j1Label::Draw()
{
	fPoint parent_pos = getParentPos(this);
	App->render->Blit(graphics,parent_pos.x + position.x, parent_pos.y + position.y, nullptr, 0.0f);
	LOG("LABEL: %f, %f", parent_pos.x + position.x, parent_pos.y + position.y);
}

