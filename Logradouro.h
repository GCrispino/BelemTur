#ifndef LOGRADOURO_H
#define LOGRADOURO_H
#include <iostream>
#include <vector>
#include "Localidade.h"
//#include "Comentario.h"

using namespace std;


class Logradouro: public Localidade
{
	friend ostream &operator << (ostream &, const Logradouro &);
	
protected:
	string cep;
	string rua;
	string referencia;
public:
	Logradouro(const string &nome = "", const string  &cep = "00000000", const string &rua = "", const string &referencia = "",float area = -1,string descricao = "");
	Logradouro(const string &rua,const string &nome, float area, const string &cep,const string &descricao);
	Logradouro(const Logradouro &);
	virtual ~Logradouro();

	void setNome(const string &);
	void setDescricao(const string &);
	string getCEP() const;
	void setCEP(const string &);
	string getRua() const;
	void setRua(const string &);
	string getReferencia() const;
	void setReferencia(const string &);
	
	
	static string validaNome(const string &);
	static string validaCEP(const string &);

	void mostrarComentarios() const;

	bool operator ==(const Logradouro &);
	Logradouro operator +=(const Logradouro &);
};

#endif // LOGRADOURO_H
