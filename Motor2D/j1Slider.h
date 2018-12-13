#pragma once

#include "j1ElementGUI.h"
#include "j1Button.h"
#include "p2Point.h"

enum OrientationType {
	HORIZONTAL,
	VERTICAL
};
class j1Slider : public j1ElementGUI
{
public:
	j1Slider(fPoint position, OrientationType orientation, SDL_Texture* graphics = nullptr, j1ElementGUI* parent = nullptr, ElementUIType type = ElementUIType::SLIDER);
	~j1Slider();

	void Update(float dt);

	void Draw();

public:
	OrientationType orientation;
	iPoint o_mouse;
	iPoint slide_pos; //0 to 1  pos/height * 100
	SDL_Rect* slide_rect;
	SDL_Rect* thumb_rect;
	uint slide_value;
	j1Label* text;
	//j1Button* thumb;
	//SDL_Rect* text_rect;
	//p2SString text;
};