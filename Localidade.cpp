#include "Localidade.h"

ostream &operator << (ostream &output, const Localidade &L){
	output<<"Nome: "<<L.nome<<endl;
	output<<"Area: ";
	if (L.area == -1)
		output<<"indisponivel!";
	else
		output<<L.area;
	output<<endl;
	return output;
}

Localidade::Localidade(string nome, float area)
:area(area)
{
	this->nome = validaNome(nome);
	
	if (area > 0)
		this->area = area;
}

Localidade::~Localidade()
{
}

Localidade::Localidade(const Localidade &L){
	this->area = L.area;
	this->nome = L.nome;
}

string Localidade::getNome() const{
		return this->nome;
}

string Localidade::validaNome(const string &nome){
	bool achoudigito = false;
	
	for (unsigned int i = 0;i < nome.size();i++)
		if (isdigit(nome[i]))
			achoudigito = true;
			
	if (achoudigito)
		return "Cidade";
	else
		return nome;
}
