#include "Cidade.h"

ostream &operator << (ostream &output, const Cidade &C){
	output<<"Cidade de ";
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

Cidade::Cidade(const string &nome, float area)
:Localidade(nome,area),nhabitantes(-1),fundacao(Data()){}

Cidade::Cidade(const Cidade &C)
:Localidade(C){
	this->nhabitantes = C.nhabitantes;
	this->fundacao = C.fundacao;
	this->bairros = C.bairros;
}

Cidade::~Cidade()
{
}

void Cidade::mostrarComentarios() const{
	cout<<"Comentarios sobre a cidade de "<<this->nome<<": "<<endl;
	
	for (unsigned int i = 0;i < this->comentarios.size();i++)
		cout<<"Comentario "<<i + 1<<endl<<comentarios[i]<<endl;
}

Cidade Cidade::operator +=(const Cidade &C){
	if (this->area == -1 || C.area == -1)
		this->area++;
	
	this->area += C.area;
	
	return *this;
}