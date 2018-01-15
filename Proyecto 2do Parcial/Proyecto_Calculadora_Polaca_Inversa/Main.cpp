#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
using namespace std;

int main() {
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
	string menu[] = { "1.-Notacion Prefija","2.-Notacion Postfija","3.-Codigo QR","4.-Ayuda","5.-Generar PDF","6.-Salir" };
	for (int i = 0; i<6; i++) {
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
	while (1) {
		ReadConsoleInput(hinput, &Input, 1, &Events);
		if (Input.EventType == MOUSE_EVENT) {
			if (Input.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
				coord.X = Input.Event.MouseEvent.dwMousePosition.X;
				coord.Y = Input.Event.MouseEvent.dwMousePosition.Y;
				for (int i = 0; i<19; i++) {
					if (coord.X == i&&coord.Y == 9) {
						ind = true;
						system("Color f9");
						system("cls");
						cout << "AQUI VA LA OPCION 1" << endl;
						system("pause");
						main();
					}
				}
				for (int i = 0; i<20; i++ ) {
					if (coord.X == i&&coord.Y == 10) {
						ind = true;
						system("Color f9");
						system("cls");
						cout << "AQUI VA LA OPCION 2" << endl;
						system("pause");
						main();
					}
				}
				for (int i = 0; i<12; i++) {
					if (coord.X == i&&coord.Y == 11) {
						ind = true;
						system("Color f9");
						system("cls");
						cout << "AQUI VA LA OPCION 3" << endl;
						system("pause");
						
						main();
					}
				}
				for (int i = 0; i<8; i++) {
					if (coord.X == i&&coord.Y == 12) {
						ind = true;
						system("Color f9");
						system("cls");
						ShellExecute(NULL, TEXT("open"), TEXT("G:\\ESPE 4 SEMESTRE\\ESTRUCTURAS\\Primer parcial\\Proyecto I\\Ayuda\\Ayuda Listas SimplesP.chm"), NULL, NULL, SW_SHOWNORMAL);
						main();
					}
				}
				for (int i = 0; i<14; i++) {
					if (coord.X == i&&coord.Y == 13) {
						ind = true;
						system("Color f9");
						system("cls");
						cout << endl << "Programa realizado por: Sandra Castro / Bryan Tualle" << endl;
						cout << "         <<<<<<CopyLeft P&C (licencia de codigo abierto)>>>>>>" << endl;
						system("pause");
						main();
					}
				}
				for (int i = 0; i<8; i++) {
					if (coord.X == i&&coord.Y == 14) {
						ind = true;
						system("Color f9");
						system("cls");
						cout << endl << "<<<<<<<<<Gracias por usar nuestro programa>>>>>>>>>" << endl;
						exit(1);
						main();
					}
				}
				if (!ind) {
					main();
				}
				ind = false;
			}
		}
	}
}