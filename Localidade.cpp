#include "Localidade.h"
#include "Usuario.h"

ostream &operator << (ostream &output, const Localidade &L){
	output<<L.nome<<endl;
	output<<endl<<"Descricao: "<<L.descricao<<endl;
	output<<endl<<"Area: ";
	if (L.area == -1)
		output<<"indisponivel!";
	else
		output<<L.area;
	output<<endl;
	return output;
}

Localidade::Localidade(string nome, float area,const string &descricao)
:area(area),descricao(descricao)
{
	this->nome = validaNome(nome);
	
	if (area > 0)
		this->area = area;
}

Localidade::Localidade(const Localidade &L){
	this->area = L.area;
	this->nome = L.nome;
	this->descricao = L.descricao;
	this->comentarios = L.comentarios;
}

Localidade::Localidade(float area, const string &descricao)
:descricao(descricao){
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

Comentario Localidade::getComentario(int indice) const{
	if (indice >= 1 && (unsigned int) indice <= this->comentarios.size())
		return this->comentarios[indice - 1];
	else
		return Comentario();
}

void Localidade::setComentario(int indice, const Comentario &C){
	if (indice >= 1 && (unsigned int) indice <= this->comentarios.size())
		this->comentarios[indice - 1] = C;
	else
		return ;
}

void Localidade::setNome(string &nome) {
	this->nome = validaNome(nome);
}

float Localidade::getArea() const{
	return this->area;
}

void Localidade::setArea(float area){
	if (area > 0 || area == -1)
		this->area = area;
	else
		this->area = -1;
}

string Localidade::getDescricao() const{
	return this->descricao;
}

void Localidade::setDescricao(const string &descricao){
	this->descricao = descricao;
}

void Localidade::insereComentario(const Comentario &C){
	this->comentarios.push_back(C);
}

void Localidade::atualizaComentarios(const string &username,string &novousername){
	novousername = Usuario::validaUsername(novousername);
	for (unsigned int i = 0;i < this->comentarios.size();i++)
		if (this->comentarios[i].getNomeUsuario() == username)
			this->comentarios[i].setNomeUsuario(novousername);
}

string Localidade::validaNome(const string &nome){
	bool achouinvalido = false;
	
	for (unsigned int i = 0;i < nome.size();i++)
		if (!isalpha(nome[i]) && !isspace(nome[i]))
			achouinvalido = true;
			
	if (achouinvalido || nome == "")
		return "Padrao";
	else
		return nome;
}
