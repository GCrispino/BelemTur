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
	Usuario(const string &nome = "Padrao", char sexo = ' ', const string &cpf = "00000000000", const Data & = Data(1,1,1901), const string &username = "padrao",const string &senha = "000000", const Bairro & = Bairro(" ",-1));
	Usuario(const Usuario &);
	virtual ~Usuario();

	virtual void cadastrar();
	void comentar(Logradouro);
	void atualizarCadastro();
	void mostrarComentarios();
	
	static string validaUsername(const string &);

	Usuario operator +=(const Usuario &);
};

#endif // USUARIO_H
