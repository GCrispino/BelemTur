#include "Logradouro.h"
#include "stringDigitos.h"
#include <conio.h>

ostream &operator << (ostream &output, const Logradouro &L){
	output<<static_cast<const Localidade &>(L);
	output<<"Endereco: "<<endl;
	output<<"   Rua: "<<L.rua<<endl;
	output<<"   CEP: "<<L.cep<<endl;
	output<<"   Referencia: "<<L.referencia<<endl;
	
	return output;
}

Logradouro::Logradouro(const string &nome, const string &cep, const string &rua, const string &referencia, float area, string descricao)
:Localidade(area,descricao),cep(cep),rua(rua),referencia(referencia)
{
	this->cep = validaCEP(cep);	
	this->nome = validaNome(nome);
}

Logradouro::Logradouro(const string &rua,const string &nome, float area, const string &cep,const string &descricao)
:Localidade(area,descricao),rua(rua)
{
	this->cep = validaCEP(cep);
	this->referencia = "";
	this->nome = validaNome(nome);
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

void Logradouro::setNome(const string &nome){
	this->nome = validaNome(nome);
}

void Logradouro::setDescricao(const string &descricao){
	this->descricao = descricao;
}

string Logradouro::getCEP() const{
	return this->cep;
}

void Logradouro::setCEP(const string &cep){
	this->cep = validaCEP(cep);
}

string Logradouro::getRua() const{
	return this->rua;
}
void Logradouro::setRua(const string &rua){
	this->rua = rua;
}

string Logradouro::getReferencia() const{
	return this->referencia;
}
void Logradouro::setReferencia(const string &referencia){
	this->referencia = referencia;
}

void Logradouro::mostrarComentarios() const{
	if (this->comentarios.empty()){
		cout<<"Nao ha nenhum comentario sobre o local "<<this->nome<<"! "<<endl;
		getch();
	}
	else{
		cout<<"Comentarios sobre o local "<<this->nome<<": "<<endl;
		
		for (unsigned int i = 0;i < this->comentarios.size();i++)
			cout<<"Comentario "<<i + 1<<endl<<comentarios[i]<<endl;
	}
}

string Logradouro::validaNome(const string &nome){
	
	for (unsigned int i = 0;i < nome.size();i++)
		if (isalpha(nome[i]))
			return nome;
			
	return "Lugar";
}

string Logradouro::validaCEP(const string &cep){
	if (!stringDigitos(cep) || cep.size() != 8)
		return "00000000";
	else
		return cep;
}

bool Logradouro::operator ==(const Logradouro &L){
	return this->area == L.area && this->cep == L.cep && this->descricao == L.descricao && this->nome == L.nome && this->referencia == L.referencia && this->rua == L.rua;
}

Logradouro Logradouro::operator +=(const Logradouro &L){
	//sobrecarga do operador "+=" na classe Usuário concatena o vector de comentário de uma instância com outra.
	for (unsigned int i = 0;i < L.comentarios.size();i++)
		this->comentarios.push_back(L.comentarios[i]);
		
	return *this;
}