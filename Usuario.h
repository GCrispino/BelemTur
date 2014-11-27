#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <vector>
#include "Pessoa.h"
#include "Comentario.h"
#include "Bairro.h"

using namespace std;

class Usuario : public Pessoa
{
	friend ostream operator << (ostream &, const Usuario &);
protected:
	string username;
	string senha;
	vector<Comentario> comentarios;
	Data datacadastro;
	Bairro bairrouser;
public:
	Usuario(string username = "padrao",string senha = "000000", Bairro = Bairro(" ",-1));
	Usuario(const Usuario &);
	virtual ~Usuario();

	/*virtual */void cadastrar();
	void comentar(Logradouro);
	void atualizarCadastro();
	void mostrarComentarios();

	Usuario operator =(const Usuario &);
};

#endif // USUARIO_H
