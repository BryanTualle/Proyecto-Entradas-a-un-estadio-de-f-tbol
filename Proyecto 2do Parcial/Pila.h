#include "string.h"
#include "iostream"
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"

using namespace std;

class Pila
{
	private:
		char simbolo[10];
		Pila *siguiente;

	public:
		Pila();
		Pila(char []);

		char *GetSimbolo();
		void SetSimbolo(char argumento[]);
		void SetSimbolo(char argumento);

		Pila* GetPila();
		void SetPila(Pila *pila);

		//void IngresoPila(Pila *&, int valor);
		//void ImprimirPila(Pila *&pila);

		//////////////////
		void crearPila(Pila *&);
		void insertarPush(char simbolo[], Pila *&);
       	void insertarPilaFinal (char simbolo[], Pila *&);
        void extraerPop(char valor[], Pila *&);
        void imprimirExpresion(Pila *lista);
		void infijaPostfija(char expresion[]);
		void infijaPrefija(char expresion[]);
		void obtenerExpresion(Pila *lista, char expresion[]);


};

Pila::Pila()
{
}

Pila::Pila(char caracter[])
{
	strcpy(simbolo, caracter);
	//simbolo = caracter;

}

char* Pila::GetSimbolo()
{
	return simbolo;
}

void Pila::SetSimbolo(char argumento[])
{
	int limi = 0;
	limi = strlen(argumento);
	
	for(int i=0; i<limi; i++) 
	{
		simbolo[i] = argumento[i];	
	}
	simbolo[limi]='\0';
	
	
	argumento[1]=='\0';
}

void Pila::SetSimbolo(char argumento)
{
	char valor[2];
	valor[0] = argumento;
	valor[1] = '\0';
	
	
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

void Pila::insertarPush(char simbolo[], Pila *&pila) //INGRESO TOPE DE LA PILA, INICIO LISTA
{
	Pila *nuevo = new Pila();
	
	if(nuevo!=NULL)
	{
		strcpy(nuevo->GetSimbolo(),simbolo);
		//cout<<"\n "<<nuevo->simbolo;
		nuevo->siguiente = pila;
		pila = nuevo;
	}
}

void Pila::insertarPilaFinal (char simbolo[], Pila *&pila)
{
	Pila *nuevo = new Pila();
	Pila *aux;
	
	if(nuevo!=NULL)
	{
		nuevo->SetSimbolo(simbolo);
		nuevo->siguiente = NULL;
		
		//cout<< "\n NUEVO "<<nuevo->simbolo<<endl;
		//getch();
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
			//pila = aux;
		}
	}
	
}

void Pila::extraerPop(char valor[], Pila *&pila)
{
	Pila *aux;
	char dato[10];
	
	/*
	if(pila == NULL)
	{
		cout<<"\nPILAS VACIA!!";
	}
	else
	{
		aux = pila;
		strcpy(dato, aux->GetSimbolo());
		//dato = aux->simbolo;
		aux = aux->GetPila();
		pila = aux;
		strcpy(valor, dato);
	}
	*/
	if(pila != NULL)
	{
		aux = pila;
		strcpy(dato, aux->GetSimbolo());
		//dato = aux->simbolo;
		aux = aux->GetPila();
		pila = aux;
		strcpy(valor, dato);
	}

}

void Pila::imprimirExpresion(Pila *lista)
{
	Pila *aux;
	
	aux = lista;
	
	while(aux!=NULL)
	{
		cout<<" "<<aux->simbolo;
		//cout<<" 1 |"<<aux->simbolo;
		aux = aux->siguiente;
	}
}

void Pila::obtenerExpresion(Pila *lista, char expresion[])
{
	
	Pila *aux;
	int i=0;
	aux = lista;
	char vacia[2];
	vacia[0]=32;
	vacia[1]='\0';
	
	
	for(i=0; i<strlen(expresion); i++)
	{
		expresion[i]='\0';
	}
	
	//expresion[0]='\0';	
	do
	{
		strcat(expresion, aux->simbolo);
		strcat(expresion, vacia);
		//strcat()expresion[i+2]= '\0';
		//expresion[i]=aux->simbolo;
		aux = aux->siguiente;
		i++;
	}while(aux!=NULL);
	//expresion[i]='\0';

}

// revisar funcion obtener expresion



