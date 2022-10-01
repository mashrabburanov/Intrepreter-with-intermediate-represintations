#pragma once
#include <string>

namespace compiler {
	class Node {
	protected:
		static unsigned int t;
	protected:
		virtual void ast(std::string txt);
		virtual void ast(int val);
	};
}