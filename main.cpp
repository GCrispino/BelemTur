#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Moderador.h"
#include "Cidade.h"


using namespace std;

int main(int argc, char **argv)
{
	Cidade C("Belem",287285,291387,Data(12,1,1616));
	
	cout<<C;
}
