#pragma once
#include <vector>
#include <string>
#include "Token.h"

//������������ ���� �����������
namespace compiler
{
	//����� �������
	class lexer
	{
	protected:
		std::vector<token> TokensVector_;
		std::string Code_;			//�������� ���
		unsigned int pos_;		//������� � �������� ������
		char current_char_;		//������� ������ � �������� ������
	public:
		lexer(const std::string& Code);
		~lexer();
		std::vector<token> tokenize();
		void getTokensToString();	//����� �������
	protected:
		char peek();	//������� ��������� ������ 
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
