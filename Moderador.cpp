#include "Moderador.h"
#include <conio.h>

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

void Moderador::editarBairro(Bairro *B,vector<Usuario *> &usuarios){
	int opcao,nrua,nlocal,ncomentario;
	float area;
	string descricao,rua,nomebairro;
	Comentario comentantigo,comentnovo;
	
	cout<<"Informacoes do bairro a ser editado: "<<endl;
	getch();
	
	cout<<*B;
	getch();
	
	do{
		cout<<"Escolha um dado para editar: "<<endl;
		cout<<"1. Nome: "<<endl;
		cout<<"2. Area: "<<endl;
		cout<<"3. Descricao: "<<endl;
		cout<<"4. Comentarios: "<<endl;
		cout<<"5. Principais ruas: "<<endl;
		cout<<"6. Locais: "<<endl;
		cout<<"7. Voltar: "<<endl;
		cin >> opcao;
		
		switch(opcao){
			case 1:
				do{
					cout<<"Digite o novo nome do bairro: "<<endl;
					cin >> nomebairro;
					nomebairro = Bairro::validaNome(nomebairro);
					if (nomebairro == "Padrao"){
						cout<<"Nome digitado e' invalido!"<<endl;
						getch();
					}
				}while(nomebairro == "Padrao");
			
				for (unsigned int i = 0;i < usuarios.size();i++)
					usuarios[i]->atualizaNomeBairro(B->getNome(),nomebairro);
					
				cout<<"Nome modificado de '"<<B->getNome()<<"' para '"<<nomebairro<<"'. "<<endl;
				getch();
				break;
			case 2:
				do{
					cout<<"Digite a nova area em km²(digite -1 caso nao saiba o valor correto): "<<endl;
					cin >> area;
					if (area == 0 || area < -1){
						cout<<"Valor invalido!"<<endl;
						getch();
					}
				}while(area == 0 || area < -1);
				
				cout<<"Area modificada de '"<<B->getArea()<<"' km² para '"<<area<<"' km². "<<endl;
				getch();
				B->setArea(area);
				break;
			case 3:
				cout<<"Digite a nova descricao para o Bairro "<<B->getNome()<<": "<<endl;
				cin.sync();
				getline(cin,descricao);
				
				cout<<"Descricao antiga: "<<endl;
				cout<<" - "<<B->getDescricao()<<"."<<endl;
				getch();
				
				cout<<"Descricao nova: "<<endl;
				cout<<" - "<<descricao<<"."<<endl;
				getch();
				
				B->setDescricao(descricao);
				break;
			case 4:
				B->mostrarComentarios();
				
				cout<<"Digite o numero do comentario que deseja editar: "<<endl;
				cin >> ncomentario;
				
				//modifica o comentario dentro do objeto B do tipo Bairro
				comentantigo = B->getComentario(ncomentario);
				comentnovo = comentantigo;
				this->editarComentario(comentnovo);
				B->setComentario(ncomentario,comentnovo);
				
				for (unsigned int i = 0;i < usuarios.size();i++) //atualiza com o texto novo os comentários de todos os usuários
					if(usuarios[i]->getUsername() == comentantigo.getNomeUsuario())
						this->editarComentario(*usuarios[i],comentantigo.getTexto(),comentnovo.getTexto());
						
				getch();
				break;
			case 5:
				B->mostraPrincipaisRuas();
				cout<<"Escolha o numero da rua que voce deseja editar: "<<endl;
				cin >> nrua;
				cout<<"Digite o novo nome da rua: "<<endl;
				cin.sync();
				getline(cin,rua);
				B->setRua(nrua,rua);
				break;
			case 6:
				B->mostrarPontos();
				cout<<"Digite o numero do local que voce deseja editar: "<<endl;
				cin >> nlocal;
				//FALTANDO AQUI!!!
				break;
			case 7: 
				break;
			default:
				cout<<"Opcao invalida!"<<endl;
				getch();
				break;
		}
	}while(opcao != 7);
}

void Moderador::editarPonto(Logradouro &L,vector<Usuario *> &usuarios){
	int opcao,ncomentario;
	float area;
	string descricao,cep,rua,referencia,nomelocal;
	Comentario comentantigo,comentnovo;
	
	cout<<"Informacoes do local a ser editado: "<<endl;
	getch();
	
	cout<<L;
	getch();
	
	do{
		cout<<"Escolha um dado para editar: "<<endl;
		getch();
		cout<<"1. Nome: "<<endl;
		cout<<"2. Area: "<<endl;
		cout<<"3. Descricao: "<<endl;
		cout<<"4. Comentarios: "<<endl;
		cout<<"5. CEP: "<<endl;
		cout<<"6. Rua: "<<endl;
		cout<<"7. Referencia"<<endl;
		cout<<"8. Voltar: "<<endl;
		cin >> opcao;
		
		switch(opcao){
			case 1:
				do{
					cout<<"Digite o novo nome do local: "<<endl;
					cin >> nomelocal;
					nomelocal = Logradouro::validaNome(nomelocal);
					if (nomelocal == "Padrao"){
						cout<<"Nome digitado e' invalido!"<<endl;
						getch();
					}
				}while(nomelocal == "Padrao");
					
				cout<<"Nome modificado de '"<<L.getNome()<<"' para '"<<nomelocal<<"'. "<<endl;
				
				L.setNome(nomelocal);
				getch();
				break;
			case 2:
				do{
					cout<<"Digite a nova area em km²(digite -1 caso nao saiba o valor correto): "<<endl;
					cin >> area;
					if (area == 0 || area < -1){
						cout<<"Valor invalido!"<<endl;
						getch();
					}
				}while(area == 0 || area < -1);
				
				cout<<"Area modificada de '"<<L.getArea()<<"' km² para '"<<area<<"' km². "<<endl;
				getch();
				L.setArea(area);
				break;
			case 3:
				cout<<"Digite a nova descricao para o Local "<<L.getNome()<<": "<<endl;
				cin.sync();
				getline(cin,descricao);
				
				cout<<"Descricao antiga: "<<endl;
				cout<<" - "<<L.getDescricao()<<"."<<endl;
				getch();
				
				cout<<"Descricao nova: "<<endl;
				cout<<" - "<<descricao<<"."<<endl;
				getch();
				
				L.setDescricao(descricao);
				break;
			case 4:
				L.mostrarComentarios();
				
				cout<<"Digite o numero do comentario que deseja editar: "<<endl;
				cin >> ncomentario;
				
				//modifica o comentario dentro do objeto B do tipo Bairro
				comentantigo = L.getComentario(ncomentario);
				comentnovo = comentantigo;
				this->editarComentario(comentnovo);
				L.setComentario(ncomentario,comentnovo);
				
				for (unsigned int i = 0;i < usuarios.size();i++) //atualiza com o texto novo os comentários de todos os usuários
					if(usuarios[i]->getUsername() == comentantigo.getNomeUsuario())
						this->editarComentario(*usuarios[i],comentantigo.getTexto(),comentnovo.getTexto());
				break;
			case 5:
				do{
					cout<<"Digite o novo CEP: "<<endl;
					cin >> cep;
					cep = Logradouro::validaCEP(cep);
					if (cep == "00000000000")
						cout<<"CEP invalido!"<<endl;
				}while(cep == "00000000000");
				cout<<"CEP modificado de '"<<L.getCEP()<<"' para '"<<cep<<"'. "<<endl;
				getch();
				L.setCEP(cep);
				break;
			case 6:
				cout<<"Digite o novo nome da rua do local '"<<L.getNome()<<"'. "<<endl;
				cin >> rua;
				cout<<"Rua modificada de '"<<L.getRua()<<"' para '"<<rua<<"'. "<<endl;
				getch();
				L.setRua(rua);
				break;
			case 7:
				cout<<"Digite a nova referencia do local '"<<L.getNome()<<"'. "<<endl;
				cin >> referencia;
				cout<<"Referencia modificada de '"<<L.getReferencia()<<"' para '"<<referencia<<"'. "<<endl;
				getch();
				L.setReferencia(referencia);
				break;
			case 8:
				break;
			default:
				cout<<"Opcao invalida!"<<endl;
				getch();
				break;
		}
	}while(opcao != 8);
	
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
			cin.sync();
			getline(cin,texto);
			C.setTexto(texto);
		}
}

void Moderador::editarComentario(Usuario &user, const string &textovelho,const string &textonovo){
	Comentario C;
	//procura dentro de um usuário os comentários cujos textos são iguais à variável "textovelho", para atualizá-los.
	for (int i = 1;i <= user.getNComentarios();i++)
		if (user.getComentario(i).getTexto() == textovelho){
			C = user.getComentario(i);
			C.setTexto(const_cast<string &>(textonovo));
			user.setComentario(i,C);
		}
}

Moderador Moderador::operator +=(const Moderador &M){
	//através do static_cast, a sobrecarga do operador "+=" para a classe base Usuário é chamada, ja que a classe moderador possui
	
	Usuario U = static_cast<Usuario &>(*this);
	U += static_cast<const Usuario &>(M);
	
	return static_cast<Moderador &>(U);
}
