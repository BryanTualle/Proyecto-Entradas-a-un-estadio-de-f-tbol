/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Calculadora Polaca Inversa en Notacion Prefija y Postfija

Autores: 				Sandra Castro y Bryan Tualle
Fecha de Creación:		2/1/2018
Fecha de modificacion:
Docente: 				Ing. Edgar Fernando Solis Acosta
Carrera: 				Ing. Sistemas e Informática
*/

#include <iostream>
#include <conio.h>
#include <string>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;


int main()
{
	locale::global(locale("spanish"));
	system("Color F0");
	system("cls");
	string menu[] = { "1.-Notacion Prefija","2.-Notacion Postfija","3.-Ayuda","4.-Salir","SALIR" };
	int cursor = 0, d;
	char tecla;
	for (;;) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
		cout << "\t\t\t\t\tUNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE" << endl;
		cout << "\t\t\t\t\t\tESTRUCTURA DE DATOS 2479" << endl;
		cout << "\t\t\t\tCalculadora Polaca Inversa en Notacion Prefija y Postfija" << endl;
		cout << "\n\t\t\t\tAutores:\t Sandra Castro  y  Bryan Tualle" << endl;
		cout << "\t\t\t\tFecha:\t\t 2/1/2018" << endl;
		cout << "\t\t\t\tProfesor:\t Ing. Edgar Fernando Solis Acosta" << endl;
		cout << "\t\t\t\tCarrera:\t Ing. Sistemas e informatica" << endl << endl;
		for (int i = 0; i < 4; i++) {
			if (cursor == i) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 245);
				cout << menu[i] << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
				cout << menu[i] << endl;
			}
		}
		for (;;) {
			tecla = _getch();
			if (tecla == 80) {
				cursor++;
				if (cursor == 4)
				{
					cursor = 0;
				}
				break;
			}
			if (tecla == 72) {
				cursor--;
				if (cursor == -1)
				{
					cursor = 3;
				}
				break;
			}
			if (tecla == 13) {
				switch (cursor) {
				case 0:
					system("cls");
					main();
					break;
				case 1:
					system("cls");
					main();
					break;
				case 2:
					system("cls");
					main();
					break;
				case 3:
					exit(1);
					break;
				}
				break;
			}
		}
	}
	return 0;
}

