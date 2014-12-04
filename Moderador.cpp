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

void Moderador::editarComentario(Comentario &C){
	char resposta;
	string texto;
	
		cout<<C<<endl;
		cout<<"Deseja editar o comentario acima(S ou N)?"<<endl;
		cin >> resposta;
		resposta = toupper(resposta);
		
		if (resposta == 'S'){
			cout<<"Digite o novo texto do comentario: "<<endl;
			//cin >> texto;
			cin.sync();
			getline(cin,texto);
			C.setTexto(texto);
		}
}

Moderador Moderador::operator +=(const Moderador &M){
	//através do static_cast, a sobrecarga do operador "+=" para a classe base Usuário é chamada, ja que a classe moderador possui
	
	Usuario U = static_cast<Usuario &>(*this);
	U += static_cast<const Usuario &>(M);
	
	return static_cast<Moderador &>(U);
}
