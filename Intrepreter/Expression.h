#pragma once
#include <vector>
#include "Node.h"

namespace compiler {
	class Expression : public Node
	{
	protected:
	public:
		virtual int executeExpression() = 0;
		virtual void generatePseudoCode(std::vector<int>& Data) = 0;
		virtual void printAST() = 0;
		virtual bool isNumber();
		virtual bool isVariable();
	};
}