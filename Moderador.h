#ifndef MODERADOR_H
#define MODERADOR_H
#include <iostream> 
#include "Usuario.h"

using namespace std;

class Moderador : public Usuario
{
	friend ostream operator << (ostream &, const Moderador &);
	
public:
	Moderador(string username = "padrao",string senha = "000000", Bairro = Bairro(" ",-1));
	Moderador(const Moderador &);
	~Moderador();

	void cadastrar();
	void editarBairro(Bairro);
	void editarComentario(Comentario);

	Moderador operator +=(const Moderador &);
};

#endif // MODERADOR_H
