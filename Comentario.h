#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <iostream>
#include "Data.h"

using namespace std;

class Comentario
{
	friend ostream operator << (ostream &, const Comentario &);
	
private:
	string texto;
	Data datacomentario;
	string nomeusuario;
	const static int QTDMAXCHAR;
public:
	Comentario(string texto = "", Data datacomentario = Data(1,1,1901),string nomeusuario = "Padrao");
	Comentario(string nomeusuario,Data datacomentario);
	Comentario(const Comentario &);
	~Comentario();
	
	void editarComentario();

	Comentario operator =(const Comentario &);
};

#endif // COMENTARIO_H
