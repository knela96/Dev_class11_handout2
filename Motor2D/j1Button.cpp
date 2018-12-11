#include "j1App.h"
#include "j1Button.h"
#include "j1ElementGUI.h"
#include "j1Render.h"
#include "j1Input.h"
#include "j1Gui.h"
#include "p2Log.h"



j1Button::j1Button(fPoint position, p2SString text, SDL_Rect* rect, SDL_Rect* anim, void(*action)(void), SDL_Texture* graphics, j1ElementGUI* parent, ElementUIType type) :
	rect(rect),
	anim(anim),
	action(action),
	j1ElementGUI(position, type, graphics, parent)
{
	label = new j1Label({ 0 ,0 },text,nullptr,this);
	label->position = {(float) rect->w / 2 - label->width / 2,(float)rect->h / 2 - label->height / 2};
	childs.add((j1ElementGUI*) label);
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
		//CHANGE TEXTURE TO DEFAULT TEXTURE
	}
	return true;
}

void j1Button::Draw()
{
	/*
	Blit code of image button
	*/

	p2List_item<j1ElementGUI*>* item;
	for (item = childs.start; item != nullptr; item = item->next)
	{
		item->data->Draw();
	}
}

void j1Button::onHover()
{
	LOG("HOVER");//CHANGE TEXTURE TO HIGHLIGHT TEXTURE  graphics = animation.getFrameAt(0);
}

void j1Button::onClick()
{
	LOG("CLICK");//CHANGE TEXTURE TO PRESSED TEXTURE
}

void j1Button::onAction()
{
	LOG("ACTION");//CHANGE TEXTURE TO PRESSED TEXTURE
	action();
}