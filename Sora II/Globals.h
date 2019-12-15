#pragma once
#include <memory>
#include "Utils.h"
#include "Engine.h"
#include "AssetManager.h"
#include "SceneManager.h"
#include "Lua.h"

struct Globals
{
	static int mousePositionX;
	static int mousePositionY;
	static std::unique_ptr<Lilac::Engine> engine;
	static std::unique_ptr<Lilac::AssetManager> assets;
	static std::unique_ptr<Lilac::SceneManager> scenes;
	static std::unique_ptr<Lilac::Lua> lua;
};

