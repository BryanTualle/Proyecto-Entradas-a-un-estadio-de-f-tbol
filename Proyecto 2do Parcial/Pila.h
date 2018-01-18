#include "string.h"
#include "iostream"
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"

using namespace std;

class Pila
{
	private:
		char simbolo;
		Pila *siguiente;

	public:
		Pila();
		Pila(char);

		char GetSimbolo();
		void SetSimbolo(char argumento);

		Pila* GetPila();
		void SetPila(Pila *pila);

		//void IngresoPila(Pila *&, int valor);
		//void ImprimirPila(Pila *&pila);

		//////////////////
		void crearPila(Pila *&);
		void insertarPush(char simbolo, Pila *&);
       	void insertarPilaFinal (char simbolo, Pila *&);
        void extraerPop(char *valor, Pila *&);
        void imprimirExpresion(Pila *lista);
		void infijaPostfija(char expresion[]);
		void infijaPrefija(char expresion[]);


};

Pila::Pila()
{
}

Pila::Pila(char caracter)
{
	simbolo = caracter;

}

char Pila::GetSimbolo()
{
	return simbolo;
}

void Pila::SetSimbolo(char argumento)
{
	simbolo = argumento;
}

Pila* Pila::GetPila()
{
	return siguiente;
}

void Pila::SetPila(Pila *pila)
{
	siguiente = pila->siguiente;
}




/*
void Pila::IngresoPila( Pila *&pila, int valor)
{
	Pila *nuevo = new Pila();

	nuevo->dato = valor;
	nuevo->siguiente = pila;
	pila = nuevo;

}

void Pila::ImprimirPila(Pila *&pila)
{
	Pila *nuevo = new Pila();


	if(pila!= NULL)
	{
		printf("\n\nPIla:");
		do
		{
			nuevo = pila;
			printf("\n%d", nuevo->dato);
			pila = nuevo->siguiente;
		}while(pila!= NULL);
		pila = NULL;
	}
	else
	{
		printf("\nPila Vacia");
	}

}
*/

////////////////////////////////////////////////////////////////////////////////////
void Pila::crearPila(Pila *&pila)
{
	pila = NULL;
}

void Pila::insertarPush(char simbolo, Pila *&pila) //INGRESO TOPE DE LA PILA, INICIO LISTA
{
	Pila *nuevo = new Pila();
	
	if(nuevo!=NULL)
	{
		nuevo->simbolo = simbolo;
		nuevo->siguiente = pila;
		pila = nuevo;
	}
}

void Pila::insertarPilaFinal (char simbolo, Pila *&pila)
{
	Pila *nuevo = new Pila();
	Pila *aux;
	
	if(nuevo!=NULL)
	{
		nuevo->simbolo = simbolo;
		nuevo->siguiente = NULL;
		if(pila == NULL)
		{
			pila = nuevo;
		}
		else
		{
			aux = pila;
			while(aux->siguiente != NULL)
			{
				aux = aux->siguiente;
			}
			aux->siguiente = nuevo;
		}
	}
}

void Pila::extraerPop(char *valor, Pila *&pila)
{
	Pila *aux = new Pila();
	char dato;

	if(pila == NULL)
	{
		cout<<"\nPILAS VACIA!!";
	}
	else
	{
		aux = pila;
		dato = aux->simbolo;
		pila = aux->siguiente;
		*valor = dato;
	}

}

void Pila::imprimirExpresion(Pila *lista)
{
	Pila *aux = new Pila();
	
	aux = lista;
	cout<<"\nPREFIJA";
	while(aux!=NULL)
	{
		cout<<" "<<aux->simbolo;
		aux = aux->siguiente;
	}
}





