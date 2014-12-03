#include "Moderador.h"

ostream &operator << (ostream &output, const Moderador &M){
	output<<"--USUARIO MODERADOR--"<<endl;
	output<<static_cast<const Usuario &>(M);
	
	return output;
}

Moderador::Moderador(const string &nome, char sexo, const string &cpf, const Data &nascimento, const string &username,const string &senha, const Bairro &bairrouser)
:Usuario(nome,sexo,cpf,nascimento,username,senha,bairrouser)
{
}

Moderador::Moderador(const Moderador &M)
:Usuario(M){}

Moderador::~Moderador()
{
}

void Moderador::cadastrar(){
	
}
