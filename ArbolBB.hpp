#pragma once
#include <iostream>
#include <queue>
#include "Colisiones.hpp"

using namespace std;

template <class clave>class ArbolBB;


template <class clave>
class ArbolBB {

public:
	// Constructor:
	class nodoBB { // Clase local: nodo de ArbolBB
	public:
		// Constructor:
		nodoBB(clave dat, int niv = 0, nodoBB *iz = NULL,
			nodoBB *de = NULL) : dato(dat),
			nivel_(niv), izdo(iz), dcho(de) {}
		// Miembros:
		clave dato;
		int nivel_;
		nodoBB *izdo;
		nodoBB *dcho;
		Colisiones colision;
		void set_nivel(int n) {
			nivel_ = 0;
			nivel_ = n;
		}
		int get_nivel() { return nivel_; }

	};
	nodoBB* raiz_;

public:
	// constructores
	ArbolBB(); // constructor por defecto
	ArbolBB(nodoBB* r); // constructor con parametros
	ArbolBB(ArbolBB& a); // constructor de copia
	~ArbolBB();
	Colisiones colision;
	void Podar(nodoBB* &nodo);
	bool EsVacio();
	bool EsHoja(nodoBB *nodo);
	nodoBB* get_raiz() { return raiz_; }
	const int Tam();
	const int TamRama(nodoBB* nodo);
	const int Alt();
	const int AltN(nodoBB* nodo);
	int Buscar(clave clave_dada);
	int BuscarRama(nodoBB * nodo, clave clave_dada);
	void Insertar(clave clave_dada);
	void InsertarRama(nodoBB* &nodo, clave clave_dada);
	void Eliminar(clave clave_dada);
	void EliminarNodo(nodoBB* &nodo, clave clave_dada);
	void sustituye(nodoBB* &eliminado, nodoBB* &sust);
	void recorreN();
	void modo_estadistico(int n, int p);
};
//
//constructor por defecto
//
template <class clave>
ArbolBB<clave>::ArbolBB() : raiz_(NULL)
{}
//
//constructor con parametros
//
template <class clave>
ArbolBB<clave>::ArbolBB(nodoBB* r) : raiz_(r)
{}
//
//constructor de copia
//
template <class clave>
ArbolBB<clave>::ArbolBB(ArbolBB& a) : raiz_(a.get_raiz())
{}
//
// Destructor
//
template <class clave>
ArbolBB<clave>::~ArbolBB() {
	Podar(raiz_);
}
//
//metodo para podar el arbol
//
template<class clave>
void ArbolBB<clave>::Podar(nodoBB* &nodo) {

	if (nodo == NULL) return;
	Podar(nodo->izdo); // Podar subarbol izquierdo
	Podar(nodo->dcho); // Podar subarbol derecho
	delete nodo; // Eliminar nodo
	nodo = NULL;

}
//
// metodo apra saber si el arbol esta vacio
//
template <class clave>
bool ArbolBB<clave>::EsVacio() {
	return (raiz_ == NULL);
}
//
//metodo para saber si el nodo es hoja
//
template <class clave>
bool ArbolBB<clave>::EsHoja(nodoBB *nodo) {
	return ((nodo->dcho == NULL) && (nodo->izdo == NULL));
}
//
// metodos parasaber el tama�o del nodo
//
template <class clave>
const int ArbolBB<clave>::Tam() {
	return TamRama(raiz_);
}
//
//metodos parasaber el tama�o del nodo
//
template <class clave>
const int ArbolBB<clave>::TamRama(nodoBB* nodo) {
	if (nodo == NULL) {
		return 0;
	}
	return (1 + TamRama(nodo->izdo) + TamRama(nodo->dcho));
}
//
//metodo para saber la altura del nodo
//
template <class clave>
const int ArbolBB<clave>::Alt() {
	return AltN(raiz_);
}
//
//metodo para saber la altura del nodo
//
template <class clave>
const int ArbolBB<clave>::AltN(nodoBB* nodo) {
	if (nodo == NULL) {
		return 0;
	}
	int alt_i = AltN(nodo->izdo);
	int alt_d = AltN(nodo->dcho);
	if (alt_d > alt_i) {
		return alt_d++;
	}
	else {
		return alt_i++;
	}
}
//
//insersion de nodos
//
template <class clave>
void ArbolBB<clave>::Insertar(clave clave_dada) {
	InsertarRama(raiz_, clave_dada);
}
//
//insertar rama
//
template<class clave>
void ArbolBB<clave>::InsertarRama(nodoBB* &nodo, clave clave_dada) {
	if (nodo == NULL) {
		nodo = new nodoBB(clave_dada);
	}
	else if (clave_dada.get_base() == nodo->dato.get_base()) {
		cout << "El elemento ya se encuentra en el arbol" << endl;
		colision.contador();
		cout << colision.getX() << "COLISION " << endl;
		cout << endl;
	}
	else if (clave_dada.get_base() < nodo->dato.get_base()) {
		InsertarRama(nodo->izdo, clave_dada);
	}
	else {
		InsertarRama(nodo->dcho, clave_dada);
	}
}
//
//Eliminar ramas
//
template<class clave>
void ArbolBB<clave>::Eliminar(clave clave_dada) {
	EliminarNodo(raiz_, clave_dada);
}

//
//Eliminar ramas
//
template<class clave>
void ArbolBB<clave>::EliminarNodo(nodoBB* &nodo, clave clave_dada) {


	if (clave_dada <nodo->dato)
		EliminarNodo(nodo->izdo, clave_dada);
	else if (clave_dada > nodo->dato)
		EliminarNodo(nodo->dcho, clave_dada);
	else { 
		nodoBB* Eliminado = nodo;
		if (nodo->dcho == NULL)
			nodo = nodo->izdo;
		else if (nodo->izdo == NULL)
			nodo = nodo->dcho;
		else
			sustituye(Eliminado, nodo->izdo);
		delete (Eliminado);
	}

}
//
//Metodo para sustituir un nodo
//
template<class clave>
void ArbolBB<clave>::sustituye(nodoBB* &eliminado, nodoBB* &sust) {
	if (sust->dcho != NULL) {
		sustituye(eliminado, sust->dcho);
	}
	else {
		eliminado->dato.set_base(sust->dato.get_base());
		eliminado = sust;
		sust = sust->izdo;
	}
}


//
//Metodos para buscar
//
template<class clave>
int ArbolBB<clave>::Buscar(clave clave_dada) {
	return BuscarRama(raiz_, clave_dada);
}
//
//metodos para buscar
//
template<class clave>
int ArbolBB<clave>::BuscarRama(nodoBB* nodo, clave clave_dada) {
	if (clave_dada == nodo->dato) {
		return nodo->dato.get_base();
	}
	if (clave_dada< nodo->dato) {
		return BuscarRama(nodo->izdo, clave_dada);
	}
	return BuscarRama(nodo->dcho, clave_dada);
}

//
//Recorrido por niveles
//
template<class clave>
void ArbolBB<clave>::recorreN() {
	queue<nodoBB*> Q;
	nodoBB *nodo;
	int nivel = 0;
	int nivel2 = 0;
	int Nivel_actual = 0;
	int aux_control = 0;
	Q.push(raiz_);
	cout << " Nivel " << raiz_->get_nivel() << " [" << raiz_->dato.get_base() << "]" << endl;
	while (!Q.empty()) {
		nodo = Q.front();
		Q.pop();
		if (nodo->get_nivel() != Nivel_actual) {
			cout << endl;
			Nivel_actual = nodo->get_nivel();
			nivel = Nivel_actual;
			nivel2 = Nivel_actual;
			aux_control = 0;
		}
		if (nodo != NULL) {
			if (aux_control == 0) {
				aux_control = 1;
				cout << " Nivel " << nodo->get_nivel() + 1;
			}
			if (nodo->izdo != NULL) {
				nodo->izdo->set_nivel(nivel + 1);
				cout << " [" << nodo->izdo->dato.get_base() << "] ";
				Q.push(nodo->izdo);
			}

			else {
				cout << " [.]";
			}

			if (nodo->dcho != NULL) {
				nodo->dcho->set_nivel(nivel2 + 1);
				cout << " [" << nodo->dcho->dato.get_base() << "] ";
				Q.push(nodo->dcho);
			}
			else {
				cout << " [.]";
			}

		}
		else {
			cout << Nivel_actual << " : [.]";
		}
	}
	cout << endl;
}
//
// modo estadistico
//
template<class clave>
void ArbolBB<clave>::modo_estadistico(int n, int p) {

	clave* banco;
	clave muestra;
	int* incersion_;
	int prueba;
	incersion_ = new int[n];
	int maximo = Alt();
	banco = new clave[n];
	for (int i = 0; i<n; i++) {
		banco[i].set_dni(i);
		cout << " Banco  -> " << banco[i].get_base() << endl;
		banco[i].generar_dni();
		cout << " Banco  -> generar_dni " << banco[i].get_base() << endl;
		Insertar(banco[i]);
		incersion_[i] = banco[i].get_medio();
		cout << " medio -> " << banco[i].get_medio() << endl;
		cout << " vector medio insercion  -> " << incersion_[i] << endl;
	}

	for (int i = 0; i<p; i++) {
		banco[i].set_medio(0);
		prueba = Buscar(banco[i]);
		cout << "-----------------------------------------------------------------" << endl;
		cout << "             N    " << "P    " << "Minimo    " << "Medio    " << "Maximo" << endl;
		cout << "busqueda : " << n << "   " << p << "   " << 1 << "   " << banco[i].get_medio() << "   " << maximo << endl;
		cout << "insercion: " << n << "   " << p << "    " << 1 << "   " << incersion_[i] << "   " << maximo << endl;
		cout << "Clave probada :   " << prueba << endl;
	}

}













