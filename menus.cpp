#include "menus.h"

void mostrarMenuPrincipal()
{
	system("cls");
	cout << "**************************************************" << endl;
	cout << "*  1 - A la vez                                  *" << endl;
	cout << "*  2 - A destiempo                               *" << endl;
	cout << "*  0 - Salir                                     *" << endl;
	cout << "**************************************************" << endl;
}

int pedirOpcion(int minimo, int maximo)
{
	int opcion = 100;

	do{
		cin >> opcion;
	}while((opcion < minimo) || (opcion > maximo));

	return opcion;
}