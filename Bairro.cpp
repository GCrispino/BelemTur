#include "Bairro.h"

ostream &operator << (ostream &output, const Bairro &B){
	output<<static_cast<const Localidade &>(B);
	
	if (B.ruas.size() != 0){
		output<<"Principais ruas: "<<endl;
	
		for (unsigned int i = 0;i < B.ruas.size();i++)
		output<<B.ruas[i];
	}
	
	return output;
}

Bairro::Bairro(const string &nome, float area,string descricao)
:Localidade(nome,area,descricao)
{
}

Bairro::~Bairro()
{
}

Bairro::Bairro(const Bairro &B)
:Localidade(B){
	this->ruas = B.ruas;
	this->pontos = B.pontos;
}

void Bairro::mostrarComentarios() const{
	
}
