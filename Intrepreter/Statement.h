#pragma once

namespace compiler {
	class statement : public node
	{
	protected:

	public:
		virtual void executeStatement() = 0;
		virtual void generatePseudoCode(vector<int>& Data) = 0;
		virtual void printAST() = 0;
		virtual bool isVariable() { return false; }
		virtual void setValue(int value) {}
		virtual void getName(string& Name) {}
	};
}