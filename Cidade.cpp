#include "Cidade.h"

ostream &operator << (ostream &output, const Cidade &C){
	output<<"Cidade ";
	output<<static_cast<const Localidade &>(C);
	output<<"Numero de habitantes: ";
	if (C.nhabitantes == -1)
		output<<"Indisponivel!"<<endl;
	else
		output<<C.nhabitantes<<endl;
	output<<"Data de fundacao: "<<C.fundacao<<endl;
	
	return output;
}

Cidade::Cidade(string nome, int nhabitantes, float area, Data fundacao, string descricao)
:Localidade(nome,area,descricao),fundacao(fundacao)
{
	if (nhabitantes < -1)
		this->nhabitantes = -1;
	else
		this->nhabitantes = nhabitantes;
}

Cidade::~Cidade()
{
}

void Cidade::mostrarComentarios() const{
	
}