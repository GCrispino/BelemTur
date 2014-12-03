#ifndef MODERADOR_H
#define MODERADOR_H
#include <iostream> 
#include "Usuario.h"

using namespace std;

class Moderador : public Usuario
{
	friend ostream &operator << (ostream &, const Moderador &);
	
public:
	Moderador(const string &nome = "Padrao", char sexo = ' ', const string &cpf = "00000000000", const Data & = Data(1,1,1901), const string &username = "usuario1",const string &senha = "000000", const Bairro &bairrouser = Bairro());
	Moderador(const Moderador &);
	~Moderador();

	void cadastrar();
	void editarBairro(Bairro);
	void editarComentario(Comentario);

	Moderador operator +=(const Moderador &);
};

#endif // MODERADOR_H
