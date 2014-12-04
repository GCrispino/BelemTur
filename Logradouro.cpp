#include "Logradouro.h"
#include "stringDigitos.h"

ostream &operator << (ostream &output, const Logradouro &L){
	output<<static_cast<const Localidade &>(L);
	output<<"Endereco: "<<endl;
	output<<"   Rua: "<<L.rua;
	output<<"   CEP: "<<L.cep;
	output<<"   Referencia: "<<L.referencia;
	
	return output;
}

Logradouro::Logradouro(const string &nome, const string &cep, const string &rua, const string &referencia, float area, string descricao)
:Localidade(nome,area,descricao),cep(cep),rua(rua),referencia(referencia)
{
	this->cep = validaCEP(cep);	
}

Logradouro::Logradouro(const string &rua,const string &nome, float area, const string &cep)
:Localidade(nome,area),rua(rua)
{
	this->cep = validaCEP(cep);
	this->referencia = "";
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

void Logradouro::mostrarComentarios() const{
	cout<<"Comentarios sobre o local "<<this->nome<<": "<<endl;
	
	for (unsigned int i = 0;i < this->comentarios.size();i++)
		cout<<"Comentario "<<i + 1<<endl<<comentarios[i]<<endl;
}

string Logradouro::validaCEP(const string &cep){
	if (!stringDigitos(cep) || cep.size() != 8)
		return "00000000";
	else
		return cep;
}

Logradouro Logradouro::operator +=(const Logradouro &L){
	//sobrecarga do operador "+=" na classe Usuário concatena o vector de comentário de uma instância com outra.
	for (unsigned int i = 0;i < L.comentarios.size();i++)
		this->comentarios.push_back(L.comentarios[i]);
		
	return *this;
}