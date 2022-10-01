#pragma once
#include <string>
#include "Tag.h"

namespace compiler
{
	class token
	{
	protected:
		std::string	Value_;
		tag	Tag_;
	public:
		token(std::string Value, tag Tag);
		token(tag Tag);
		token();
		tag			getTag();
		std::string	getValue();
	};
}