#pragma once

#include "j1ElementGUI.h"

struct SDL_Rect;

class j1Image : public j1ElementGUI
{
public:
	j1Image();
	~j1Image();

	void Draw();

public:
	SDL_Rect* rect;
};