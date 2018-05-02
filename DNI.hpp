#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
using namespace std;
typedef  int Index_t;
const int dni_min = 30000000;
class DNI {
	int dni_;
	int base_;
	int medio;
public:
	DNI();
	DNI(int& d);
	DNI(DNI& x);
	void generar_dni();
	int get_base();
	void set_dni(int x) { base_ = x; }
	void set_base(int x) { dni_ = x; }
	bool operator>(DNI&);
	bool operator>(int&);
	bool operator< (int&);
	Index_t operator %(int&);
	DNI operator /(int&);
	bool operator<(DNI&);
	bool operator==(DNI&);
	bool operator!=(DNI&);
	DNI operator=(const  DNI&);
	DNI operator=(const int&);
	int get_medio();
	void set_medio(const int  a) { medio = a; }

};