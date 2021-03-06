#include "MainMenu.h"
#include "Globals.h"

// base theme: { 0, 155, 255, 255 }
// christmas theme: { 0, 155, 255, 255 } / { 255, 165, 165, 255 }

const SDL_Color theme_primary_color = { 0, 155, 255, 255 };
const SDL_Color theme_secondary_color = { 0, 155, 255, 255 };
const std::string menu_message = "Welcome to the project \"Sora II\".";

void Lilac::Scenes::MainMenu::init()
{
	//MusicManager::play("musics/menu");
	MusicManager::play_with_repeat("musics/suguv3", 118.418);
	Globals::engine->set_cursor_state(true);

	this->init_world();
	this->init_top_bar();
	this->init_menu_bar();
	this->init_left_menu();
}

void Lilac::Scenes::MainMenu::init_world()
{
	auto& world = this->create_world("ri_se_sky");
	world.set_world_color(theme_primary_color);
}

void Lilac::Scenes::MainMenu::init_top_bar()
{
	Image* top_bar = this->create_element<Image>("mm_top_bar", Image("guis/main_menu/main_menu_top_bar"));
	top_bar->set_position({ 0, 32 });
	top_bar->set_scroll(true);
	top_bar->set_color(theme_secondary_color);

	UIText* top_bar_label = this->create_element<UIText>("mm_top_bar_title", UIText("Main Menu", {255, 255, 255, 255}, 0, Globals::assets->get_font("escom48")));
	top_bar_label->set_position(
		{
			Globals::engine->sdl().workspace_size().x - top_bar_label->text()->data().w - 10,
			top_bar->position().y + (top_bar->texture()->data().h / 2) - top_bar_label->text()->data().h / 2
		}
	);
}

void Lilac::Scenes::MainMenu::init_menu_bar()
{
	auto top_bar = this->get_element<Image>("mm_top_bar");

	Image* menu_bar_bg = this->create_element<Image>("mm_menu_bar_bg", Image("guis/rect_base"));
	menu_bar_bg->set_custom_size({ Globals::engine->sdl().workspace_size().x, 64 });
	menu_bar_bg->set_color({ 0, 0, 0 }, 150);
	menu_bar_bg->set_position({ 0, top_bar->position().y + top_bar->height() });

	UIText* menu_message_text = this->create_element<UIText>("menu_message_text", UIText(menu_message));
	menu_message_text->set_position(
		{
			menu_bar_bg->right().x - menu_message_text->width() - 10,
			menu_bar_bg->right().y + (menu_bar_bg->height() / 2) - menu_message_text->height() / 2
		}
	);
}

void Lilac::Scenes::MainMenu::init_left_menu()
{
	Image* menu_left = this->create_element<Image>("mm_menu_left_bg", Image("guis/main_menu/menu_left"));
	menu_left->set_color(theme_primary_color);

	this->create_main_buttons();
}

void Lilac::Scenes::MainMenu::create_main_buttons()
{
	this->clear_left_menu_buttons();

	Button* quit_btn = this->create_left_menu_button("quit_game", "guis/main_menu/exit_button");
	quit_btn->set_animation(Lilac::UI::Button::ButtonAnimation::RightSlide);
	quit_btn->set_position(
		{
			5,
			Globals::engine->sdl().window_size().y - quit_btn->height() - 10
		}
	);
	quit_btn->set_callback([]() { Globals::engine->quit(); });
}

Button* Lilac::Scenes::MainMenu::create_left_menu_button(const std::string button_id, const std::string button_texture)
{
	Button* btn = this->create_element<Button>(button_id, Button(button_id, button_texture));
	this->left_menu_btns.push_back(btn);

	return btn;
}

void Lilac::Scenes::MainMenu::clear_left_menu_buttons()
{
	for (const auto& button : this->left_menu_btns)
	{
		const std::string btn_id = button->id();
		this->remove_element(btn_id);
	}
}

void Lilac::Scenes::MainMenu::update(const float dt)
{
}
