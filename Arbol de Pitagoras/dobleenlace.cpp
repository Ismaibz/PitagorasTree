// Cola doblemente enlazada en C++
// (C) Septiembre 2001, Salvador Pozo
// C con Clase: http://c.conclase.net

#include <iostream>
using namespace std;
template<class TIPO> class lista;

template<class TIPO>
class nodo {
   public:
    nodo(TIPO v, nodo<TIPO> *sig = NULL, nodo<TIPO> *ant = NULL) :
       dato(v), siguiente(sig), anterior(ant) {}

   private:
    TIPO dato;
    nodo<TIPO> *siguiente;
    nodo<TIPO> *anterior;

   friend class lista<TIPO>;
};

template<class TIPO>
class lista {
   public:
    lista() : primero(NULL), ultimo(NULL), actual(NULL), numElem(0) {}
    ~lista();

    void InsertarFinal(const TIPO v);
    void InsertarPrincipio(const TIPO v);
    void Borrar(TIPO v);
    bool ListaVacia() { return primero == NULL; }
    void Mostrar(int);
    void Siguiente() { if(actual) actual = actual->siguiente; }
    void Anterior() { if(actual) actual = actual->anterior; }
    void Primero() { actual = primero; }
    void Ultimo(){ actual = ultimo; }
    bool Actual() { return primero != NULL; }
    TIPO ValorActual() { return primero->dato; }
	int numElem;
	
   private:
    nodo<TIPO> *primero;
	nodo<TIPO> *ultimo;
	Nodo<DATO> *actual;
};

template<class TIPO>
lista<TIPO>::~lista() {
   nodo<TIPO> *aux;

   Primero();
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }               
}

template<class TIPO>
void lista<TIPO>::InsertarFinal(TIPO v) {
   // Si la lista está vacía, insertar al principio:
   if(Vacia()) InsertarPrincipio(v);
   else { // Si no lo está:
     ultimo->siguiente = new Nodo<TIPO>(v, NULL, ultimo);
	 ultimo = ultimo->siguiente;
   }
   numElem++;
}


template<class TIPO>
void lista<TIPO>::InsertarPrincipio(TIPO v) {
	nodo<TIPO> *pnodo = new Nodo<TIPO>(v,primero,NULL);;
   if(Vacia())
		primero = pnodo;
	else
	{
		primero->anterior = pnodo;
		primero = pnodo;
	}
		
   numElem++;
}

template<class TIPO>
void lista<TIPO>::Borrar(TIPO v) {
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
void lista<TIPO>::Mostrar(int orden) {
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

template<class TIPO>
void lista<TIPO>::Siguiente() {
   if(primero) primero = primero->siguiente;
}

template<class TIPO>
void lista<TIPO>::Anterior() {
   if(primero) primero = primero->anterior;
}

