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
	label = new j1Label({ 0 ,0 },text,nullptr,this);
	label->position = {(float) rect->w / 2 - label->width / 2,(float)rect->h / 2 - label->height / 2};
}


j1Button::~j1Button()
{
	delete rect;
	rect = nullptr;
	delete anim;
	rect = nullptr;
}

bool j1Button::Update() {
	

	return true;
}

void j1Button::Draw()
{
	iPoint mouse;
	App->input->GetMousePosition(mouse.x, mouse.y);

	LOG("x:%i y:%i", mouse.x, mouse.y);
	LOG("x:%i y:%i w:%i h:%i", rect->x, rect->y, rect->w, rect->h);
	if (mouse.x >= position.x && mouse.x < rect->w + position.x && mouse.y >= position.y && mouse.y < rect->h + position.y) {
		if (App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_DOWN || App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_REPEAT)
			onClick();
		else if (App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_UP)
			onAction();
		else
			onHover();
	}
	else {
		LOG("DRAW");
	}
	/*
	Blit code
	*/
	label->Draw();//last
}

void j1Button::onHover()
{
	LOG("HOVER");//HIGHLIGHT TEXTURE
}

void j1Button::onClick()
{
	LOG("CLICK");//PRESSED TEXTURE
}

void j1Button::onAction()
{
	LOG("ACTION");//PRESSED TEXTURE
	action();
}