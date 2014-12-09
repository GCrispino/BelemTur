#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <vector>
#include "Pessoa.h"
#include "Comentario.h"
#include "Bairro.h"
#include "Cidade.h"

using namespace std;

class Usuario : public Pessoa
{
	friend ostream &operator << (ostream &, const Usuario &);
protected:
	string username;
	string senha;
	vector<Comentario> comentarios;
	Data datacadastro;
	Bairro bairrouser;
public:
	Usuario(const string &nome = "Padrao", char sexo = ' ', const string &cpf = "00000000000", const Data & = Data(1,1,1901), const string &username = "usuario1",const string &senha = "000000", const Bairro &bairrouser = Bairro());
	Usuario(const Usuario &);
	virtual ~Usuario();

	string getUsername() const;
	void setUsername(const string &);
	void setSenha(const string &);
	//void setComentario(const string &);
	void setBairro(const Bairro &);
	void setDataCadastro(const Data &);
	string getNomeBairro() const;
	void setNomeBairro(const string &);
	Comentario getComentario(int indice) const;
	void setComentario(int indice,const Comentario &);
	int getNComentarios() const;
	

	virtual void cadastrar(const Cidade &,vector <Pessoa *> &);
	void editarComentario();
	void comentar(Localidade *);
	void atualizarCadastro(Cidade *);
	void mostrarComentarios() const;
	void atualizaComentarios(const string &,string &);
	void atualizaNomeBairro(const string &, string &);
	
	bool verificaSenha(const string &) const;
	static int buscaUsername(const string &, const vector<Pessoa *> &);
	static string validaUsername(const string &);
	static string validaSenha(const string &);

	Usuario operator +=(const Usuario &);
};

#endif // USUARIO_H
