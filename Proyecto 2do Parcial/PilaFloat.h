#include "string.h"
#include "iostream"
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"

using namespace std;

class PilaFloat
{
	private:
		float valor;
		PilaFloat *siguiente;

	public:
		PilaFloat();
		PilaFloat(float);

		float GetValor();
		void SetValor(float argumento);

		PilaFloat* GetPilaFloat();
		void SetPilaFloat(PilaFloat *pila);
		
		//void IngresoPila(Pila *&, int valor);
		//void ImprimirPila(Pila *&pila);

		//////////////////
		void crearPilaFloat(PilaFloat *&);
		void insertarPushFloat(float simbolo, PilaFloat *&);
       	//void insertarPilaFinal (char simbolo, PilaFloat *&)
        void extraerPopFloat(float *valor, PilaFloat *&);
        //void imprimirExpresion(Pila *pila);
		//void infijaPostfija(char expresion[]);
		//void infijaPrefija(char expresion[]);


};

PilaFloat::PilaFloat()
{
}

PilaFloat::PilaFloat(float simbolo)
{
	valor = simbolo;

}

float PilaFloat::GetValor()
{
	return valor;
}

void PilaFloat::SetValor(float argumento)
{
	valor = argumento;
}

PilaFloat* PilaFloat::GetPilaFloat()
{
	return siguiente;
}

void PilaFloat::SetPilaFloat(PilaFloat *pila)
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
void PilaFloat::crearPilaFloat(PilaFloat *&pila)
{
	pila = NULL;
}

void PilaFloat::insertarPushFloat(float valor, PilaFloat *&pila) //INGRESO TOPE DE LA PILA, INICIO LISTA
{
	PilaFloat *nuevo = new PilaFloat();
	
	if(nuevo!=NULL)
	{
		nuevo->valor = valor;
		nuevo->siguiente = pila;
		pila = nuevo;
	}
}
/*
void Pila::insertarPilaFinal (char simbolo, PilaFloat *&pila)
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
}*/

void PilaFloat::extraerPopFloat(float *valor, PilaFloat *&pila)
{
	PilaFloat *aux = new PilaFloat();
	float dato;

	if(pila == NULL)
	{
		cout<<"\nPILAS VACIA!!";
	}
	else
	{
		aux = pila;
		dato = aux->valor;
		pila = aux->siguiente;
		*valor = dato;
	}

}
/*
void Pila::imprimirExpresion(Pila *lista)
{
	Pila *aux = new Pila();
	
	aux = lista;
	cout<<"\nPOSTFIJA";
	while(aux!=NULL)
	{
		cout<<" "<<aux->simbolo;
		aux = aux->siguiente;
	}
}
*/





