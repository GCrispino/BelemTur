#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <iostream>
#include "Data.h"
//#include "Usuario.h"

using namespace std;

class Comentario
{
	friend ostream &operator << (ostream &, const Comentario &);
	
private:
	string texto;
	Data datacomentario;
	string nomeusuario;
	const static unsigned int QTDMAXCHAR;
public:
	Comentario(string texto = "", const Data &datacomentario = Data(1,1,1901),const string &nomeusuario = " ");
	Comentario(string &texto, const string &nomeusuario);
	Comentario(const Comentario &);
	~Comentario();
	
	void editarComentario();

	Comentario operator +=(const Comentario &);
};

#endif // COMENTARIO_H
