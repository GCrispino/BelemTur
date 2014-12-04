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
	
	void mostrarComentarios() const;
	
	void inserePonto(); //insere um objeto do tipo "Logradouro" no vector 'pontos'.
	void mostrarPontos() const; //imprime todos os objetos contidos no vector 'pontos'.
	Logradouro buscaPonto(); //busca e retorna um determinado ponto buscado.

	Bairro operator +=(Bairro &);
};

#endif // BAIRRO_H
