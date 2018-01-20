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
#include  <pthread.h>
#include <fstream>
#include <cstring>
#include<time.h> 
//#include "imagen.h"


using namespace std;


//PROTOTIPOS DE FUNCIONES
int expresionBalanceada (char []);
int esOperador(char );
int prioridad (char );
Pila *infijaPostfija(char []);
Pila *infijaPrefija(char []);
void GenerarAudio(char []);
void GenerarQR(char expresion[]);
void GenerarPDF(char [], char []);
char limitacionIngreso(char []);
bool validacionExpresion(char []);
float operacion(float , float , char );
float evaluarPostFija(char []);
char soloLetras(char []);


void* AlgunaFuncion(void* ) ;
void recuperar(string name1);
string generar_1();
struct tm *localtime(const time_t *tiempoPtr);
void recuperar(string name1);
string generar_1();
void GenerarBACKUP(char [], char []);
//void imagen();


//////////////////////////////////////////////////
//Programa Principal
main()
{
	pthread_t thread1, thread2; 
	pthread_create(&thread1, NULL, AlgunaFuncion, NULL); 
	
	
	char expresion[50], expresion2[50];
	Pila *postFija, *preFija;
	int opcion;

	//system("F:\\agente\\agente\\WinAppManejoMSAgente.exe");
	home:
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
	string menu[] = { "1.-Notacion POSTfija","2.-Notacion PREfija","3.-BackUp","4.-Ayuda","5.-Generar PDF","6.-Salir" };
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
						limitacionIngreso(expresion);
						if(expresionBalanceada(expresion))
						{
							postFija = infijaPostfija(expresion);
							cout<<"\nPOSTFIJA:"<<endl;
							postFija->imprimirExpresion(postFija);
							cout<<endl<<endl;
							postFija->obtenerExpresion(postFija, expresion2);
							cout<<"\nRESULTADO:\t"<<evaluarPostFija(expresion2)<<endl;
							GenerarQR(expresion);
							GenerarPDF(expresion, expresion2);
							system("start GENERADORQR.jar");
							system("start GENERADORPDF.jar");
							GenerarAudio(expresion);
						}
						else
						{
							cout<<"\nExpresion no valida!!";
						}
								
						system("pause");
						goto home;
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
						goto home;
					}
				}
				
				///////////////////////////////////////////////////////////////// BACKUP
				for (int i = 0; i<12; i++) 
				{
					if (coord.X == i&&coord.Y == 11) 
					{
						ind = true;
						system("Color f9");
						system("cls");
									
						int op=0;
						string a;
						do{
							do{
								printf("\n1.-RESPALDAR\n");
								printf("2.-RECUPERAR");
								printf("\n0.-SALIR");
								printf("\nIngrese una opcion: ");
								scanf("%d",&op);	
								}while(op<0||op>2);
								
								switch (op)
								{
									case 1: {
										GenerarBACKUP(expresion, expresion2);
										a = generar_1();
										break;
									}
									case 2: {
										ifstream f;
										string fich=a;
										FILE* fichero;
										f.open(fich.c_str() ,ios::in);
										recuperar(fich);
										break;
									} 
								}
						}while (op != 0);
						
		
						system("pause");

						goto home;
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
						ShellExecute(NULL, TEXT("open"), TEXT("C:\\PDF\\ayuda.chw"), NULL, NULL, SW_SHOWNORMAL);
						goto home;
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
						goto home;
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
						//imagen();
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

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
//DESARROLLO DE FUNCIONES

char limitacionIngreso(char A[])
{
	char letra;
	int i=0,l=0;
	fflush(stdin);
	letra=getch();
	while(letra!=13 && i<50)
	{
		fflush(stdin);
		if(letra!=8)
		{
			if(letra==123||letra==125||letra==93 ||letra==91 ||letra==94 || letra==42 || letra==43 || letra==47 || letra==45||letra==97 || letra==99 || letra==110 || letra==111|| letra==101|| letra==115|| letra==116 || letra==40 || letra==41|| letra==46|| letra==13 || ((letra>=48)&&(letra<=57)) )
			{
				if(letra!=13)
				{
					printf("%c",letra);
					fflush(stdin);
					A[i]=letra;
					i++;
				}
			}
		}
		else
		{
			l=strlen(A);
			if(l>0)
			{
				printf("\b \b");//mueve el cursor a la izquierda
				A[l-1]='\0';
				i--;
			}
		}
		letra=getch();
	}
	A[i]='\0';
	
}


float operacion(float operando1, float operando2, char operador)
{
	switch(operador)
	{
		case '+':
			return operando1 + operando2;
		break;

		case '-':
			return operando1 - operando2;
		break;

		case '*':
			return operando1 * operando2;
		break;

		case '/':
			return operando1 / operando2;
		break;

		case '^':
			return pow(operando1, operando2);
		break;

	}
}



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


float evaluarPostFija(char expresion[])
{
	PilaFloat *pila;
	int longitud, i, j;
	char valor;
	float operando1, operando2, resultado;



	longitud = strlen(expresion);
	int angulo=0;

	for(i=0;i<longitud;i++)
	{
	    if(expresion[i]!=' ')
        {
        	
			
            if( ((expresion[i]>=48)&&(expresion[i]<=57)) ||  expresion[i]==115 || expresion[i]==99 || expresion[i]==116)
            {
            	

				valor = expresion[i];
                pila->insertarPushFloat(atof(&valor),pila);
            }
            else
            {
                if(esOperador(expresion[i]))
                {
                    pila->extraerPopFloat(&operando2,pila);
                    pila->extraerPopFloat(&operando1, pila);
                    resultado = operacion(operando1, operando2, expresion[i]);
                    pila->insertarPushFloat(resultado, pila);
                }
            }
        }

	}

	return pila->GetValor();
	//return 1;
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

void GenerarQR(char expresion[])
{
	FILE *archivo = fopen("C:\\QR\\QR.txt", "w");

	//cout<< texto<<endl;

	
	if(archivo != NULL)
	{
		fprintf(archivo, "%s", expresion);

		fclose(archivo);
	}
	else
	{
		printf("\n\n\tNO PUDO GENERAR EL ARCHIVO 'QR.txt'\n'");
	}
	
}

void GenerarBACKUP(char expresion[], char expresion2[])
{
	FILE *archivo = fopen("C:\\Backup\\PRINCIPAL\\C00.txt", "a");

	//cout<< texto<<endl;

	
	if(archivo != NULL)
	{
		fprintf(archivo, "\nExpresión: %s\nNotacion: %s\n", expresion, expresion2);

		fclose(archivo);
	}
	else
	{
		printf("\n\n\tNO PUDO GENERAR EL ARCHIVO 'PDF.txt'\n'");
	}
	
	
}


void GenerarPDF(char expresion[], char expresion2[])
{
	FILE *archivo = fopen("C:\\PDF\\PDF.txt", "a");

	//cout<< texto<<endl;

	
	if(archivo != NULL)
	{
		fprintf(archivo, "\nExpresión: %s\nNotacion: %s\n", expresion, expresion2);

		fclose(archivo);
	}
	else
	{
		printf("\n\n\tNO PUDO GENERAR EL ARCHIVO 'PDF.txt'\n'");
	}
	
	
}




void GenerarAudio(char expresion[])
{
	FILE *archivo = fopen("Audio.vbs", "w");
	
	char texto[] = "CreateObject(\"SAPI.SpVoice\").Speak\" ";
	char texto2[] = " \" ";
	char texto3[] = " ";
	
	strcat(texto, expresion);
	strcat(texto, texto2);
	//cout<<texto<<endl;
	
	if(archivo != NULL)
	{
		fprintf(archivo, "%s", texto);

		fclose(archivo);
	}
	else
	{
		printf("\n\n\tNO PUDO GENERAR EL ARCHIVO 'Audio.vbs'\n'");
	}
	
	system("Audio.vbs");
	
}

void* AlgunaFuncion(void* ) 
{ 
	system("F:\\agente\\agente\\WinAppManejoMSAgente.exe");
	return NULL; 
} 

void recuperar(string name1) 
{
	time_t fsistema=time(0);
	struct tm *tlocal= localtime(&fsistema);
	int data1=0;
	char cad[100];
	char y[100]; 
	std::strcpy(y, name1.c_str());
	puts(y);
	strftime(cad, 100, "C:/Backup/RECUPERAR/hora(%HH-%MM-%SS)fecha(%dD-%mM-%YA)", tlocal);
	FILE* fichero;//Puntero de tipo archivo
	FILE *archivo;
	string name2 = cad;
	name2 = y;
	archivo=fopen("C:/Backup/PRINCIPAL/C00.txt","r");
	fichero = fopen(name2.c_str(), "w+");
	 while ( (data1 = fgetc (archivo)) != EOF ) {
            fputc ( data1, fichero);
        }
        fclose(archivo);
        fclose (fichero);
	printf("Recuperado...");
	getch();
}
string generar_1()
{
	time_t fsistema=time(0);
	struct tm *tlocal= localtime(&fsistema);
	
	char cad[100];
	int data1=0;
	strftime(cad, 100, "C:/Backup/RESPALDO/hora(%HH-%MM-%SS)fecha(%d-%m-%Y)", tlocal);
	FILE* fichero;//Puntero de tipo archivo
	FILE *archivo;
	string name1 = cad;
	name1 = name1 + ".txt";
	cout << name1;
	archivo=fopen("C:/Backup/PRINCIPAL/C00.txt","r");
	fichero = fopen(name1.c_str(), "w+");//fopen con w+ crea un archivo y lo edita se crea en la raiz del programa
	 while ( (data1 = fgetc (archivo)) != EOF ) {
            fputc ( data1, fichero);
        }
        
        fclose (archivo);
        fclose (fichero);
	printf("\nProceso completado\n");
	getch();
	return name1;
}
/*
void imagen()
{

    hConWnd = GetConsoleWndHandle();
    if (hConWnd)
    {
        // select a bitmap file you have or use one of the files in the Windows folder
        // filename, handle, ID, ulcX, ulcY, width, height   0,0 auto-adjusts
        BCX_Bitmap("LOGO.bmp",hConWnd,123,230,65,0,0);
        //system("pause>nul");
        Sleep(3000);
        //getchar();
    }
    system("cls");

}
*/
