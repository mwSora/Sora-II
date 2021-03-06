#include "Globals.h"

int Globals::mousePositionX = 0;
int Globals::mousePositionY = 0;
Lilac::Engine* Globals::engine = nullptr;
std::unique_ptr<Lilac::Lua> Globals::lua = nullptr;
std::unique_ptr<Lilac::Archive> Globals::archive = nullptr;
std::unique_ptr<Lilac::AssetManager> Globals::assets = nullptr;
std::unique_ptr<Lilac::SceneManager> Globals::scenes = nullptr; 
Lilac::VNManager* Globals::vn_manager = nullptr;