#pragma once
#include "Scene.h"
#include "VNCharacter.h"
#include "VNBubble.h"

namespace Lilac::Scenes
{
	class VNScene : public Scene
	{
	private:
		// Easy access values to workspace
		int workspace_width = 0;
		int workspace_height = 0;

		// Pointers to vn stuff
		Lilac::Scenes::VNCharacter* l_unit = nullptr;
		Lilac::Scenes::VNCharacter* r_unit = nullptr;
		Lilac::Scenes::VNBubble* bubble = nullptr;

	public:
		void init();
		void update(const float dt);

	private:
		void _init_characters();
		void _init_vn_bubble();
	};
}