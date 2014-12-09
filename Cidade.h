#ifndef CIDADE_H
#define CIDADE_H
#include <iostream>
#include "Localidade.h"
#include "Data.h"
#include "Bairro.h"
//#include "Usuario.h"

using namespace std;

class Cidade : public Localidade
{
	friend ostream &operator << (ostream &, Cidade &);
	
private:
	int nhabitantes;
	Data fundacao;
	vector <Bairro> bairros;
public:
	Cidade(string nome = "Padrao",int nhabitantes = -1, float area = -1, Data fundacao = Data(1,1,1901),string descricao = "");
	Cidade(const string &nome,float area);
	Cidade(const Cidade &);
	~Cidade();

	Bairro getBairro(int indice);
	void setBairro(int indice, const Bairro &);

	void mostrarComentarios() const;
	void atualizaComentarios(const string &,string &);
	//void atualizaComentarios(const string &, const Bairro &);

	void insereBairro(const Bairro &);
	void mostraBairros() const;
	Bairro * buscaBairro(const string &);
	int calculaIdade(); //calcula a idade da cidade baseado na data do sistema

	Cidade operator +=(const Cidade &);
};

#endif // CIDADE_H
