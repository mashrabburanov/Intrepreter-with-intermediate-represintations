#pragma once
#include <vector>
#include "Token.h"
#include "Expressions.h"
#include "Statements.h"

#define		IGNORE		0
#define		NOTIGNORE	1

//пространство имен компилятора
namespace compiler
{
	class parser
	{
	protected:
		std::vector<token>		TokensArray_;
		static int				pos_;
		token					CurrentToken_;
		std::vector<statement*>	StatementsArray_;
		std::vector<int>		PseudoCode_;

	public:
		parser(std::vector<token> TokensArray);

		std::vector<statement*>	parse();
		void					execute();
		void					printAST();
		std::vector<int>		generatePseudoCode();

	protected:
		expression*		parseExpression();
		expression*		parseUnaryExpression();
		expression*		parseAdditiveExpression();
		expression*		parseBinaryExpression();
		expression*		parseBooleanExpression();
		expression*		parseEqualityExpression();
		expression*		parseLogicExpression();
		expression*		parseTerm();
		expression*		parseFactor();
		expression*		parseAssignmentExpression();

		statement*		parseProgram();
		statement*		parseDeclaration();
		statement*		parseMultipleVariables();
		statement*		parseAssignmentDeclaration();
		statement*		parseVariableDeclaration();
		statement*		parseExpressionStatement();
		statement*		parseStatement();
		statement*		parseCompundStatement();
		statement*		parseIfStatement(bool ignore);
		statement*		parseWhileStatement();
		statement*		parseSystemPrint();

		token				nextToken();
		token				look(int far);
	};

}