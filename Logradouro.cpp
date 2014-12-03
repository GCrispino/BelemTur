#include "Logradouro.h"
#include "stringDigitos.h"

Logradouro::Logradouro(const string &nome, const string &cep, const string &rua, const string &referencia, float area)
:Localidade(nome,area),cep(cep),rua(rua),referencia(referencia)
{
	this->cep = validaCEP(cep);	
}

Logradouro::Logradouro(const Logradouro &L)
:Localidade(L){
	this->cep = L.cep;
	this->rua = L.rua;
	this->referencia = L.referencia;
	this->comentarios = L.comentarios;
}

Logradouro::~Logradouro()
{
}


string Logradouro::validaCEP(const string &cep){
	if (!stringDigitos(cep) || cep.size() != 8)
		return "00000000";
	else
		return cep;
}