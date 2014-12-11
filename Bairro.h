#ifndef BAIRRO_H
#define BAIRRO_H
#include "Localidade.h"
#include "Logradouro.h"

class Bairro : public Localidade
{
	friend ostream &operator << (ostream &, const Bairro &);
	
private:
	vector <string> ruas;
	vector <Logradouro> pontos;
public:
	Bairro(const string &nome = "", float area = -1,string descricao = "");
	Bairro(float area);
	Bairro(const Bairro &);
	~Bairro();
	
	int getNRuas() const;
	void setRua(int,const string &);
	int getNPontos() const;
	const Logradouro * getPonto(int indice);
	void setPonto(int, const Logradouro &);
	
	void mostrarComentarios() const;
	void atualizaComentarios(const string &, string &);
	
	void insereRua(const string &); //insere uma rua nova no vector das principais ruas do bairro.
	void inserePonto(); //insere um objeto do tipo "Logradouro" no vector 'pontos'.
	bool mostrarPontos() const; //imprime todos os objetos contidos no vector 'pontos'.
	const Logradouro* buscaPonto(const string &); //busca e retorna um determinado ponto buscado.
	void mostraPrincipaisRuas() const; //imprime os valores do vector 'ruas'.

	Bairro operator +=(const Bairro &);
	Bairro operator =(const Bairro &);
};

#endif // BAIRRO_H
