#pragma once

#include "j1ElementGUI.h"

class j1Image : public j1ElementGUI
{
public:
	j1Image(fPoint position,SDL_Rect* rect, SDL_Texture* graphics = nullptr, j1ElementGUI* parent = nullptr, ElementUIType type = ElementUIType::LABEL);
	~j1Image();

	void Draw();

public:
	SDL_Rect* rect;
};