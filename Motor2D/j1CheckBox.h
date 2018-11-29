#pragma once

#include "j1ElementGUI.h"

struct SDL_Rect;

class j1CheckBox : public j1ElementGUI
{
public:
	j1CheckBox();
	~j1CheckBox();

	void onClick();

public:
	bool active = false;
	p2SString label;
	SDL_Rect* rect;
};

