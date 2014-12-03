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
	string nome;
	float area;
	string descricao;
	vector<Comentario> comentarios;
public:
	Localidade(string nome = "Local",float area = -1,string descricao = "");
	Localidade(float area);
	Localidade(const Localidade &L);
	virtual ~Localidade();

	//getters e setters
	string getNome() const;
	
	virtual void mostrarComentarios() const = 0;

	string validaNome(const string &);
};

#endif // LOCALIDADE_H
