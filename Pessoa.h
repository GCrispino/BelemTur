#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>
#include "Data.h"
#include "stringDigitos.h"
#include "Cidade.h"

using namespace std;

class Pessoa
{
	friend ostream &operator << (ostream &, const Pessoa &);
protected:
	string nome;
	char sexo;
	string cpf;
	Data nascimento;
public:
	Pessoa(const string &nome = "Padrao", char sexo = ' ', string cpf = "00000000000", const Data & = Data(1,1,1901));
	Pessoa(string &nome, Data &);
	Pessoa(const Pessoa &);
	virtual ~Pessoa();

	virtual void cadastrar(const Cidade &,vector <Pessoa *> &) = 0;

	//getters e setters
	void setNome(const string &);
	void setSexo(char);
	void setCPF(const string &);
	void setNascimento(const Data &);

	static int validaIdade(int idade);
	static string validaNome(const string &nome);
	static string validaCPF(const string &cpf);
};

#endif // PESSOA_H
