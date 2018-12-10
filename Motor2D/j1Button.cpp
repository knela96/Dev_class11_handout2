#include "j1App.h"
#include "j1Button.h"
#include "j1ElementGUI.h"
#include "j1Render.h"
#include "j1Input.h"
#include "j1Gui.h"
#include "p2Log.h"



j1Button::j1Button(fPoint position, p2SString text, SDL_Rect* rect, SDL_Rect* anim, SDL_Texture* graphics, j1ElementGUI* parent, ElementUIType type) :
	rect(rect),
	anim(anim),
	j1ElementGUI(position, type, graphics, parent)
{
	label = new j1Label({ 0,0 },text);

	this->graphics = (SDL_Texture*)App->gui->GetAtlas();
}


j1Button::~j1Button()
{
	delete rect;
	rect = nullptr;
	delete anim;
	rect = nullptr;
}

bool j1Button::Update() {
	iPoint mouse;
	App->input->GetMousePosition(mouse.x, mouse.y);
	if (mouse.x >= rect->x && mouse.y < rect->w + rect->x && mouse.y >= rect->y && mouse.y < rect->h + rect->y) {
		if (App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_DOWN || App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_REPEAT)
			onClick();
		else if (App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_UP)
			nullptr;
		else
			onHover();
	}
	else
		Draw();

	return true;
}

void j1Button::Draw()
{
	label->Draw();//last
}

void j1Button::onHover()
{

}

void j1Button::onClick()
{

}
