#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "Lexer.h"
#include "Parser.h"

int main(int argc, char* argv[])
{
	std::ifstream	FstrmSourceFile;	//���� � �������� �����
	std::string		StrCode = "";		//������ ��� ��������� ���� ���������

	//��� ��������� ������ ���������� �� ���������� fstream
	FstrmSourceFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);

	//������� ������� ����
	try
	{
		//�������� �� ���������� �������� ����� ����� (���������� � �����������)
		if (/*argv[argc - 1] != argv[0]*/true)
		{
			FstrmSourceFile.open(/*"Source.txt"*/argv[argc - 1]);
		}
		//� ������ ���� �� ����� �� ����� - ����� ���������
		else
		{
			throw std::exception("File name is null");
		}
	}
	//���������������� ����������
	catch (const std::exception& excp)
	{
		std::cout << excp.what() << std::endl;
		return 1;
	}
	//��������� �� ���������� fstream
	catch (const std::ifstream::failure& excp)
	{
		std::cout << excp.what() << std::endl;
		return excp.code().value();
	}

	//���� ���� ������
	if (FstrmSourceFile.is_open())
	{
		//��������� ��� � ��������� ���������� StrCode
		StrCode.assign((std::istreambuf_iterator<char>(FstrmSourceFile)),
			(std::istreambuf_iterator<char>()));
		//������� ��� � �������
		std::cout << "Programm source code is:"
			<< "\n--------------------------------------------------------------\n"
			<< StrCode
			<< "\n==============================================================\n";
		//�������� ����������� ���������� �� ������������ ���� ���������
		//� ���������� ��� ������� � �������� �����
		compiler::lexer Lexer(StrCode);
		//�������� �����������
		std::vector<compiler::token> TokensArray = Lexer.tokenize();
		compiler::parser Parser(TokensArray);

		//������� ������ �������
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
	//����� ���������� ������
	else
	{
		std::cout << "File is NOT open" << std::endl;
		FstrmSourceFile.close();
		return 2;
	}

	FstrmSourceFile.close();
	return 0;
}

