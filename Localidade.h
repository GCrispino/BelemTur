#ifndef LOCALIDADE_H
#define LOCALIDADE_H
#include <iostream>

using namespace std;

class Localidade
{
	friend ostream &operator << (ostream &, const Localidade &);
	
protected:
	string nome;
	float area;
public:
	Localidade(string nome = "Local",float area = -1);
	Localidade(float area);
	Localidade(const Localidade &L);
	virtual ~Localidade();

	//getters e setters
	string getNome() const;

	string validaNome(const string &);

	//Localidade operator ==(const Localidade &);
};

#endif // LOCALIDADE_H
