/* 
 * File:   Data.cpp
 * Author: Cssj
 * 
 * Created on 9 de Junho de 2012, 14:47
 */

#include "Data.h"

#include <iostream>
#include <ctime>
#include <conio.h>
using std::cout;

ostream &operator <<(ostream &output, const Data &D){
	if (D.dia < 10)
		output<<'0';
	output<<D.dia<< '/';
	if (D.mes < 10)
		output<<'0';
	output<<D.mes<< '/';
	output<<D.ano;
	
	return output;
}

bool operator == (Data &d1, Data &d2){
	if (d1.dia == d2.dia && d1.mes == d2.mes && d1.ano == d2.ano)
		return true;
	else
		return false;
}

Data::Data(int d, int m, int a) 
{
    if ( m > 0 && m <= 12 ) // validate the month
		mes = m;
    
    if ( a < 0 )
        ano = 1900;
    else
        ano = a;
   
    dia = VerificaDia(d);

}

Data::Data(const Data &D){
	this->dia = D.dia;
	this->mes = D.mes;
	this->ano = D.ano;
}

int Data::getDia(){
	return this->dia;
}

int Data::getMes(){
	return this->mes;
}

int Data::getAno(){
	return this->ano;
}

int Data::VerificaDia(int diaTeste) const
{
    static const int diasPorMes[ 13 ] = 
       { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    if ( diaTeste > 0 && diaTeste <= diasPorMes[ mes ] )
        return diaTeste;
    
    if ( mes == 2 && diaTeste == 29 && ( ano % 400 == 0 ||
            ( ano % 4 == 0 && ano % 100 != 0 ) ) )
        return diaTeste;
    
    cout << "Dia invalido (" << diaTeste << ") configurado para 1.\n";
	getch();
    return 1; 

    
}

Data Data::getDataAtual() {
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    int ano = (now->tm_year + 1900);
    int mes = (now->tm_mon + 1);
	int dia = now->tm_mday;
    
	Data D(dia,mes,ano);
	
	return D;
}

Data Data::operator +=(const Data &D){
	this->dia += D.dia;
	this->mes += D.mes;
	this->ano += D.ano;
	
	return *this;
}