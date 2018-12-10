#pragma once

#include "j1ElementGUI.h"

class j1Label : public j1ElementGUI
{
public:
	j1Label(fPoint position, p2SString text, ElementUIType type = ElementUIType::LABEL, SDL_Texture* graphics = nullptr, j1ElementGUI* parent = nullptr);
	~j1Label();

	void Draw();

public:
	p2SString text;
	int height;
	int width;
};

