#include "Pessoa.h"

ostream &operator << (ostream &output, const Pessoa &P){
	output<<"Nome: "<<P.nome<<endl;
	output<<"Sexo: ";
	if (P.sexo == 'M')
		cout<<"masculino";
	else if (P.sexo == 'F')
		cout<<"feminino";
	else
		cout<<"indisponivel";
	cout<<". "<<endl;
	output<<"CPF: "<<P.cpf<<endl;
	output<<"Data de nascimento: "<<P.nascimento<<endl;
	
	return output;
}

Pessoa::Pessoa(const string &nome, char sexo, string cpf, const Data &nascimento)
:sexo(sexo),nascimento(nascimento)
{
	this->nome = validaNome(nome);
	
	this->setSexo(sexo);
	
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

void Pessoa::setNome(const string &nome){
	this->nome = validaNome(nome);
}
void Pessoa::setSexo(char sexo){
	sexo = toupper(sexo);
	if (sexo != 'M' && sexo != 'F')
		this->sexo = '0';
	else
		this->sexo = sexo;
}
void Pessoa::setCPF(const string &cpf){
	this->cpf = validaCPF(cpf);
}
void Pessoa::setNascimento(const Data &D){
	this->nascimento = D;
}

string Pessoa::validaNome(const string &nome){
	bool achouinvalido = false;
	
	for (unsigned int i = 0;i < nome.size();i++)
		if (!isalpha(nome[i]) && !isspace(nome[i]))
			achouinvalido = true;
			
	if (achouinvalido || nome == "")
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
