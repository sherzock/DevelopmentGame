#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Textures.h"
#include "j1Input.h"
#include "j1Player.h"
#include "j1Render.h"
#include "j1Collisions.h"



j1Player::j1Player() : j1Module(){
		

	name.create("player");
}

j1Player::~j1Player() {}


bool j1Player::Awake(pugi::xml_node& config) {
	
	position.x = config.child("position").attribute("x").as_int();
	position.y = config.child("position").attribute("y").as_int();

	return true;
}


bool j1Player::Start() {
	
	graphics = App->tex->Load("textures/magenta.jpg");

	position.x = 300;
	position.y = 300;
	
	player = App->colls->AddCollider({ (int)position.x, (int)position.y, 22, 25 }, PLAYER_COLLIDER, this);

	return true;
}


bool j1Player::PreUpdate() {

	return true;
}

bool j1Player::Update(float dt) {

	
	// Direction controls
	if (App->input->GetKey(SDL_SCANCODE_D) == j1KeyState::KEY_REPEAT) {
		position.x += XSpeed;
	}

	if (App->input->GetKey(SDL_SCANCODE_A) == j1KeyState::KEY_REPEAT) {
		position.x -= XSpeed;
	}

	

		
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == j1KeyState::KEY_REPEAT && position.y < 1000) {
		
		while (YSpeed < 0) {
			jump == true;
			position.y += YSpeed;
			YSpeed += 0.001f;
		}
		YSpeed = -0.022f;
		jump == false;
	}

	if (GroundCollision == false && jump==false) {
		position.y += -YSpeed;
	}

	
	player->Set_Pos(position.x,position.y);

	SDL_Rect character = {10,10,10,10};

	// Blitting the player
	App->render->Blit(graphics, (int)position.x, (int)position.y, &character);

	return true;
}

bool j1Player::PostUpdate() {

	return true;
}

// Load game 
bool j1Player::Load(pugi::xml_node& data) {

	position.x = data.child("position").attribute("x").as_int();
	position.y = data.child("position").attribute("y").as_int();

	return true;
}

// Save game 
bool j1Player::Save(pugi::xml_node& data) const {

	pugi::xml_node player = data.append_child("position");

	player.append_attribute("x") = position.x;
	player.append_attribute("y") = position.y;

	return true;
}


bool j1Player::CleanUp() {

	//delete (&player);//aixo dona un exception error
	App->tex->UnLoad(graphics);

	return true;
}

void j1Player::OnCollision(Collider* col_1, Collider* col_2)
{
	if (((col_1->type == PLAYER_COLLIDER || col_1->type == NO_COLLIDER) && col_2->type == GROUND_COLLIDER)
		|| ((col_2->type == PLAYER_COLLIDER || col_2->type == PLAYER_COLLIDER) || col_1->type == GROUND_COLLIDER))
	{
		GroundCollision = true;
		jump = false;

	}

};