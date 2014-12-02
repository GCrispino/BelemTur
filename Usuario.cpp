#include "Usuario.h"
#include <cstdlib>
#include <time.h>

Usuario::Usuario(const string &nome, char sexo, const string &cpf, const Data &nascimento, const string &username,const string &senha, const Bairro &B)
:Pessoa(nome,sexo,cpf,nascimento)
{
	
}

Usuario::~Usuario()
{
}

void Usuario::cadastrar(){
	
}

string Usuario::validaUsername(const string &username){
	int n;
	if (username.size() < 4){ //o tamanho do username deve ser no mínimo de 4 caracteres.
		srand((unsigned)time(NULL));
		
		n = rand() % 10;
		if (n == 0) 
			n++;
		
		string s = "usuario";
		char c = 48 + n;
		
		return s + c; //retorna um nome padrão juntamente de um número aleatório entre 1 e 9.
	}
	else //caso o nome possua mais que 4 caracteres, o retorna
		return username;
		
}

