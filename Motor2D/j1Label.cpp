#include "j1App.h"
#include "j1Render.h"
#include "j1Label.h"
#include "j1Fonts.h"
#include "p2Log.h"


j1Label::j1Label(p2SString text)
{
	this->text = text;
	graphics = App->font->Print(text.GetString());
	App->font->CalcSize(text.GetString(), width, height);
}


j1Label::~j1Label()
{
}

void j1Label::Draw()
{
	App->render->Blit(graphics, position.x, position.y, nullptr, 0.0f);
	LOG("LABEL: %f, %f", position.x, position.y);
}

