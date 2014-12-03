#include "Usuario.h"
#include <cstdlib>
#include <time.h>

ostream &operator << (ostream &output, const Usuario &U){
	output<<static_cast<const Pessoa &>(U);
	
	output<<"Username: "<<U.username<<endl;
	output<<"Data de cadastro: "<<U.datacadastro;
	output<<"Bairro: "<<U.bairrouser.getNome();
	
	return output;
}

Usuario::Usuario(const string &nome, char sexo, const string &cpf, const Data &nascimento, const string &username,const string &senha, const Bairro &bairrouser)
:Pessoa(nome,sexo,cpf,nascimento),bairrouser(bairrouser),username(username)
{
	this->username = validaUsername(username);
	this->senha = validaSenha(senha);
}

Usuario::Usuario(const Usuario &U){
	this->username = U.username;
	this->senha = U.senha;
	this->comentarios = U.comentarios;
	this->datacadastro = U.datacadastro;
	this->bairrouser = U.bairrouser;
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

string Usuario::validaSenha(const string &senha){
	if (senha.size() < 6)
		return "123456";
	else
		return senha;
}