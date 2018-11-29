#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Input.h"
#include "j1Gui.h"
#include "j1Render.h"
#include "j1Image.h"
#include "j1Label.h"

j1Gui::j1Gui() : j1Module()
{
	name.create("gui");
}

// Destructor
j1Gui::~j1Gui()
{}

// Called before render is available
bool j1Gui::Awake(pugi::xml_node& conf)
{
	LOG("Loading GUI atlas");
	bool ret = true;

	atlas_file_name = conf.child("atlas").attribute("file").as_string("");

	return ret;
}

// Called before the first frame
bool j1Gui::Start()
{
	atlas = App->tex->Load(atlas_file_name.GetString());

	AddImage();
	AddLabel();

	return true;
}

// Update all guis
bool j1Gui::PreUpdate()
{
	return true;
}

// Called after all Updates
bool j1Gui::PostUpdate()
{
	bool ret = true;

	p2List_item<j1ElementGUI*>* item;
	for (item = elements.start; item != nullptr && ret == true; item = item->next)
	{
		item->data->Draw();
	}
	return true;
}

// Called before quitting
bool j1Gui::CleanUp()
{
	LOG("Freeing GUI");

	return true;
}

// const getter for atlas
const SDL_Texture* j1Gui::GetAtlas() const
{
	return atlas;
}

void j1Gui::AddImage()
{
	j1Image* image = new j1Image();//add position and rect
	image->rect = new SDL_Rect({ 485, 829, 328, 103 });
	image->position = { (float)(App->render->camera.w / 2 - image->rect->w / 2), 50.0f };

	j1ElementGUI* element = image;
	elements.add(element);
	
}

void j1Gui::AddLabel()
{
	j1Label* label = new j1Label("Hello World!");//add position and text
	label->position = { (float)(App->render->camera.w / 2 - label->width/2), 25.0f };

	j1ElementGUI* element = label;
	elements.add(element);

}

// class Gui ---------------------------------------------------

