#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <typeinfo>
#include <conio.h>
#include <stdexcept>
#include <string>
#include <windows.h>
#include "Moderador.h"
#include "Cidade.h"
#include "stringDigitos.h"


using namespace std;

void mensagemPadrao();
void menuLogin();
void menuPrincipal(const Usuario &U);

int buscaUsername(const string &,const vector<Pessoa*> &);

Cidade leArquivoCidade();
void desaloca(vector<Pessoa *> &);

string getSenha(const string &);
int main(int argc, char **argv)
{
	//Cidade C("Belem",1432844,1065,Data(6,12,1616),descricao);
	Cidade C = leArquivoCidade();
	Bairro *ptrBairro,*tmpbairro,tmp;
	const Logradouro *tmpponto;
	vector <Pessoa *> usuarios;
	int opcaologin,opcaoprincipal,opcaolocal,opcaobairro,opcaobairrolocal,opcaomenubairro,indiceusuario,nruas;
	float areabairro;
	string username,senha,nomebairro,nomelocal,descricao,rua;
	
	Usuario *ptrU = new Usuario("Joao",'m',"12345675895",Data(1,1,2001),"joaozinho123","360HD3D"),*ptrTempU;
	Moderador *ptrM;
	usuarios.push_back(ptrU);
	ptrU = new Moderador("Gabriel Nunes Crispino",'m',"00991867211",Data(19,11,1995),"GCrispino","12161820");
	usuarios.push_back(ptrU);
	
	do{
		menuLogin();
		cin >> opcaologin;
		
		switch(opcaologin){
			case 1:
				if (usuarios.empty()){
					cout<<"Nao ha nenhum usuario registrado no programa!"<<endl;
					getch();
				}
				else{
					cout<<"Digite seu nome de usuario: "<<endl;
					cin >> username;
					indiceusuario = buscaUsername(username,usuarios);
					if (indiceusuario == -1){
						cout<<"Nao ha nenhum usuario registrado com o nome '"<<username<<"'! "<<endl;
						getch();
					}
					else{
						senha = getSenha("Digite a sua senha: ");
						cout<<endl;
						if (static_cast<Usuario*>(usuarios[indiceusuario])->verificaSenha(senha)){
							cout<<"Fazendo login..."<<endl;
							for (int i = 0;i < 5;i++){
								cout<<"..."<<endl;
								Sleep(300);
							}
							do{
								menuPrincipal(static_cast<Usuario &>(*usuarios[indiceusuario]));
								cin >> opcaoprincipal;
								
								switch(opcaoprincipal){
									case 1:
										do{
											if (C.mostraBairros()){
												cin >> opcaobairro;
												if (opcaobairro < 0 || opcaobairro > C.getNBairros()){
													cout<<"Opcao invalida!"<<endl;
													getch();
												}
											}
											else{
												opcaobairro = 0;
												break;
											}
										}while(opcaobairro < 1 || opcaobairro > C.getNBairros());
										if (!opcaobairro)
											break;
											
										do{
											system("cls");
											cout<<"Voce escolheu o bairro: "<<C.getBairro(opcaobairro).getNome()<<endl;
											cout<<"Escolha uma opcao: "<<endl;
											cout<<"1. Mostrar as informacoes do bairro: "<<endl;
											cout<<"2. Listar os locais registrados do bairro: "<<endl;
											cout<<"3. Mostrar os comentarios feitos sobre o bairro: "<<endl;
											cout<<"4. Fazer um comentario sobre o bairro: "<<endl;
											cout<<"5. Voltar: "<<endl;
											if (typeid(*usuarios[indiceusuario]) == typeid(Moderador)){
												cout<<"--OPCOES RESTRITAS A MODERADORES--"<<endl;
												cout<<"6. Editar bairro: ";
											}
											cin >> opcaomenubairro;
											
											switch(opcaomenubairro){
												case 1:
													cout<<C.getBairro(opcaobairro);
													getch();
													break;
												case 2:
													system("cls");
													tmp = C.getBairro(opcaobairro);
													ptrM = dynamic_cast<Moderador *>(usuarios[indiceusuario]);
													if (ptrM)
														ptrM->acessaPontos(tmp,usuarios);
													else
														static_cast<Usuario *>(usuarios[indiceusuario])->acessaPontos(tmp);
													//tmp.mostrarPontos();
													//cin >> opcaobairrolocal;
													//tmpponto = C.getBairro(opcaobairro).getPonto(opcaobairrolocal);
													//static_cast<Usuario *>(usuarios[indiceusuario])->buscaPonto(C,tmpponto->getNome());
													
													//C.getBairro(opcaobairro).setPonto(opcaobairro,*tmpponto);
													C.setBairro(opcaobairro,tmp);
													break;
												case 3:
													tmp = C.getBairro(opcaobairro);
													tmp.mostrarComentarios();
													getch();
													break;
												case 4:
													tmp = C.getBairro(opcaobairro);
													static_cast<Usuario *>(usuarios[indiceusuario])->comentar(&tmp);
													C.setBairro(opcaobairro,tmp);
													break;
												case 5:
													break;
												case 6:
													if (typeid(*usuarios[indiceusuario]) == typeid(Moderador)){
														tmp = C.getBairro(opcaobairro);
														static_cast<Moderador *>(usuarios[indiceusuario])->editarBairro(&tmp,usuarios);
														
														C.setBairro(opcaobairro,tmp);
													}
													else{
														cout<<"Opcao invalida!"<<endl;
														getch();
													}
													break;
												default:
													cout<<"Opcao invalida!"<<endl;
													getch();
													break;
											}
										}while(opcaomenubairro != 5);
										break;
									case 2:
										do{
											cout<<"Digite 1 se o local a ser registrado e' um bairro, ou 2 se e' outro local: "<<endl;
											cin >> opcaolocal;
											if (opcaolocal == 1){
												ptrBairro = new Bairro();
												do{
													cout<<"Digite o nome do bairro: "<<endl;
													cin >> nomebairro;
													tmpbairro = C.buscaBairro(nomebairro);
													if (tmpbairro){
														cout<<"Bairro "<<nomebairro<<" ja esta registrado!"<<endl;
														getch();
													}
													else if (nomebairro == "Padrao"){
														cout<<"Nome invalido!"<<endl;
														getch();
													}
												}while (tmpbairro != 0 || nomebairro == "Padrao");
												ptrBairro->setNome(nomebairro);
												do{
													cout<<"Digite a area do bairro em km2";
													cout<<"(caso nao saiba a area, digite -1: )"<<endl;
													cin >> areabairro;
												}while(areabairro < 0 && areabairro != -1);
												ptrBairro->setArea(areabairro);
												
												cout<<"Digite descricao para o bairro: "<<endl;
												cin >> descricao;
												ptrBairro->setDescricao(descricao);
												
												nruas = 0;
												do{
													cout<<"Entre com as principais ruas do bairro(digite 0 quando quiser parar): "<<endl;
													cout<<"Rua "<<nruas + 1<<": "<<endl;
													cin.sync();
													getline(cin,rua);
													if (rua == "0")
														break;
													ptrBairro->insereRua(rua);
													nruas++;
												}while(rua != "0");
												
												C.insereBairro(*ptrBairro);
												delete ptrBairro;
											}
											else if(opcaolocal == 2){
												cout<<"Digite o nome do bairro do local a ser registrado: "<<endl;
												cin >> nomebairro;
												
												ptrBairro = const_cast<Bairro *>(C.buscaBairro(nomebairro));
												
												if (ptrBairro)
													ptrBairro->inserePonto();
												else{
													cout<<"Bairro nao encontrado!"<<endl;
													getch();
												}
											}
											else{
												cout<<"Opcao invalida!"<<endl;
												getch();
											}
										}while(opcaolocal != 1 && opcaolocal != 2);
										break;
									case 3:
										cout<<"Digite o nome do local: "<<endl;
										cin.sync();
										getline(cin,nomelocal);
										
										cout<<"Resultados: "<<endl;;
										ptrM = dynamic_cast<Moderador *>(usuarios[indiceusuario]);
										if (ptrM)
											ptrM->buscaPonto(C,nomelocal,usuarios);
										else{
											ptrTempU = dynamic_cast<Usuario *>(usuarios[indiceusuario]);
											ptrTempU->buscaPonto(C,nomelocal);
										}
										
										
										break;
									case 4:
										static_cast<Usuario &>(*usuarios[indiceusuario]).atualizarCadastro(&C);
										break;
									case 5:
										cout<<"Fazendo logout..."<<endl;
										for (int i = 0;i < 5;i++){
											cout<<"..."<<endl;
											Sleep(300);
										}
										break;
									default:
										cout<<"Opcao invalida!"<<endl;
										getch();
										break;
									
								}
							}while(opcaoprincipal != 5);
						}
						else{
							cout<<"Senha incorreta!"<<endl;
							getch();
						}
					}
				}
				break;
			case 2:
				ptrU = new Usuario();
				ptrU->cadastrar(C,usuarios);
				usuarios.push_back(ptrU);
				break;
			case 3:
				cout<<"Programa encerrado!"<<endl;
				getch();
				break;
			default:
				cout<<"Opcao invalida!"<<endl;
				getch();
				break;
		}
	}while(opcaologin != 3);
	
	delete ptrU;
	//desaloca(usuarios);
	
	return 0;
	/*vector<Usuario *> usuarios;
	//const_cast<Logradouro *>(L3)->setDescricao("coco");
	Cidade C("Belem",-1,-1,Data(6,12,1616));
	Bairro Cremacao("Cremacao",-1,"Local onde era localizado o forno crematorio de Belem"),B;
	Moderador U("joao",'m',"12345678901",Data(1,1,1997),"fulano123","123456",Cremacao),*M;
	usuarios.push_back(&U);
	C.insereBairro(Cremacao);
	
	//U.cadastrar(C);
	
	cout<<*usuarios[0]<<endl;
	
	usuarios[0]->comentar(&C);
	usuarios[0]->comentar(&Cremacao);
	//U.comentar(&Cremacao);
	C.setBairro(1,Cremacao);
	B = C.getBairro(1);
	M = dynamic_cast<Moderador *>(usuarios[0]);
	if (M != 0)
		M->editarBairro(&B,usuarios);
	//U.atualizarCadastro(&C);
	system("cls");
	//B.mostrarComentarios();
	getch();
	C.setBairro(1,B);
	
	system("cls");
	
	//C.getBairro(1).mostrarComentarios();
	cout<<*usuarios[0];
	getch();
	usuarios[0]->mostrarComentarios();
	getch();
	
	system("cls");
	
	C.getBairro(1).mostrarComentarios();
	getch();*/
}

void mensagemPadrao(){
	system("cls");
	cout<<"\t\t\t SEJA BEM VINDO AO BELEMTUR !"<<endl;
}

void menuLogin(){
	mensagemPadrao();
	cout<<endl<<"||MENU DE LOGIN||"<<endl<<endl;
	cout<<"1.Fazer login"<<endl;
	cout<<"2.Se registrar"<<endl;
	cout<<"3.Sair do programa"<<endl;
}

void menuPrincipal(const Usuario &U){
	mensagemPadrao();
	cout<<endl<<"||MENU PRINCIPAL||"<<endl<<endl;
	cout<<"Usuario logado: "<<U.getUsername();
	if (typeid(U) == typeid(Moderador))
		cout<<"(Moderador)"<<endl<<endl;
	else
		cout<<endl<<endl;
	cout<<"1.Listar todos os bairros de Belem"<<endl;
	cout<<"2.Adicionar um novo local"<<endl;
	cout<<"3.Buscar um local"<<endl;
	cout<<"4.Editar informacoes do usuario"<<endl;
	cout<<"5.Logout"<<endl;
}

int buscaUsername(const string &username,const vector<Pessoa*> &usuarios){
	Usuario *ptrU;
	for (unsigned int i = 0;i < usuarios.size();i++){
		ptrU = dynamic_cast<Usuario *>(usuarios[i]);
		if (ptrU && maiuscula(ptrU->getUsername()) == maiuscula(username))
			return i;
	}

	return -1;
}

Cidade leArquivoCidade(){
	ifstream arquivo;
	string linha,nome,descricao;
	string s;
	float area;
	int nhabitantes,cont = 0,contdata = 1,dia,mes,ano;
	Data fundacao;
	
	
	arquivo.open("Cidade.txt");
	
	if (arquivo.is_open())
		while(getline(arquivo,linha)){
			for (unsigned int i = 0;i < linha.size();i++){
				if (cont != 4 && linha[i] != ' ')
					s.push_back(linha[i]);
				else{
					switch(cont){
						case 0:
							nome = s;
							s.clear();
							break;
						case 1:
							nhabitantes = atoi(s.c_str());
							s.clear();
							break;
						case 2:
							area = atof(s.c_str());
							s.clear();
							break;
						case 3:
							if (contdata == 1){
								dia = atoi(s.c_str());
								s.clear();
								cont--;
							}
							else if (contdata == 2){
								mes = atoi(s.c_str());
								s.clear();
								cont--;
							}
							else{
								ano = atoi(s.c_str());
								s.clear();
								fundacao = Data(dia,mes,ano);
							}
							contdata++;
							break;
						case 4:
							descricao = linha.substr(i);
							break;
						default:
							break;
					}
					cont++;
				}
			}
		}
	
	arquivo.close();
	
	return Cidade(nome,nhabitantes,area,fundacao,descricao);
}

string getSenha( const string& prompt = "Enter password> " ){
	string result;

	// Set the console mode to no-echo, not-line-buffered input
	DWORD mode, count;
  	HANDLE ih = GetStdHandle( STD_INPUT_HANDLE  );
	HANDLE oh = GetStdHandle( STD_OUTPUT_HANDLE );
	if (!GetConsoleMode( ih, &mode ))
	    throw runtime_error(
	      "getpassword: You must be connected to a console to use this program.\n"
	    );
	SetConsoleMode( ih, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT) );
	
	// Get the password string
	WriteConsoleA( oh, prompt.c_str(), prompt.length(), &count, NULL );
	char c;
	while (ReadConsoleA( ih, &c, 1, &count, NULL) && (c != '\r') && (c != '\n')){
		if (c == '\b'){
	    	if (result.length()){
	        	WriteConsoleA( oh, "\b \b", 3, &count, NULL );
	        	result.erase( result.end() -1 );
	    	}
	    }
	    else{
	    		WriteConsoleA( oh, "*", 1, &count, NULL );
	    		result.push_back( c );
	    }
	}
	
	  // Restore the console mode
	  SetConsoleMode( ih, mode );
	
	  return result;
}