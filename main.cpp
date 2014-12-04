#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Moderador.h"
#include "Cidade.h"


using namespace std;

int main(int argc, char **argv)
{
	Usuario U;
	U.setUsername("joaozinho");
	Comentario C("Voces sabem qual eh a capital da Bielorussia?",Data::getDataAtual(),"610V4N1M");
	Moderador M;
	M.setUsername("joaozinho");
	
	cout<<C<<endl;
	
	
	U.editarComentario(C);
	M.editarComentario(C);
	
	cout<<C<<endl;
}
