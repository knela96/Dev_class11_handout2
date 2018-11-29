#pragma once

#include "j1ElementGUI.h"

struct SDL_Rect;

class j1InputText : public j1ElementGUI
{
public:
	j1InputText();
	~j1InputText();

public:
	SDL_Rect* rect;
	p2SString text;
};

