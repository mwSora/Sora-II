#include "VNScene.h"
#include "Globals.h"

void Lilac::Scenes::VNScene::init()
{
	Globals::engine->set_cursor_state(true);

	this->create_world("building_night");
	//this->scene_world.set_world_color({ 45, 125, 255, 255 });
	this->scene_world.set_world_scroll_multiplier(0.f);

	this->workspace_width = Globals::engine->sdl().workspace_size().x;
	this->workspace_height = Globals::engine->sdl().workspace_size().y;

	this->_init_characters();
	this->_init_vn_bubble();
	this->_init_chapter();
}

Lilac::Scenes::VNBubble* Lilac::Scenes::VNScene::bubble()
{
	return this->vn_bubble;
}

void Lilac::Scenes::VNScene::update(const float dt)
{
}

void Lilac::Scenes::VNScene::_init_characters()
{
	Globals::scenes->create_scene({ "l_unit", std::shared_ptr<VNCharacter>(new VNCharacter()) });
	Globals::scenes->create_scene({ "r_unit", std::shared_ptr<VNCharacter>(new VNCharacter()) });

	this->l_unit = Globals::scenes->get_scene<VNCharacter>("l_unit");
	this->r_unit = Globals::scenes->get_scene<VNCharacter>("r_unit");

	// Init left unit
	this->l_unit->create_character("sora", "stand4");
	this->l_unit->set_active(true);
	this->l_unit->artwork()->set_position({ -128, this->workspace_height - this->l_unit->artwork()->height() });

	// Init right unit
	this->r_unit->create_character("sugu", "stand1");
	this->r_unit->artwork()->set_position({ this->workspace_width - this->l_unit->artwork()->width() + 128, this->workspace_height - this->l_unit->artwork()->height() });
	this->r_unit->set_flipped(true);
}

void Lilac::Scenes::VNScene::_init_vn_bubble()
{
	Globals::scenes->create_scene({ "VNBubble", std::shared_ptr<VNBubble>(new VNBubble()) });
	this->vn_bubble = Globals::scenes->get_scene<VNBubble>("VNBubble");
	this->vn_bubble->set_visible(false);
}

void Lilac::Scenes::VNScene::_init_chapter()
{
	// Pre chapter init


	Globals::scenes->create_scene({ "VNManager", std::shared_ptr<Lilac::VNManager>(new Lilac::VNManager()) });
	Globals::vn_manager = Globals::scenes->get_scene<Lilac::VNManager>("VNManager");
}