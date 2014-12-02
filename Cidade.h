#ifndef CIDADE_H
#define CIDADE_H
#include <iostream>
#include "Localidade.h"
#include "Data.h"
#include "Bairro.h"

using namespace std;

class Cidade : public Localidade
{
	friend ostream operator << (ostream &, const Cidade &);
	
private:
	int nhabitantes;
	Data fundacao;
	vector <Bairro> bairros;
public:
	Cidade(string nome = "Padrao",int nhabitantes = -1, float area = -1, Data fundacao = Data(1,1,1901));
	Cidade(string nome,float area);
	Cidade(const Cidade &);
	~Cidade();

	void insereBairro(Bairro);
	void mostraBairros();
	int calculaIdade();

	Cidade operator +=(const Cidade &);
};

#endif // CIDADE_H
