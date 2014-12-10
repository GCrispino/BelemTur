#ifndef LOCALIDADE_H
#define LOCALIDADE_H
#include <iostream>
#include <vector>
#include "Comentario.h"

using namespace std;

class Localidade
{
	friend ostream &operator << (ostream &, const Localidade &);
	
protected:
	string nome; //nome do local
	float area; //área do local(em km²)
	string descricao; //descrição do local
	vector<Comentario> comentarios;
public:
	Localidade(string nome = "Local",float area = -1,const string &descricao = "");
	Localidade(float area, const string &descricao);
	Localidade(const Localidade &L);
	virtual ~Localidade();

	//getters e setters
	string getNome() const;
	void setNome(string &);
	float getArea() const;
	void setArea(float);
	string getDescricao() const;
	void setDescricao(const string &);
	int getNComentarios() const;
	Comentario getComentario(int indice) const;
	void setComentario(int indice,const Comentario &);
	
	virtual void mostrarComentarios() const = 0;
	void insereComentario(const Comentario &);
	//função que atualiza o nome de usuário em um comentário quando este é modificado nos dados de um determinado usuário.
	virtual void atualizaComentarios(const string &, string &); 

	static string validaNome(const string &);
};

#endif // LOCALIDADE_H
