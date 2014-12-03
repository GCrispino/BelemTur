#include "PontoTuristico.h"

ostream &operator << (ostream &output,const PontoTuristico &PT){
	output<<"--PONTO TURISTICO--"<<endl;
	output<<static_cast<const Logradouro &>(PT);
	output<<"Data de fundacao do ponto turistico: "<<PT.fundacao;
	
	return output;
}

PontoTuristico::PontoTuristico(const string &nome, const string &cep, const string &rua, const string &referencia, float area, string descricao,const Data &fundacao)
:Logradouro(nome,cep,rua,referencia,area,descricao),fundacao(fundacao)
{
}

PontoTuristico::PontoTuristico(const PontoTuristico &PT)
:Logradouro(PT){
	this->fundacao = PT.fundacao;
}

PontoTuristico::~PontoTuristico()
{
}

