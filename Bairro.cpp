#include "Bairro.h"
#include "PontoTuristico.h"
#include <conio.h>

ostream &operator << (ostream &output, const Bairro &B){
	output<<static_cast<const Localidade &>(B);
	
	if (B.ruas.size() != 0){
		output<<"Principais ruas: "<<endl;
	
		for (unsigned int i = 0;i < B.ruas.size();i++)
		output<<B.ruas[i];
	}
	
	return output;
}

Bairro::Bairro(const string &nome, float area,string descricao)
:Localidade(nome,area,descricao)
{
}

Bairro::Bairro(float area)
:Localidade("Cidade",area){}

Bairro::Bairro(const Bairro &B)
:Localidade(B){
	this->ruas = B.ruas;
	this->pontos = B.pontos;
}

Bairro::~Bairro()
{
}

void Bairro::setRua(int indice,const string &rua){
	if (indice >= 1 && (unsigned int) indice <= this->ruas.size())
		this->ruas[indice - 1] = rua;
	else
		return ;
}

int Bairro::getNPontos() const{
	return this->pontos.size();
}

const Logradouro * Bairro::getPonto(int indice){
	if (indice >= 1 && (unsigned int) indice <= this->pontos.size())
		return &this->pontos[indice - 1];
	else
		return 0;
}

void Bairro::setPonto(int indice, const Logradouro &L){
	
}

void Bairro::mostrarComentarios() const{
	if (this->comentarios.empty()){
		cout<<"Nao ha nenhum comentario!"<<endl;
		getch();
	}
	else{
		cout<<"Comentarios sobre o bairro "<<this->nome<<": "<<endl;
		
		for (unsigned int i = 0;i < this->comentarios.size();i++)
			cout<<"Comentario "<<i + 1<<endl<<comentarios[i]<<endl;
	}
}

void Bairro::atualizaComentarios(const string &username,string &novousername){
	Localidade::atualizaComentarios(username,novousername);
	
	for (unsigned int i = 0;i < this->pontos.size();i++)
		this->pontos[i].atualizaComentarios(username,novousername);
}

void Bairro::insereRua(const string &rua){
	this->ruas.push_back(rua);
}

void Bairro::inserePonto(){
	string nome,descricao,rua,cep,referencia;	
	float area;
	int rarea,pt,dia,mes,ano;
	Data fundacao;
	bool loop;
	
	cout<<"Digite 1 se o novo local a ser inserido e' um ponto turistico, ou qualquer outro numero caso contrario: "<<endl;
	cin >> pt;
	cout<<"Digite o nome do novo local a ser salvo: "<<endl;
	cin.sync();
	getline(cin,nome);
	
	if (pt == 1){
		cout<<"Digite a data de fundacao do ponto turistico: "<<endl;
		cout<<"Dia: ";
		cin >> dia;
		cout<<endl<<"Mes: ";
		cin >> mes;
		cout<<endl<<"Ano: ";
		cin >> ano;
		cout<<endl;
		fundacao = Data(dia,mes,ano);
	}
	cout<<"Caso deseje informar a area do novo local, digite 1. Caso nao queira, digite outro numero: "<<endl;
	cin >> rarea;
	
	if (rarea == 1){
		cout<<"Digite a area do novo local(em km²): "<<endl;
		cin >> area;
	}
	else
		area = -1;
	cout<<"Digite uma breve descricao do novo local: "<<endl;
	cin.sync();
	getline(cin,descricao);
	
	cout<<"--Endereco--"<<endl;
	
	cout<<"Rua: "<<endl;
	cin.sync();
	getline(cin,rua);
	
	loop = true;
	do{
		cout<<"CEP: "<<endl;
		cin >> cep;
		if (cep == "0"){
			cep = "00000000";
			loop = false;
		}
		else{
			cep = Logradouro::validaCEP(cep);
			if (cep == "00000000"){
				cout<<"CEP invalido! Caso nao saiba o CEP, defina o CEP do local como 0."<<endl;
				getch();
			}
		}
	}while(loop);
	
	cout<<"Referencia: "<<endl;
	cin.sync();
	getline(cin,referencia);
	
	if (pt == 1)
		this->pontos.push_back(PontoTuristico(nome,cep,rua,referencia,area,descricao,fundacao));
	else
		this->pontos.push_back(Logradouro(nome,cep,rua,referencia,area,descricao));
}

bool Bairro::mostrarPontos() const{
	if (this->pontos.empty()){
		cout<<"Nao ha nenhum ponto registrado no bairro!"<<endl;
		getch();
		return false;
	}
	else{
		cout<<"Pontos registrados no bairro "<<this->nome<<": "<<endl;
	
		for (unsigned int i = 0;i < this->pontos.size();i++)
			cout<<i + 1<<". "<<this->pontos[i].getNome()<<endl;
		getch();
		
		return true;
	}
}

const Logradouro* Bairro::buscaPonto(const string &nomePonto){
	for (unsigned int i = 0;i < this->pontos.size();i++)
		if (this->pontos[i].getNome() == nomePonto)
			return &(this->pontos[i]);
	
	return 0;
}

void Bairro::mostraPrincipaisRuas() const{
	cout<<"Principais ruas do bairro "<<this->nome<<": "<<endl;
	for (unsigned int i = 0;i < this->ruas.size();i++)
		cout<<i + 1<<". "<<this->ruas[i]<<"."<<endl;
}

Bairro Bairro::operator +=(const Bairro &B){
	if (this->area == -1 || B.area == -1)
		this->area++;
		
	this->area += B.area;
	
	return *this;
}

Bairro Bairro::operator =(const Bairro &B){
	this->area = B.area;
	this->nome = B.nome;
	this->descricao = B.descricao;
	this->comentarios = B.comentarios;
	this->ruas = B.ruas;
	this->pontos = B.pontos;
	
	return *this;
}