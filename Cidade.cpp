#include "Cidade.h"
#include <conio.h>
#include <cstdlib>

ostream &operator << (ostream &output,Cidade &C){
	output<<"Cidade de ";
	output<<static_cast<const Localidade &>(C);
	output<<"Numero de habitantes: ";
	if (C.nhabitantes == -1)
		output<<"Indisponivel!"<<endl;
	else
		output<<C.nhabitantes<<endl;
	output<<"Data de fundacao: "<<C.fundacao<<"("<<C.calculaIdade()<<" anos)."<<endl;
	
	return output;
}

Cidade::Cidade(string nome, int nhabitantes, float area, Data fundacao, string descricao)
:Localidade(nome,area,descricao),fundacao(fundacao)
{
	if (nhabitantes < -1)
		this->nhabitantes = -1;
	else
		this->nhabitantes = nhabitantes;
}

Cidade::Cidade(const string &nome, float area)
:Localidade(nome,area),nhabitantes(-1),fundacao(Data()){}

Cidade::Cidade(const Cidade &C)
:Localidade(C){
	this->nhabitantes = C.nhabitantes;
	this->fundacao = C.fundacao;
	this->bairros = C.bairros;
}

Cidade::~Cidade()
{
}

Bairro Cidade::getBairro(int indice){
	if (indice >= 1 && (unsigned int) indice <= this->bairros.size())
		return this->bairros[indice - 1];
	else
		return Bairro();
}

void Cidade::setBairro(int indice, const Bairro &B){
	if (indice >= 1 && (unsigned int) indice <= this->bairros.size())
		this->bairros[indice - 1] = B;
	else
		return ;
}

void Cidade::mostrarComentarios() const{
	cout<<"Comentarios sobre a cidade de "<<this->nome<<": "<<endl;
	
	for (unsigned int i = 0;i < this->comentarios.size();i++)
		cout<<"Comentario "<<i + 1<<endl<<comentarios[i]<<endl;
}

void Cidade::atualizaComentarios(const string &username, string &novousername){
	Localidade::atualizaComentarios(username,novousername);
	
	for (unsigned int i = 0;i < this->bairros.size();i++)
		this->bairros[i].atualizaComentarios(username,novousername);
}

void Cidade::insereBairro(const Bairro &B){
	this->bairros.push_back(B);
	
	cout<<"Bairro "<<B.getNome()<<" adicionado!"<<endl;
	getch();
}

void Cidade::mostraBairros() const{
	if (this->bairros.empty()){
		cout<<"Nao ha nenhum bairro cadastrado na cidade de "<<this->nome<<"! "<<endl;
		getch();
	}
	else{
		cout<<"Lista de bairros da cidade de "<<this->nome<<". "<<endl;
		for (unsigned int i = 0;i < this->bairros.size();i++)
			cout<<i + 1<<". "<<this->bairros[i].getNome()<<". "<<endl;
	}
}

/*
void Cidade::acessaBairro(int indice,Usuario *user){
	int opcao;
	
	if (indice < 1 || (unsigned int)indice > this->bairros.size()){
		cout<<"Valor invalido!"<<endl;
		getch();
	}
	else{
		cout<<"Voce selecionou o Bairro "<<this->bairros[indice - 1].getNome()<<"! "<<endl;
		getch();
		
		do{
			system("cls");
			cout<<"Escolha uma opcao: "<<endl;
			cout<<"1. Informacoes sobre o bairro."<<endl;
			cout<<"2. Comentarios do bairro."<<endl;
			cout<<"3. Fazer um comentario sobre o bairro."<<endl;
			cout<<"4. Locais registrados do bairro."<<endl;
			cout<<"5. Registrar um local novo deste bairro."<<endl;
			cout<<"6. Voltar"<<endl;
			cin >> opcao;
			
			switch(opcao){
				case 1:
					cout<<"Informacoes sobre o Bairro: "<<endl;
					cout<<this->bairros[indice - 1];
					getch();
					break;
				case 2:
					this->bairros[indice - 1].mostrarComentarios();
					break;
				case 3:
					//user->comentar(this->bairros[indice - 1]);
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					break;
				default:
					cout<<"Valor invalido!"<<endl;
					getch();
					break;
			}
		}while(opcao != 6);
	}
}*/

Bairro * Cidade::buscaBairro(const string &nomebairro){
	for (unsigned int i = 0;i < this->bairros.size();i++)
		if (this->bairros[i].getNome() == nomebairro)
			return &(this->bairros[i]);
	
	return 0;
}

void Cidade::buscaPonto(const string &nomeponto){
	Logradouro *tmplog;
	int cont,nponto;
	bool achou = false;
	vector <Logradouro *> ptrpontos;
	
	for (unsigned int i = 0;i < this->bairros.size();i++){
		//cont = 0;
		tmplog = const_cast<Logradouro *>(this->bairros[i].buscaPonto(nomeponto));
		
		if (tmplog){
			achou = true;
			ptrpontos.push_back(tmplog);
			//cont++;
			cout<<"Bairro: "<<this->bairros[i].getNome()<<": "<<endl;
			cout<<ptrpontos.size()<<". "<<tmplog->getNome();
		}
	}
	
	if (achou){
		getch();
		do{
			cout<<"Selecione o numero do ponto que voce deseja visualizar: "<<endl;
			cin >> nponto;
			if (nponto < 1 || nponto > ptrpontos.size()){
				cout<<"Opcao invalida!"<<endl;
				getch();
			}
		}while(nponto < 1 || nponto > ptrpontos.size());
		cout<<ptrpontos[nponto]<<endl;
	}
	else{
		cout<<"Local nao encontrado!"<<endl;
		getch();
	}
}

int Cidade::calculaIdade(){
	Data atual = Data::getDataAtual();
	
	if (atual.getMes() == this->fundacao.getMes() && atual.getDia() >= this->fundacao.getDia())
		return atual.getAno() - this->fundacao.getAno();
	else if (atual.getMes() > fundacao.getMes())
		return atual.getAno() - this->fundacao.getAno();
	else 
		return atual.getAno() - this->fundacao.getAno() - 1;
}

Cidade Cidade::operator +=(const Cidade &C){
	if (this->area == -1 || C.area == -1)
		this->area++;
	
	this->area += C.area;
	
	return *this;
}