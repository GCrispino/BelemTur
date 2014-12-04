#include "Localidade.h"

ostream &operator << (ostream &output, const Localidade &L){
	output<<"- "<<L.nome<<endl;
	output<<endl<<"Descricao: "<<L.descricao<<endl;
	output<<endl<<"Area: ";
	if (L.area == -1)
		output<<"indisponivel!";
	else
		output<<L.area;
	output<<endl;
	return output;
}

Localidade::Localidade(string nome, float area,string descricao)
:area(area),descricao(descricao)
{
	this->nome = validaNome(nome);
	
	if (area > 0)
		this->area = area;
}

Localidade::Localidade(const Localidade &L){
	this->area = L.area;
	this->nome = L.nome;
}

Localidade::Localidade(float area){
	if (area < 0)
		this->area = -1;
	else
		this->area = area;
		
	this->nome = "Local";
}

Localidade::~Localidade()
{
}

string Localidade::getNome() const{
		return this->nome;
}

string Localidade::validaNome(const string &nome){
	bool achouinvalido = false;
	
	for (unsigned int i = 0;i < nome.size();i++)
		if (!isalpha(nome[i]) && !isspace(nome[i]))
			achouinvalido = true;
			
	if (achouinvalido || nome == "")
		return "Cidade";
	else
		return nome;
}
