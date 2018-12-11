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
#include "j1Button.h"


void action()
{
	LOG("Value of aaaaaa");
}

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
	
	SDL_Rect* rect = new SDL_Rect({ 0, 0,328,103 });
	fPoint pos = { 200.0f, 50.0f };
	AddImage(pos,rect); 
	SDL_Rect* anim = new SDL_Rect({ 0,0,400,103 });
	AddButton(pos, "BUTTON", rect, anim, &action);
	

	return true;
}

// Update all guis
bool j1Gui::PreUpdate()
{
	return true;
}

bool j1Gui::Update(float dt) {

	bool ret = true;
	p2List_item<j1ElementGUI*>* item;
	for (item = elements.start; item != nullptr && ret == true; item = item->next)
	{
		item->data->Update();
	}
	return ret;
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
	return ret;
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

void j1Gui::AddImage(fPoint pos, SDL_Rect* rect)
{
	j1Image* image = new j1Image(pos,rect, (SDL_Texture*)GetAtlas());

	j1ElementGUI* element = image;
	elements.add(element);
	
}

void j1Gui::AddLabel(fPoint pos, p2SString text)
{
	j1Label* label = new j1Label(pos,text);//add position and text

	j1ElementGUI* element = (j1ElementGUI*)label;
	elements.add(element);
}

void j1Gui::AddButton(fPoint pos, p2SString text, SDL_Rect* rect, SDL_Rect* anim, void(*action)(void)) {
	j1Button* button = new j1Button(pos, text, rect, anim, action, (SDL_Texture*)GetAtlas());

	j1ElementGUI* element = button;
	elements.add(element);
}

// class Gui ---------------------------------------------------

