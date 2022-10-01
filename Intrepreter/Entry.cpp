#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "Lexer.h"
#include "Parser.h"

int main(int argc, char* argv[])
{
	std::ifstream	FstrmSourceFile;	//файл с исходным кодом
	std::string		StrCode = "";		//строка для исходного кода программы

	//код разрешени¤ работы исключений из библиотеки fstream
	FstrmSourceFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);

	//пробуем открыть файл
	try
	{
		//проверка на правильное указание имени файла (расшиирить в последующем)
		if (/*argv[argc - 1] != argv[0]*/true)
		{
			FstrmSourceFile.open(/*"Source.txt"*/argv[argc - 1]);
		}
		//в случае если им¤ файла не верно - вызов исключени¤
		else
		{
			throw std::exception("File name is null");
		}
	}
	//пользовательское исключение
	catch (const std::exception& excp)
	{
		std::cout << excp.what() << std::endl;
		return 1;
	}
	//исклчение из библиотеки fstream
	catch (const std::ifstream::failure& excp)
	{
		std::cout << excp.what() << std::endl;
		return excp.code().value();
	}

	//если файл открыт
	if (FstrmSourceFile.is_open())
	{
		//переносим код в строковую переменную StrCode
		StrCode.assign((std::istreambuf_iterator<char>(FstrmSourceFile)),
			(std::istreambuf_iterator<char>()));
		//выводим код в консоль
		std::cout << "Programm source code is:"
			<< "\n--------------------------------------------------------------\n"
			<< StrCode
			<< "\n==============================================================\n";
		//объ¤вл¤ем лексический анализатор из пространства имен компил¤тор
		//и инициируем его строкой с исходным кодом
		compiler::lexer Lexer(StrCode);
		//проводим токенизацию
		std::vector<compiler::token> TokensArray = Lexer.tokenize();
		compiler::parser Parser(TokensArray);

		//выводим список токенов
		std::cout << "Programm tokens is:"
			<< "\n-----------------------------------------------------------------\n";
		Lexer.getTokensToString();
		std::cout << "================================================================\n";
		Parser.parse();
		std::cout << "Programm AST is:"
			<< "\n-----------------------------------------------------------------\n";
		Parser.printAST();
		std::cout << "================================================================\n";
		std::cout << "Programm output is:"
			<< "\n-----------------------------------------------------------------\n";
		Parser.execute();
		std::cout << "================================================================\n";
	}
	//иначе прекращаем работу
	else
	{
		std::cout << "File is NOT open" << std::endl;
		FstrmSourceFile.close();
		return 2;
	}

	FstrmSourceFile.close();
	return 0;
}

