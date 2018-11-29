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
	IMAGE
};

// ---------------------------------------------------
class j1ElementGUI
{
public:

	j1ElementGUI() {}

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

	virtual void OnClick() {}

	virtual void setPosition() {}

public:
	p2SString name;
	p2SString folder;
	fPoint position;
	ElementUIType type;
	SDL_Texture* graphics;
};

#endif

