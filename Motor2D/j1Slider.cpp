#include "j1App.h"
#include "j1Render.h"
#include "j1Slider.h"
#include "j1Input.h"
#include "p2Log.h"
#include "j1ElementGUI.h"


j1Slider::j1Slider(fPoint position, OrientationType orientation, SDL_Texture* graphics, j1ElementGUI* parent, ElementUIType type) :
	orientation(orientation),
	j1ElementGUI(position, type, graphics, parent)
{
	slide_rect = new SDL_Rect({ 0,0,0,0 });
	thumb_rect = new SDL_Rect({ 0,0,0,0 });
	//thumb = new j1Button({ 0,0 }, nullptr, slide_rect, nullptr, nullptr, graphics, (j1ElementGUI*)this);
	//childs.add(thumb);
}


j1Slider::~j1Slider()
{}

void j1Slider::Update(float dt)
{
	iPoint mouse;
	App->input->GetMousePosition(mouse.x, mouse.y);
	if (mouse.x >= position.x && mouse.x < thumb_rect->w + position.x && mouse.y >= position.y && mouse.y < thumb_rect->h + position.y) {
		if (App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_DOWN) {
			o_mouse = mouse;
		}
		if(App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_REPEAT) {
			slide_pos = { mouse.x - o_mouse.x, mouse.y - o_mouse.y };
		}
	}
}

void j1Slider::Draw()
{
	fPoint parent_pos = getParentPos(this);
	App->render->Blit(graphics, parent_pos.x + position.x, parent_pos.y + position.y, slide_rect, 0.0f);
}

