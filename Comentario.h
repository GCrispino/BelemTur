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
	string texto; //texto do comentário
	Data datacomentario; //data em que o comentário foi criado
	string nomeusuario; //username do usuário que fez o comentário
	const static unsigned int QTDMAXCHAR; //quantidade máxima de caracteres que um comentário pode ter
public:
	Comentario(string texto = "", const Data &datacomentario = Data(1,1,1901),const string &nomeusuario = " ");
	Comentario(string &texto, const string &nomeusuario);
	Comentario(const Comentario &);
	~Comentario();
	
	string getNomeUsuario();
	void setTexto(string &);
	

	Comentario operator +=(const Comentario &);
};

#endif // COMENTARIO_H
