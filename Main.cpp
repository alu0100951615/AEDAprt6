#include <iostream>
#include <stdio.h>
#include "ArbolBB.hpp"
#include "DNI.hpp"
using namespace std;


int main() {

	ArbolBB<DNI> a;
	ArbolBB<DNI> c;
	int opcion, opcion2, num;
	int p, n;
	DNI b;

	do {


		cout << "|-----------------------------------|" << endl;
		cout << "|               Menu                |" << endl;
		cout << "|1)       Modo Demostracion         |" << endl;
		cout << "|2)       Modo Estadistico          |" << endl;
		cout << "|0)             Salir               |" << endl;
		cout << "|   introduzca una opcion por favor |" << endl;
		cout << "|-----------------------------------|" << endl;
		cin >> opcion;
		switch (opcion) {


		case  1: {
			do {
				cout << "|-----------------------------------|" << endl;
				cout << "|              Menu                 |" << endl;
				cout << "|1)         insertar clave          |" << endl;
				cout << "|2)         eliminar clave          |" << endl;
				cout << "|0)            Salir                |" << endl;
				cout << "|   introduzca una opcion por favor |" << endl;
				cout << "|-----------------------------------|" << endl;
				cin >> opcion2;
				switch (opcion2) {

				case 1: {
					if (a.EsVacio()) {
						cout << "Arbol vacio" << endl;
						cout << " Nivel " << 0 << "[.]" << endl;
					}
					cout << "Inserte un numero en el arbol" << endl;
					cin >> num;
					b.set_base(num);
					a.Insertar(b);
					a.recorreN();
					break;
				}
				case 2: {

					if (a.EsVacio()) {
						cout << "Arbol vacio" << endl;
						cout << " Nivel " << 0 << "[.]" << endl;
					}
					cout << "Inserte un numero en el arbol" << endl;
					cin >> num;
					b.set_base(num);
					a.Eliminar(b);
					a.recorreN();

					break;
				}
				default: {
					opcion2 = 0;
					break;
				}
				}
			} while (opcion2 != 0);


			break;
		}
		case 2: {
			cout << "por favor introduzca el numero de nodos del arbol" << endl;
			cin >> n;
			cout << "por favor intorduzca el numero de pruebas del arbol" << endl;
			cin >> p;
			c.modo_estadistico(n, p);

		}
		case 0: opcion = 0; break;
		}

	} while (opcion != 0);



}
