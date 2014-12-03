#ifndef PONTOTURISTICO_H
#define PONTOTURISTICO_H
#include <iostream>
#include "Logradouro.h"

using namespace std;

class PontoTuristico: public Logradouro
{
	friend ostream &operator << (ostream &,const PontoTuristico &);
	
private:
	Data fundacao;
public:
	PontoTuristico(const string &nome = "", const string  &cep = "00000000", const string &rua = "", const string &referencia = "",float area = -1,string descricao = "",const Data &fundacao = Data());
	PontoTuristico(const PontoTuristico &);
	~PontoTuristico();
	
	
	
};

#endif // PONTOTURISTICO_H
