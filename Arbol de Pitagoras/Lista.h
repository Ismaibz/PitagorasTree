// Cola doblemente enlazada en C++
// (C) Septiembre 2001, Salvador Pozo
// C con Clase: http://c.conclase.net

#include <iostream>
using namespace std;
template<class TIPO> class Lista;

template<class TIPO>
class nodo {
   public:
    nodo(TIPO v, nodo<TIPO> *sig = NULL, nodo<TIPO> *ant = NULL) :
       dato(v), siguiente(sig), anterior(ant) {}

   private:
    TIPO dato;
    nodo<TIPO> *siguiente;
    nodo<TIPO> *anterior;

   friend class Lista<TIPO>;
};

template<class TIPO>
class Lista {
   public:
    Lista() : primero(NULL), ultimo(NULL), actual(NULL), numElem(0) {}
    ~Lista();

    void InsertarFinal(const TIPO v);
    void InsertarPrincipio(const TIPO v);
    void Borrar(TIPO v);
    bool ListaVacia() { return primero == NULL; }
    void Mostrar(int);
    void Siguiente() { if(actual) actual = actual->siguiente; }
    void Anterior() { if(actual) actual = actual->anterior; }
    void Primero() { actual = primero; }
    void Ultimo(){ actual = ultimo; }
    bool Actual() { return actual != NULL; }
    TIPO ValorActual() { return actual->dato; }
	int numElem;
	
   private:
    nodo<TIPO> *primero;
	nodo<TIPO> *ultimo;
	nodo<TIPO> *actual;
};

template<class TIPO>
Lista<TIPO>::~Lista() {
   nodo<TIPO> *aux;

   Primero();
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }               
}

template<class TIPO>
void Lista<TIPO>::InsertarFinal(TIPO v) {

   // Si la Lista está vacía, insertar al principio:
   if(ListaVacia()) InsertarPrincipio(v);
   else { // Si no lo está:
     nodo<TIPO> *pnodo = new nodo<TIPO>(v,NULL,ultimo);
     ultimo->siguiente  = pnodo;
     ultimo = pnodo;

   }
   numElem++;
}


template<class TIPO>
void Lista<TIPO>::InsertarPrincipio(TIPO v) {
	nodo<TIPO> *pnodo = new nodo<TIPO>(v,primero,NULL);
   if(ListaVacia())
   {
        primero = pnodo;
        ultimo = pnodo;
   }
   else
   {
   	primero->anterior = pnodo;
   	primero = pnodo;
   }
		
   numElem++;
}

template<class TIPO>
void Lista<TIPO>::Borrar(TIPO v) {
   nodo<TIPO> *pnodo;

   pnodo = primero;
   while(pnodo && pnodo->dato < v) pnodo = pnodo->siguiente;
   while(pnodo && pnodo->dato > v) pnodo = pnodo->anterior;

   if(!pnodo || pnodo->dato != v) return;
   // Borrar el nodo

   if(pnodo->anterior) // no es el primer elemento
      pnodo->anterior->siguiente = pnodo->siguiente;
   if(pnodo->siguiente) // no el el último nodo
      pnodo->siguiente->anterior = pnodo->anterior;
}

template<class TIPO>
void Lista<TIPO>::Mostrar(int orden) {
   nodo<TIPO> *pnodo;
   if(orden == ASCENDENTE) {
      Primero();
      pnodo = primero;
      while(pnodo) {
         cout << pnodo->dato << "-> ";
         pnodo = pnodo->siguiente;
      }
   }
   else {
      Ultimo();
      pnodo = primero;
      while(pnodo) {
         cout << pnodo->dato << "-> ";
         pnodo = pnodo->anterior;
      }
   }
   cout << endl;
}


