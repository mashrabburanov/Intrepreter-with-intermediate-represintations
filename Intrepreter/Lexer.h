#pragma once
#include <vector>
#include <string>
#include "Token.h"

//пространтсво имен компилятора
namespace compiler
{
	//класс лексера
	class lexer
	{
	protected:
		std::vector<token> TokensVector_;
		std::string Code_;			//исходный код
		unsigned int pos_;		//позиция в исходном тексте
		char current_char_;		//текущий символ в исходном тексте
	public:
		lexer(const std::string& Code);
		~lexer();
		std::vector<token> tokenize();
		void getTokensToString();	//вывод токенов
	protected:
		char peek();	//выбрать следующий символ 
		void setPos(unsigned int new_pos);
		token tokenizeNumber();
		token tokenizeWord();
		token tokenizeOperator();
		token tokenizePunct();
		bool isOperator(const char& ch);
		bool isPunct(const char& ch);
		void strGen(int& line, std::string StrTagValue, std::string StrTagName);
	};
}
