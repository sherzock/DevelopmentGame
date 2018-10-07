#ifndef __j1PLAYER_H__
#define __j1PLAYER_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2Point.h"
#include "j1Module.h"

struct SDL_Texture;


class j1Player : public j1Module
{
public:

	j1Player();

	SDL_Rect* player;
	
	// Destructor
	virtual ~j1Player();

	// Called before render is available
	bool Awake(pugi::xml_node& config);

	// Called before the first frame
	bool Start();

	// Called each loop iteration
	bool PreUpdate();
	bool Update(float dt);
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	// Load / Save
	bool Load(pugi::xml_node&);
	bool Save(pugi::xml_node&) const;

public:
	// To know the last direction the character was moving to
	fPoint position;

	float XSpeed = 0.22f;
	float InitialYSpeed = -0.22f;
	float YSpeed = -0.22f;
	float gravity = 0.02f;;

	uint currentTime;
	uint lastTime;

	bool updatedTime = false;
	bool dead = false;
};

#endif // __jPLAYER_H__
