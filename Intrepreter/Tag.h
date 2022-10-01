#pragma once

namespace compiler
{
	//тэги для токенов
	enum class tag
	{
		//operators and symbols

		PLUS,	//+
		MINUS,	//-
		MUL,	//*
		DIV,	///
		PERCENT,//%

		BAND,	//&
		BOR,	//|
		TILDE,	//~
		SHL,	//<<
		SHR,	//>>

		ASSIGN,	//=
		SA,		//-=
		PA,		//+=
		MA,		//*=
		DA,		///=
		LSHA,	//>>=
		RSHA,	//<<=
		PERCA,	//%=

		UP,		//++
		UM,		//--

		NOT,	//!
		LAND,	//&&
		LOR,	//||

		E,		//==
		NE,		//!=
		G,		//>
		GE,		//>=
		L,		//<
		LE,		//<=

		LPAREN,	//(
		RPAREN,	//)
		LCBRA,	//{
		RCBRA,	//}
		SEMI,	//;
		COMMA,	//,

		//key words
		IF,		//if
		ELSE,	//else
		TRUE,	//true
		FALSE,	//false
		WHILE,	//while
		PRINT,	//print

		//data types
		INT,	//int

		IDENTIFIER,	//variables
		INTLITRL,	//number

		ENDOF	//end of file
	};
}