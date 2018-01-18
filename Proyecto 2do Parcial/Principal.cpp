/*
						"UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE"
								ESTRUCTURA DE DATOS 2479"
				
					Calculadora Polaca Inversa en Notacion Prefija y Postfija
	Autores: 	Sandra Castro  y  Bryan Tualle
	Fecha:	 	2/1/2018
	Profesor:	Ing. Edgar Fernando Solis Acosta
	Carrera:	Ing. Sistemas e informatica
*/

#include <iostream>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#include <math.h>
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include "Pila.h"
#include "PilaFloat.h"


using namespace std;


//PROTOTIPOS DE FUNCIONES
int expresionBalanceada (char []);
int esOperador(char );
int prioridad (char );
Pila *infijaPostfija(char []);
Pila *infijaPrefija(char []);
void GenerarAudio(char []);

//////////////////////////////////////////////////
//Programa Principal
main()
{
	char expresion[50];
	Pila *postFija, *preFija;
	int opcion;

	system("Cls");
	cout << "\t\t\t\t\tUNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE" << endl;
	cout << "\t\t\t\t\t\tESTRUCTURA DE DATOS 2479" << endl;
	cout << "\t\t\t\tCalculadora Polaca Inversa en Notacion Prefija y Postfija" << endl;
	cout << "\n\t\t\t\tAutores:\t Sandra Castro  y  Bryan Tualle" << endl;
	cout << "\t\t\t\tFecha:\t\t 2/1/2018" << endl;
	cout << "\t\t\t\tProfesor:\t Ing. Edgar Fernando Solis Acosta" << endl;
	cout << "\t\t\t\tCarrera:\t Ing. Sistemas e informatica" << endl << endl;
	bool ind = false;
	system("Color f9");
	string menu[] = { "1.-Notacion POSTfija","2.-Notacion PREfija","3.-Codigo QR","4.-Ayuda","5.-Generar PDF","6.-Salir" };
	for (int i = 0; i<6; i++) 
	{
		cout << menu[i] << endl;
	}
	
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hinput = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD Input;
	DWORD Events;
	COORD coord;
	CONSOLE_CURSOR_INFO inf;
	inf.dwSize = 20;
	inf.bVisible = false;
	SetConsoleCursorInfo(houtput, &inf);
	SetConsoleMode(hinput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	while (1) 
	{
		ReadConsoleInput(hinput, &Input, 1, &Events);
		if (Input.EventType == MOUSE_EVENT) 
		{
			if (Input.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) 
			{
				coord.X = Input.Event.MouseEvent.dwMousePosition.X;
				coord.Y = Input.Event.MouseEvent.dwMousePosition.Y;
				
				///////////////////////////////////////////////////////////////// OPCIÓN POSTFIJA
				for (int i = 0; i<19; i++) 
				{
					if (coord.X == i&&coord.Y == 9) 
					{
						ind = true;
						system("Color f9");
						system("cls");
						
						system("cls");
						cout<<"\nExpresion Infija: ";
						cin>>expresion;
						if(expresionBalanceada(expresion))
						{
							postFija = infijaPostfija(expresion);
							postFija->imprimirExpresion(postFija);
							cout<<endl<<endl;
							//GenerarAudio(expresion);
						}
						else
						{
							cout<<"\nExpresion no valida!!";
						}
								
						system("pause");
						main();
					}
				}
				
				///////////////////////////////////////////////////////////////// OPCIÓN PREFIJA
				for (int i = 0; i<20; i++ ) 
				{
					if (coord.X == i&&coord.Y == 10) 
					{
						ind = true;
						system("Color f9");
						system("cls");
						
						cout<<"\nExpresion Infija: ";
						cin>>expresion;
						if(expresionBalanceada(expresion))
						{
							preFija = infijaPrefija(expresion);
							preFija->imprimirExpresion(preFija);
							cout<<endl<<endl;
						}
						else
						{
							cout<<"\nExpresion no valida!!";
						}	
							
						system("pause");
						main();
					}
				}
				
				///////////////////////////////////////////////////////////////// OPCIÓN 3
				for (int i = 0; i<12; i++) 
				{
					if (coord.X == i&&coord.Y == 11) 
					{
						ind = true;
						system("Color f9");
						system("cls");
						cout << "AQUI VA LA OPCION 3" << endl;
						system("pause");

						main();
					}
				}
				
				///////////////////////////////////////////////////////////////// OPCIÓN AYUDA
				for (int i = 0; i<8; i++) 
				{
					if (coord.X == i&&coord.Y == 12) 
					{
						ind = true;
						system("Color f9");
						system("cls");
						ShellExecute(NULL, TEXT("open"), TEXT("G:\\ESPE 4 SEMESTRE\\ESTRUCTURAS\\Primer parcial\\Proyecto I\\Ayuda\\Ayuda Listas SimplesP.chm"), NULL, NULL, SW_SHOWNORMAL);
						main();
					}
				}
				
				///////////////////////////////////////////////////////////////// OPCIÓN 5
				for (int i = 0; i<14; i++) 
				{
					if (coord.X == i&&coord.Y == 13) 
					{
						ind = true;
						system("Color f9");
						system("cls");
						cout << endl << "Programa realizado por: Sandra Castro / Bryan Tualle" << endl;
						cout << "         <<<<<<CopyLeft P&C (licencia de codigo abierto)>>>>>>" << endl;
						system("pause");
						main();
					}
				}
				
				///////////////////////////////////////////////////////////////// OPCIÓN SALIR
				for (int i = 0; i<8; i++) 
				{
					if (coord.X == i&&coord.Y == 14) 
					{
						ind = true;
						system("Color f9");
						system("cls");
						cout << endl << "<<<<<<<<<Gracias por usar nuestro programa>>>>>>>>>" << endl;
						exit(1);
						main();
					}
				}
				
				if (!ind) 
				{
					main();
				}
				ind = false;
			}
		}
	}
	
}


//DESARROLLO DE FUNCIONES
int expresionBalanceada (char expresion[])
{
	Pila *pilaAuxiliar;
	int longitudExpresion;//Entrada
	char valor;
	pilaAuxiliar->crearPila(pilaAuxiliar);
	longitudExpresion = strlen(expresion);
	for(int i = 0; i<longitudExpresion; i++)
	{
		if(expresion[i] == '(')
		{
			pilaAuxiliar->insertarPush(expresion[i],pilaAuxiliar);
		}
		if(expresion[i] == ')')
		{
			pilaAuxiliar->extraerPop(&valor, pilaAuxiliar);
		}
	}
	if(pilaAuxiliar == NULL)
	{
		return 1;
	}
	return 0;
}

int esOperador(char simbolo)
{
	if((simbolo == '+')||(simbolo == '-')||(simbolo == '*')||(simbolo == '/')
	||(simbolo == '^'))
	{
		return 1;
	}
	return 0;
}

int prioridad (char operador)
{
	if(operador == '^')
	{
		return 3;
	}
	if((operador == '*')||(operador == '/'))
	{
		return 2;
	}
	if((operador=='+')||(operador=='-'))
	{
		return 1;
	}
	if((operador=='(')||(operador==')'))
	{
		return 0;
	}
}

Pila *infijaPostfija(char expresion[])
{
	Pila *pila;;
	Pila *postFija;
	int longitudExpresion;
	char valor;

	pila->crearPila(pila);
	postFija->crearPila(postFija);

	longitudExpresion = strlen(expresion);

	for(int i=0; i<longitudExpresion; i++)
	{
		if(((expresion[i]>=48)&&(expresion[i]<=57)) || ((expresion[i]>=65)&&(expresion[i]<=90))
		||((expresion[i]>=97)&&(expresion[i]<=122)))
		{
			postFija->insertarPilaFinal(expresion[i], postFija);
		}
		else
		{
			if(expresion [i]=='(')
			{
				pila->insertarPush(expresion[i], pila);
			}
			else
			{
				if(esOperador(expresion[i]))
				{
					if(pila==NULL)
					{
						pila->insertarPush(expresion[i], pila);
					}
					else
					{
						while(pila!=NULL)
						{
							if(prioridad(pila->GetSimbolo()) >= prioridad(expresion[i]))
							{
								pila->extraerPop(&valor,pila);
								postFija->insertarPilaFinal(valor,postFija);
							}
							else
							{
								break;
							}
						}
						pila->insertarPush(expresion[i], pila);
					}
				}
			}
		}
		if(expresion[i]==')')
		{
			while( (pila->GetSimbolo()!='(') && (pila!=NULL) )
			{
				pila->extraerPop(&valor,pila);
				postFija->insertarPilaFinal(valor,postFija);
			}
			pila->extraerPop(&valor,pila);
		}
	}
	while(pila!=NULL)
	{
		pila->extraerPop(&valor,pila);
		postFija->insertarPilaFinal(valor,postFija);
	}
	return postFija;
}


Pila *infijaPrefija(char expresion[])
{
	Pila *pila, *preFija;
	int longitudExpresion;
	char valor;

	pila->crearPila(pila);
	preFija->crearPila(preFija);

	longitudExpresion = strlen(expresion);

	for(int i=longitudExpresion-1; i>=0; i--)
	{
		if(((expresion[i]>=48)&&(expresion[i]<=57)) || ((expresion[i]>=65)&&(expresion[i]<=90))
		||((expresion[i]>=97)&&(expresion[i]<=122)))
		{
			preFija->insertarPush(expresion[i], preFija);
		}
		else
		{
			if(expresion [i]==')')
			{
				pila->insertarPush(expresion[i], pila);
			}
			else
			{
				if(esOperador(expresion[i]))
				{
					if(pila==NULL)
					{
						pila->insertarPush(expresion[i], pila);
					}
					else
					{
						while(pila!=NULL)
						{
							if(prioridad(pila->GetSimbolo()) > prioridad(expresion[i]))
							{
								pila->extraerPop(&valor,pila);
								preFija->insertarPush(valor,preFija);
							}
							else
							{
								break;
							}
						}
						pila->insertarPush(expresion[i], pila);
					}
				}
			}
		}
		if(expresion[i]=='(')
		{
			while((pila->GetSimbolo()!=')')&&(pila!=NULL))
			{
				pila->extraerPop(&valor,pila);
				preFija->insertarPush(valor,preFija);
			}
			pila->extraerPop(&valor,pila);
		}
	}
	while(pila!=NULL)
	{
		pila->extraerPop(&valor,pila);
		preFija->insertarPush(valor, preFija);
	}
	return preFija;
}

/*
void GenerarAudio(char expresion[])
{
	FILE *archivo = fopen("Audio.vbs", "w");
	
	char texto[] = "CreateObject(\"SAPI.SpVoice\").Speak\" ";
	char texto2[] = " \" ";
	char texto3[] = " ";
	
	char suma[]=" mas ";
	char resta[]=" menos ";
	char multi[]=" por ";
	char division[]=" dividido ";
	char potencia[]=" elevado al ";
	int posicion=0;
	
	for(int i=0; i<strlen(expresion); i++)
	{
		if(expresion[i]=='+' || expresion[i]=='-' || expresion[i]=='*'||expresion[i]=='/' || expresion[i]=='^')
		{
			if(expresion[i]=='+') strcat(texto3, suma);
			if(expresion[i]=='-') strcat(texto3, resta);
			if(expresion[i]=='*') strcat(texto3, multi);
			if(expresion[i]=='/') strcat(texto3, division);
			if(expresion[i]=='^') strcat(texto3, potencia);
		}
		else
		{
			posicion = strlen(texto3);
			if(i==0) texto3[0]=expresion[i];
			else texto3[posicion]=expresion[i];
		}
	}
	//cout<< texto<<endl;

	strcat(texto, texto3);
	strcat(texto, texto2);
	cout<<texto<<endl;
	
	if(archivo != NULL)
	{
		fprintf(archivo, "%s", texto);

		fclose(archivo);
	}
	else
	{
		printf("\n\n\tNO PUDO GENERAR EL ARCHIVO 'Audio.vbs'\n'");
	}
	
	//system("Audio.vbs");
	
}
*/

