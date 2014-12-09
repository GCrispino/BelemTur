#include "stringDigitos.h"
#include <iostream>

using namespace std;

bool stringDigitos(const string &s){
	if (s.empty())
		return false;
	for (unsigned int i = 0;i < s.size();i++)
		if (isdigit(s[i]) == 0)
			return false;
	
	return true;
}

string maiuscula(const string &s){
	string s2;
	for (unsigned int i = 0;i < s.size();i++)
		s2.push_back(toupper(s[i]));
		
	return s2;
}