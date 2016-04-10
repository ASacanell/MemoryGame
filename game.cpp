#include <iostream>
#include <time.h>
#include <windows.h>
#include "menus.h"

using namespace std;

		//DECLARACIONES

const int MAXIMO = 2;
typedef struct
{
	int lista[10];
	int contador;
} listaNumeros;


		//PROTOTIPOS

void solicitarNumeros(int &numeros, int &tiempo);
void generarNumeros(int numeros, listaNumeros &cadena);
void mostrarNumerosAlternativos(int tiempo, listaNumeros cadena);
void mostrarNumeros(int tiempo, listaNumeros cadena);
void introducirNumerosAlternativos(listaNumeros cadena, int &puntuacion, bool &acierto);
void introducirNumeros(listaNumeros cadena, int &puntuacion, bool &acierto);
int searchNumber(listaNumeros cadena, int buscado);
int gotoxy(SHORT x, SHORT y);
void eliminarNumero(listaNumeros &cadena, int pos);
void mostrarCadena(listaNumeros cadena);
void pausarPrograma();
void sameTime();
void alternatively();



		//MAIN

int main()
{
	bool acabado = false;

	do{
		mostrarMenuPrincipal();
		switch(pedirOpcion(0,2)){
		case 0: {
			acabado = true;
			break;}

		case 1:{
			sameTime();
			break;}

		case 2:{
			alternatively();
			break;}
		}
	
	}while(!acabado);
	return 0;
}

		//IMPLEMENTACIONES

void solicitarNumeros(int &numeros, int &tiempo)
{
	cout << "Introduce la cantidad de numeros a adivinar: " << endl;
	cin >> numeros;
	cout << "Introduce la cantidad de segundos: " << endl;
	cin >> tiempo;
	tiempo = tiempo * 1000;
}

void generarNumeros(int numeros, listaNumeros &cadena)
{
	srand(time(NULL)); 
	cadena.contador = 0;
	int auxiliar;
	
	for(int i=0;i<numeros;i++)
	{
		auxiliar = rand()%101;;
		cadena.lista[i] = auxiliar;
		cadena.contador++;
	}
}

void mostrarNumeros(int tiempo, listaNumeros cadena)
{
	srand(time(NULL));
	int auxiliarx;
	int auxiliary;
	
	for(int i=0;i<cadena.contador;i++)
	{
		auxiliarx=rand()%81;
		auxiliary=rand()%25;
		
		gotoxy(auxiliarx,auxiliary); cout << cadena.lista[i];
	}
	Sleep(tiempo);
}

int gotoxy(SHORT x, SHORT y)
{
   COORD coord;
   HANDLE h_stdout;
   
   coord.X = x;
   coord.Y = y;
   
   if ((h_stdout = GetStdHandle(STD_OUTPUT_HANDLE)) == INVALID_HANDLE_VALUE)
      return 0;
   
   if (SetConsoleCursorPosition(h_stdout, coord) == 0)
      return 0;

   return 1;
}

void introducirNumeros(listaNumeros cadena, int &puntuacion, bool &acierto)
{
	int posicion;
	int opciones = cadena.contador;
	int auxiliar = 0;
	for(int i=0;i<opciones;i++)
	{
		cout << "Introduce un numero: ";
		cin >> auxiliar;
		posicion = searchNumber(cadena, auxiliar);
		if(posicion != -1)
		{
			cout << "Numero correcto" << endl;
			acierto = true;
			eliminarNumero(cadena, posicion);
		}else
			cout << "Numero incorrecto" << endl;
	}
	pausarPrograma();
	if(cadena.contador == 0)
		puntuacion++;
}

int searchNumber(listaNumeros cadena, int buscado)
{
	bool encontrado = false;
	int posicion = -1;
	int i= 0;
	while(!encontrado && i < cadena.contador)
	{
		if(cadena.lista[i] == buscado)
		{
			encontrado = true;
			posicion = i;
		}
		i++;
	}
	return posicion;
}

void eliminarNumero(listaNumeros &cadena, int pos)
{
	for(int i=pos;i<cadena.contador;i++)
	{
		cadena.lista[i]=cadena.lista[i+1];
	}
	cadena.contador--;
}

void mostrarCadena(listaNumeros cadena)
{
	for(int i = 0;i< cadena.contador;i++)
		cout << cadena.lista[i] << endl;
}

void pausarPrograma()
{
	cin.sync();
	cin.get();
	cin.sync();
}

void sameTime()
{
	int puntuacion = 0;
	bool acierto;
	int numeros;
	int tiempo;
	int pantallas = 0;
	listaNumeros cadena;
	
	do{
	acierto = false;
	system("cls");
	solicitarNumeros(numeros, tiempo);
	generarNumeros(numeros, cadena);
	
	system("cls");
	mostrarNumeros(tiempo, cadena);
	system("cls");
	introducirNumeros(cadena, puntuacion, acierto);
	pantallas++;
	}while(acierto && pantallas<MAXIMO);
	if(!acierto)
		cout << "Oh oh, no has acertado ningun numero de esta pantalla"<< endl;
	cout << "La puntuacion final ha sido de: " << puntuacion << " sobre " << MAXIMO;
	pausarPrograma();
}

void alternatively()
{
	int puntuacion = 0;
	bool acierto;
	int numeros;
	int tiempo;
	int pantallas = 0;
	listaNumeros cadena;
	
	do{
	acierto = false;
	system("cls");
	solicitarNumeros(numeros, tiempo);
	generarNumeros(numeros, cadena);	
	system("cls");
	mostrarNumerosAlternativos(tiempo, cadena);
	system("cls");
	introducirNumerosAlternativos(cadena, puntuacion, acierto);
	pantallas++;
	}while(acierto && pantallas<MAXIMO);
	if(!acierto)
		cout << "Oh oh, no has acertado ningun numero de esta pantalla"<< endl;
	cout << "La puntuacion final ha sido de: " << puntuacion << " sobre " << MAXIMO;
	pausarPrograma();
}

void mostrarNumerosAlternativos(int tiempo, listaNumeros cadena)
{
	srand(time(NULL));
	int auxiliarx;
	int auxiliary;
	
	for(int i=0;i<cadena.contador;i++)
	{
		auxiliarx=rand()%81;
		auxiliary=rand()%25;
		
		gotoxy(auxiliarx,auxiliary); cout << cadena.lista[i];
		Sleep(tiempo);
		system("cls");
	}
	
}

void introducirNumerosAlternativos(listaNumeros cadena, int &puntuacion, bool &acierto)
{
	int opciones = cadena.contador;
	int auxiliar = 0;
	bool fallo = false;
	for(int i=0;i<opciones;i++)
	{
		cout << "Introduce un numero: ";
		cin >> auxiliar;
		if(auxiliar == cadena.lista[i]){
			cout << "Numero correcto" << endl;
			acierto = true;
		}else{
			cout << "Numero incorrecto" << endl;
			fallo = true;
		}
			
	}
	pausarPrograma();
	if(!fallo)
		puntuacion++;
}