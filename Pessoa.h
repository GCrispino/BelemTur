#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>
#include "Data.h"

using namespace std;

class Pessoa
{
	friend ostream operator << (ostream &, const Pessoa &);
protected:
	string nome;
	char sexo;
	string cpf;
	Data nascimento;
public:
	Pessoa(string nome = "Padrao", char sexo = ' ', string cpf = "00000000000", Data = Data(1,1,1901));
	Pessoa(string nome, Data);
	Pessoa(const Pessoa &);
	~Pessoa();

	int validaIdade(int idade);
	string validaNome(string nome);
	string validaCPF(string cpf);

	Pessoa operator =(const Pessoa &);
};

#endif // PESSOA_H
