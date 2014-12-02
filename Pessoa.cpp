#include "Pessoa.h"

Pessoa::Pessoa(const string &nome, char sexo, string cpf, const Data &nascimento)
:sexo(sexo),nascimento(nascimento)
{
	this->nome = validaNome(nome);
	
	if (sexo != 'M' && sexo != 'F')
		this->sexo = '0';
	
	this->cpf = validaCPF(cpf);
}

Pessoa::Pessoa(string &nome , Data &nascimento)
:nascimento(nascimento)
{
	this->nome = validaNome(nome);
}

Pessoa::Pessoa(const Pessoa &P){
	this->cpf = P.cpf;
	this->nascimento = P.nascimento;
	this->nome = P.nome;
	this->sexo = P.sexo;
}

Pessoa::~Pessoa()
{
}

string Pessoa::validaNome(const string &nome){
	bool achoudigito = false;
	
	for (unsigned int i = 0;i < nome.size();i++)
		if (isdigit(nome[i]))
			achoudigito = true;
			
	if (achoudigito)
		return "Padrao";
	else
		return nome;
}

string Pessoa::validaCPF(const string &cpf){
	if (stringDigitos(cpf) && cpf.size() == 11)
		return cpf;
	else
		return "00000000000";
}

int Pessoa::validaIdade(int idade){
	if (idade <= 0 || idade >= 180)
		return 1; //se a idade for inválida, retorna uma idade default igual a 1.
	else
		return idade; //caso contrário, a idade passada é válida e é retornada.
}
