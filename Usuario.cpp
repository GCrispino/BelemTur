#include "Usuario.h"
#include <cstdlib>
#include <time.h>
#include <ctype.h>
#include <conio.h>

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

string Usuario::getUsername() const{
	return this->username;
}

void Usuario::setUsername(const string &username){
	this->username = validaUsername(username);
}

void Usuario::setSenha(const string &senha){
	this->senha = validaSenha(senha);
}

void Usuario::setBairro(const Bairro &bairro){
	this->bairrouser = bairro;
}

void Usuario::setDataCadastro(const Data &D){
	this->datacadastro = D;
}

string Usuario::getNomeBairro() const{
	return this->bairrouser.getNome();
}

void Usuario::cadastrar(const Cidade &C,vector <Pessoa *> &usuarios){
	system("cls");
	string nome,cpf,username,senha,nomebairro;
	char sexo;
	int dia,mes,ano,buscaUsername;
	bool achoubairro;
	
	cout<<"--CADASTRO DE USUARIOS--"<<endl;
	getch();
	
	cout<<"--DADOS PESSOAIS--"<<endl;
	getch();
	cout<<"Entre com as suas informacoes pessoais: "<<endl;
	getch();
	
	do{
		cout<<endl<<"Nome: "<<endl;
		cin.sync();
		getline(cin,nome);		
		nome = validaNome(nome);
		if (nome == "Padrao"){
			cout<<"Nome invalido!"<<endl;
			getch();
		}
	}while(nome == "Padrao");
	this->setNome(nome);
	
	do{
		cout<<"Sexo('M' ou 'F'): "<<endl;
		cin >> sexo;
		sexo = toupper(sexo);
		if (sexo != 'M' && sexo != 'F'){
			cout<<"Dado invalido!"<<endl;
			getch();
		}
	}while(sexo != 'M' && sexo != 'F');
	this->setSexo(sexo);
	
	do{
		cout<<"CPF: "<<endl;
		cin >> cpf;
		cpf = validaCPF(cpf);
		if (cpf == "00000000000"){
			cout<<"CPF invalido!"<<endl;
			getch();
		}
	}while(cpf == "00000000000");
	this->setCPF(cpf);
	
	
	cout<<"Data de nascimento: "<<endl;
	getch();
	cout<<"Dia: "<<endl;
	cin >> dia;
	cout<<"Mes: "<<endl;
	cin >> mes;
	cout<<"Ano: "<<endl;
	cin >> ano;
	Data D(dia,mes,ano);
	this->setNascimento(D);
	
	system("cls");
	
	cout<<"--DADOS DE USUARIO--: "<<endl;
	getch();
	
	do{
		cout<<"Nome de usuario: "<<endl;
		cin >> username;
		buscaUsername = Usuario::buscaUsername(username,usuarios);
		if (buscaUsername != -1){
			cout<<"Username ja existe!"<<endl;
			getch();
		}
	}while(buscaUsername != -1);
	this->setUsername(username);
	
	do{
		cout<<"Senha(no minimo 6 digitos): "<<endl;
		cin >> senha;
		senha = validaSenha(senha);
		if (senha == "000000"){
			cout<<"Senha invalida!"<<endl;
			getch();
		}
	}while(senha == "000000");
	this->setSenha(senha);
	
	do{
		cout<<"Digite o nome do Bairro em que voce mora: "<<endl;
		cin >> nomebairro;
		nomebairro = Localidade::validaNome(nomebairro);
		if (nomebairro == "Padrao"){
			cout<<"Nome invalido!"<<endl;
			getch();
		}
	}while(nomebairro == "Padrao");
	this->setNomeBairro(nomebairro);
	
	const Bairro *busca = const_cast<Cidade *>(&C)->buscaBairro(nomebairro);
	
	if (busca != 0){
		achoubairro = true;
		cout<<"Bairro "<<nomebairro<<" encontrado!"<<endl;
		getch();
	}
	else{
		cout<<"Bairro nao encontrado! Talvez voce tenha digitado incorretamente, ou o seu bairro nao esteja presente no nosso registro."<<endl;
		getch();
		cout<<"Sinta-se livre para cadastrar o seu bairro no programa!"<<endl;
		getch();
		
		achoubairro = false;
	}
	
	Bairro B;
	
	if (achoubairro)
		B = *busca;
	
	this->setBairro(B);
	
	this->setDataCadastro(Data(Data::getDataAtual()));
}

void Usuario::editarComentario(){
	char resposta;
	string texto;
	int ncomentario;
	
	if (this->comentarios.empty()){
		cout<<"Nenhum comentario foi feito por esse usuario!";
		getch();
	}
	else{
	
		this->mostrarComentarios();
		getch();
	
		do{
			cout<<"Digite o numero do comentario que voce quer editar: "<<endl;
			cin >> ncomentario;
			if (ncomentario <= 0 || (unsigned int)ncomentario > this->comentarios.size()){
				cout<<"Valor invalido!"<<endl;
				getch();
			}			
		}while(ncomentario <= 0 || (unsigned int)ncomentario > this->comentarios.size());
	
		
			cout<<this->comentarios[ncomentario - 1]<<endl;
			do{
				cout<<"Deseja editar o comentario acima(S ou N)?"<<endl;
				cin >> resposta;
				resposta = toupper(resposta);
			}while(resposta != 'S' && resposta != 'N');
		
			if (resposta == 'S'){
				cout<<"Digite o novo texto do comentario: "<<endl;
				cin.sync();
				getline(cin,texto);
				this->comentarios[ncomentario - 1].setTexto(texto);
			}
	}
}

Comentario Usuario::getComentario(int indice) const{
	if (indice >= 1 && (unsigned int)indice <= this->comentarios.size())
		return this->comentarios[indice - 1];
	else
		return Comentario();
}

void Usuario::setComentario(int indice,const Comentario &C){
	if (indice >= 1 && (unsigned int)indice <= this->comentarios.size())
		this->comentarios[indice - 1] = C;
	else
		return ;
}

int Usuario::getNComentarios() const{
	return this->comentarios.size();
}

void Usuario::setNomeBairro(const string &nomebairro){
	 this->nome = Bairro::validaNome(nomebairro);
}

void Usuario::comentar(Localidade*L){
	string texto;
	
	cout<<"Digite abaixo o seu comentario sobre o seguinte local(maximo de 140 caracteres): "<<endl;
	cout<<"- "<<L->getNome()<<endl<<endl;
	cin.sync();
	getline(cin,texto);
	
	Comentario C(texto,Data::getDataAtual(),this->username);
	
	//insere o novo comentario nos vector de comentários referentes ao usuário e ao local em questão
	this->comentarios.push_back(C);
	L->insereComentario(C);
}

void Usuario::atualizarCadastro(Cidade *C){ 
	int opcao,dia,mes,ano;
	string nome,cpf,nomebairro,username;
	char sexo;
	Data novadata;
	const Bairro *busca;
	Bairro B;
	bool achoubairro;
	
	do{
		system("cls");
		cout<<"-- MODIFICACAO DOS DADOS CADASTRADOS -- "<<endl;
		getch();
		
		cout<<endl<<"Digite o numero correspondente ao dado que quer modificar, ou 0 se deseja sair: "<<endl;
		cout<<"1. Nome"<<endl;
		cout<<"2. Sexo"<<endl;
		cout<<"3. CPF"<<endl;
		cout<<"4. Data de nascimento"<<endl;
		cout<<"5. Username"<<endl;
		cout<<"6. Senha"<<endl;
		cout<<"7. Bairro"<<endl;
		cin >> opcao;
		
		switch(opcao){
			case 0:
				break;
			case 1:
				cout<<"Digite o novo nome: "<<endl;
				cin.sync();
				getline(cin,nome);
				nome = validaNome(nome);
				cout<<"Nome modificado de '"<<this->nome<<"' para '"<<nome<<"'. "<<endl;
				getch();
				this->nome = nome;
				break;
			case 2:
				do{
					cout<<"Digite o seu sexo('M' ou 'F'): "<<endl;
					cin >> sexo;
					sexo = toupper(sexo);
					if (sexo != 'M' && sexo != 'F'){
						cout<<"Valor invalido!"<<endl;
						getch();
					}
				}while(sexo != 'M' && sexo != 'F');
				cout<<"Sexo modificado de '"<<this->sexo<<"' para '"<<sexo<<"'."<<endl;
				getch();
				this->sexo = sexo;
				break;
			case 3:
				do{
					cout<<"Digite o seu novo CPF: "<<endl;
					cin >> cpf;
					cpf = validaCPF(cpf);
					if (cpf == "00000000000"){
						cout<<"Valor invalido!"<<endl;
						getch();
					}
				}while(cpf == "00000000000");
				cout<<"CPF modificado de '"<<this->cpf<<"' para '"<<cpf<<"'. "<<endl;
				getch();
				this->cpf = cpf;
				break;
			case 4:
				cout<<"Digite a sua nova data de nascimento: "<<endl;
				cout<<"Dia: "<<endl;
				cin >> dia;
				cout<<"Mes: "<<endl;
				cin >> mes;
				cout<<"Ano: "<<endl;
				cin >> ano;
				novadata = Data(dia,mes,ano);
				cout<<"Data modificada de '"<<this->nascimento<<"' para '"<<novadata<<"'. "<<endl;
				getch();
				this->nascimento = novadata;
				break;
			case 5:
				do{
					cout<<"Digite o seu novo username: "<<endl;
					cin.sync();
					getline(cin,username);
					if (username.size() < 4){
						cout<<"O username deve conter no minimo 4 caracteres!"<<endl;
						getch();
					}
				}while(username.size() < 4);
				
				//busca pelos comentarios que tinham o username antigo e modificam para o novo:
				C->atualizaComentarios(this->username,username);
				this->atualizaComentarios(this->username,username);
				
				cout<<"Username modificado de '"<<this->username<<"' para '"<<username<<"'. "<<endl;
				this->username = username;
				getch();
				break;
			case 6:
				cout<<"Digite a nova senha: "<<endl;
				cin >> senha;
				nome = validaSenha(senha);
				cout<<"Senha modificada de '"<<this->senha<<"' para '"<<senha<<"'. "<<endl;
				getch();
				this->senha = senha;
				break;
			case 7:
				cout<<"Digite o nome do novo bairro: "<<endl;
				cin.sync();
				getline(cin,nomebairro);
				busca = C->buscaBairro(nomebairro);
		
				if (busca != 0){
					achoubairro = true;
					cout<<"Bairro "<<nomebairro<<" encontrado!"<<endl;
					getch();
				}
				else{
					cout<<"Bairro nao encontrado! Talvez voce tenha digitado incorretamente, ou o seu bairro nao esteja presente no nosso registro."<<endl;
					getch();
					cout<<"Sinta-se livre para cadastrar o seu bairro no programa!"<<endl;
					getch();
			
					achoubairro = false;
				}
				
				if (achoubairro){
					B = *busca;
					cout<<"Bairro modificado de '"<<this->bairrouser.getNome()<<"' para '"<<B.getNome()<<"'. "<<endl;
					getch();
				}
		
		
				this->setBairro(B);
				
				break;
			default:
				cout<<"Opcao invalida!"<<endl;
				getch();
				break;
		}
	}while(opcao != 0);
}

void Usuario::mostrarComentarios() const{
	if (this->comentarios.empty()){
		cout<<"Nenhum comentario foi feito pelo usuario "<<this->username<<"!. "<<endl;
		getch();
	}
	else{
		cout<<"Comentarios feitos pelo usuario "<<this->username<<": "<<endl;
	
		for (unsigned int i = 0;i < this->comentarios.size();i++)
			cout<<"Comentario "<<i + 1<<endl<<comentarios[i]<<endl;
	}
}

void Usuario::atualizaComentarios(const string &username,string &novousername){
	novousername = Usuario::validaUsername(novousername);
	for (unsigned int i = 0;i < this->comentarios.size();i++)
		if (this->comentarios[i].getNomeUsuario() == username)
			this->comentarios[i].setNomeUsuario(novousername);
}

void Usuario::atualizaNomeBairro(const string &nomebairro,string &novonomebairro){
	if (this->getNomeBairro() == nomebairro)
		this->bairrouser.setNome(novonomebairro);
}

bool Usuario::verificaSenha(const string &senha) const{
	if (senha == this->senha)
		return true;
	else
		return false;
}

int Usuario::buscaUsername(const string &username,const vector<Pessoa*> &usuarios){
	Usuario *ptrU;
	for (unsigned int i = 0;i < usuarios.size();i++){
		ptrU = dynamic_cast<Usuario *>(usuarios[i]);
		if (ptrU && maiuscula(ptrU->getUsername()) == maiuscula(username))
			return i;
	}

	return -1;
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
		s += c;
		
		cout<<"Nome invalido! O seu nome de usuario foi configurado para: '"<<s<<"'!"<<endl;
		getch();
		
		return s; //retorna um nome padrão juntamente de um número aleatório entre 1 e 9.
	}
	else //caso o nome possua mais que 4 caracteres, o retorna
		return username;
		
}

string Usuario::validaSenha(const string &senha){
	if (senha.size() < 6)
		return "000000";
	else
		return senha;
}

Usuario Usuario::operator +=(const Usuario &U){
	//sobrecarga do operador "+=" na classe Usuário concatena o vector de comentário de uma instância com outra.
	for (unsigned int i = 0;i < U.comentarios.size();i++)
		this->comentarios.push_back(U.comentarios[i]);
		
	return *this;
}