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
	Bairro(const Bairro &);
	~Bairro();
	
	void mostrarComentarios() const;
	
	void inserePonto();
	void mostrarPontos();
	Logradouro buscaPonto();

	Bairro operator +=(const Bairro &);
};

#endif // BAIRRO_H
