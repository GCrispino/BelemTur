#include "Comentario.h"

const unsigned int Comentario::QTDMAXCHAR = 140;

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
