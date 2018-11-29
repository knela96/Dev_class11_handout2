#pragma once

#include "j1ElementGUI.h"


struct SDL_Rect;
class j1Label : public j1ElementGUI
{
public:
	j1Label(p2SString text);
	~j1Label();

	void Draw();

public:
	p2SString text;
	int height;
	int width;
};

