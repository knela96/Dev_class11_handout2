#pragma once

#include "j1ElementGUI.h"
#include "j1Label.h"
//
//enum status {
//	OUT,
//	IN,
//	CLICKED
//};

struct SDL_Rect;

class j1Button : public j1ElementGUI
{
public:
	j1Button(fPoint pos, p2SString text, SDL_Rect* rect, SDL_Rect* anim, SDL_Texture* graphics = nullptr, j1ElementGUI* parent = nullptr, ElementUIType type = ElementUIType::BUTTON);
	~j1Button();

	bool Update();

	void Draw();

	void onHover();
	void onClick();

public:
	bool clicked = false;
	j1Label* label;
	SDL_Rect* rect;
	SDL_Rect* anim;
	j1ElementGUI* parent;
};

