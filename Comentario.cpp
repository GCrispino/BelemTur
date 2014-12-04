#include "Comentario.h"

const unsigned int Comentario::QTDMAXCHAR = 140;

ostream &operator << (ostream &output, const Comentario &C){
	output<<"Autor: "<<C.nomeusuario<<endl;
	output<<"Data do comentario: "<<C.datacomentario<<endl;
	output<<" - Comentario: "<<C.texto<<endl;
	
	return output;
}

Comentario::Comentario(string texto,const Data &datacomentario, const string &nomeusuario)
:texto(texto),datacomentario(datacomentario),nomeusuario(nomeusuario)
{
	if (texto.size() > QTDMAXCHAR){
		texto.resize(QTDMAXCHAR); //se o texto for maior que o tamanho máximo, a string é reduzida ao tamanho máximo
		this->texto = texto;
	}
	
	
	if (nomeusuario.size() < 4)
		this->nomeusuario = "usuario1";
}

Comentario::Comentario(string &texto, const string &nomeusuario)
{
	if (texto.size() > QTDMAXCHAR){
		texto.resize(QTDMAXCHAR); //se o texto for maior que o tamanho máximo, a string é reduzida ao tamanho máximo
		this->texto = texto;
	}
	
	if (nomeusuario.size() < 4)
		this->nomeusuario = "usuario1";
	else
		this->nomeusuario = nomeusuario;
	
}

Comentario::Comentario(const Comentario &C){
	this->texto = C.texto;
	this->datacomentario = C.datacomentario;
	this->nomeusuario = C.nomeusuario;
}

Comentario::~Comentario()
{
}

string Comentario::getNomeUsuario(){
	return this->nomeusuario;
}


void Comentario::setTexto(string &texto){
	if (texto.size() > QTDMAXCHAR)
		texto.resize(QTDMAXCHAR); //se o texto for maior que o tamanho máximo, a string é reduzida ao tamanho máximo
	this->texto = texto;
}


Comentario Comentario::operator +=(const Comentario &C){
	//concatena o texto dos dois comentários
	this->texto.push_back(' ');
	this->texto.append(C.texto);
	
	return *this;
}