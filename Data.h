/* 
 * File:   Data.h
 * Author: Cssj
 *
 * Created on 9 de Junho de 2012, 14:47
 */
#include <iostream>

using namespace std;

#ifndef DATA_H
#define	DATA_H

class Data 
{

friend ostream &operator << (ostream &,const Data &);
friend bool operator == (Data &, Data &);
	
public:
    
    Data( int = 1, int = 1, int = 1900 );
	
	static Data getDataAtual(); //retorna a data do sistema
	
private:
    
    int mes;
    int dia;
    int ano;
    
    int VerificaDia( int ) const;

	Data operator +=(const Data &);
};

#endif	/* DATA_H */

