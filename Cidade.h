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

	int getNBairros() const;
	Bairro getBairro(int indice) const;
	const Bairro *getBairro(unsigned int indice) const;
	void setBairro(int indice, const Bairro &);

	void mostrarComentarios() const;
	void atualizaComentarios(const string &,string &);

	void insereBairro(const Bairro &);
	bool mostraBairros();
	Bairro * buscaBairro(const string &);
	//void buscaPonto(bool, const string &); //busca e retorna um determinado ponto buscado.
	int calculaIdade(); //calcula a idade da cidade baseado na data do sistema

	Cidade operator +=(const Cidade &);
};

#endif // CIDADE_H
