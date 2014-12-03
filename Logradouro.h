#ifndef LOGRADOURO_H
#define LOGRADOURO_H
#include <iostream>
#include <vector>
#include "Localidade.h"
#include "Comentario.h"

using namespace std;


class Logradouro: public Localidade
{
	friend ostream &operator << (ostream &, const Logradouro &);
	
protected:
	string cep;
	string rua;
	string referencia;
	vector <Comentario> comentarios;
public:
	Logradouro(const string &nome = "", const string  &cep = "00000000", const string &rua = "", const string &referencia = "",float area = -1);
	Logradouro(const Logradouro &);
	virtual ~Logradouro();

	static string validaCEP(const string &);

	void mostrarComentarios();

	Logradouro operator +=(const Logradouro &);
};

#endif // LOGRADOURO_H
