#ifndef LOGRADOURO_H
#define LOGRADOURO_H
#include <iostream>
#include <vector>
#include "Localidade.h"
#include "Comentario.h"

using namespace std;


class Logradouro: public Localidade
{
	friend ostream operator << (ostream &, const Logradouro &);
	
protected:
	int cep;
	string rua;
	string referencia;
	vector <Comentario> comentarios;
public:
	Logradouro(int cep = 00000000, string rua = "", string referencia = "");
	Logradouro(const Logradouro &);
	virtual ~Logradouro();

	void mostrarComentarios();

	Logradouro operator +=(const Logradouro &);
};

#endif // LOGRADOURO_H
