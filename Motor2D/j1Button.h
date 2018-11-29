#pragma once

#include "j1ElementGUI.h"

struct SDL_Rect;

class j1Button : public j1ElementGUI
{
public:
	j1Button();
	~j1Button();

	void Draw();

	void onClick();

public:
	bool clicked = false;
	p2SString label;
	SDL_Rect* rect;
};

