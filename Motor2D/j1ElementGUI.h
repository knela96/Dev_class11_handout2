#ifndef __j1ElementGUI_H__
#define __j1ElementGUI_H__

#include "p2Point.h"
#include "j1Gui.h"

enum class ElementUIType {
	NONE = -1,
	BUTTON,
	CHECKBOX,
	INPUT_TEXT,
	LABEL,
	IMAGE,
	SLIDER
};

// ---------------------------------------------------
class j1ElementGUI
{
public:

	j1ElementGUI(fPoint position, ElementUIType type, SDL_Texture* graphics, j1ElementGUI* parent) : position(position), type(type), graphics(graphics), parent(parent){}

	// Destructor
	virtual ~j1ElementGUI() {}

	// Called when before render is available
	virtual bool Awake(pugi::xml_node&) { return true; }

	virtual bool Start() { return true; }

	virtual bool PreUpdate() { return true; }

	virtual bool Update() { return true; }

	virtual bool PostUpdate() { return true; }

	virtual bool CleanUp() { return true; }

	virtual void Draw() {}

	virtual void setPosition() {}

	fPoint getParentPos(j1ElementGUI* element) {
		j1ElementGUI* c_parent = element->parent;
		fPoint parent_pos = { 0,0 };
		while (c_parent != nullptr) {
			parent_pos += parent->position;
			c_parent = c_parent->parent;
		}
		return parent_pos;
	}

public:
	p2SString name;//delete?
	p2SString folder;//delete?
	fPoint position;
	ElementUIType type;
	SDL_Texture* graphics;
	j1ElementGUI* parent;
	p2List<j1ElementGUI*> childs;
};

#endif

