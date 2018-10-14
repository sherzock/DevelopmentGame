#ifndef __j1PLAYER_H__
#define __j1PLAYER_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2Point.h"
#include "j1Module.h"
#include "p2Animations.h"

struct SDL_Texture;


class j1Player : public j1Module
{
public:

	j1Player();

	Collider* player;
	SDL_Texture* graphics = nullptr;
	// Destructor//
	virtual ~j1Player();

	// Called before render is available//
	bool Awake(pugi::xml_node& config);

	// Called before the first frame//
	bool Start();

	// Called each loop iteration//
	bool PreUpdate();
	bool Update(float dt);
	bool PostUpdate();

	// Called before quitting//
	bool CleanUp();

	// Load / Save//
	bool Load(pugi::xml_node&);
	bool Save(pugi::xml_node&) const;

	//oncollision checks if its colliding//
	void OnCollision(Collider* col_1, Collider* col_2);

public:
	
	
	Animations* current_animation = nullptr;

	// Animations of the player
	Animations idle;
	Animations run;
	Animations jumpanim;
	Animations falling;
	Animations dashanim;
	
	
	//Player positions//
	fPoint position;
	fPoint Initial_position;

	//variables
	float XSpeed;
	float initialspeed;
	float gravity;
	float Jumpforce;
	float Jumpreset;
	float gravityMax;
	float gravityIteratior;
	float JumpforceIterator;
	float DashSpeed;
	float DashSpeedres ;
	float DashAcc;
	uint currentTime;
	uint lastTime;

	//logical booleans//
	bool updatedTime = false;
	bool dead = false;
	bool win = false;
	bool GroundCollision = false;
	bool jump = false;
	bool CanPlayerJump = false;
	bool CanPlayerDash = false;
	bool isfalling = false;
	bool goingright = true;
	bool godmode = false;
	bool dash = false;
};

#endif // __jPLAYER_H__