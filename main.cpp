#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Moderador.h"
#include "Cidade.h"


using namespace std;

int main(int argc, char **argv)
{
	string descricao = "Bairro nobre de Belém. E' onde esta localizada a Basilica de Nossa Senhora de Nazare.";
	Bairro B("Nazare",-1,descricao);
	
	cout<<B<<endl;
	B.inserePonto();
	
	B.mostrarPontos();
}
