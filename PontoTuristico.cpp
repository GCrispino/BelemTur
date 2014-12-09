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

PontoTuristico::PontoTuristico(const string &rua,const string &nome, float area, const string &cep,const string &descricao)
:Logradouro(rua,nome,area,cep,descricao){
	this->fundacao = Data();
}

PontoTuristico::PontoTuristico(const PontoTuristico &PT)
:Logradouro(PT){
	this->fundacao = PT.fundacao;
}

PontoTuristico::~PontoTuristico()
{
}

void PontoTuristico::mostrarComentarios() const{
	cout<<"Comentarios sobre o ponto turístico "<<this->nome<<": "<<endl;
	
	for (unsigned int i = 0;i < this->comentarios.size();i++)
		cout<<"Comentario "<<i + 1<<endl<<comentarios[i]<<endl;
}

PontoTuristico PontoTuristico::operator +=(const PontoTuristico &PT){
	Logradouro L = static_cast<Logradouro &>(*this);
	L += static_cast<const Logradouro &>(PT);
	
	return static_cast<PontoTuristico &>(L);
}