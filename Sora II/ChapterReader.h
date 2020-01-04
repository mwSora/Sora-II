#pragma once
#include <string>
#include <vector>
#include "tinyxml2.h"

namespace Lilac
{
	class ChapterReader
	{
	private:
		tinyxml2::XMLDocument chapter_document;

	public:
		ChapterReader();
		void load_chapter(const std::string& xml_path);
		const std::string get_chapter_title();
		const std::vector<tinyxml2::XMLElement*> get_dialogs();

		const tinyxml2::XMLElement* get_dialog_by_id(const int id);
		
	};
}
	

