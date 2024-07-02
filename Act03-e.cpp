#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <stdio.h> 
#include <stdlib.h>
using namespace std;

void mostrarArreglo(int arr[], int tamanio)
{
	for (int i = 0; i < tamanio; i++)
	{
		cout << arr[i] << " ";
	}
}
void crearArreglo(vector<int> &lista, int x)
{
	for(int i=0; i<x; i++)
	{
		lista.push_back(rand() % (100-1));
	}
}

void mostrarArreglo(vector<int> lista) 
{
	for (int i = 0; i < lista.size(); i++)
	{
		cout << lista[i] << " ";
	}
}


int BusquedaSequencial(vector<int> lista, int n)
{
	int pos;

	for (int i = 0; i < lista.size(); i++)
	{
		if(n ==lista[i])
		{
			pos = i;
			return pos + 1;
		}
	}
	return -1;
}

int BusquedaOrdenada(vector<int> &lista, int n)
{
	int num, inicio = 0, final = lista.size() - 1;
	int centro = (inicio + final) / 2;

	while(inicio<=final)
	{
		if(lista[centro] == n)
		{
			return centro;
		}
		else if (n > lista[centro])
		{
			inicio = centro + 1;
		}
		else
		{
			final = centro - 1;
		}
		centro = (inicio + final) / 2;
	}
}


/*void merge(int arr[], int LimiteIzq, int LimiteDer, int Centro)
{
	int tamanio1 = LimiteIzq -LimiteDer + 1; // tamanio arreglo 1 
	int tamanio2 = LimiteIzq - Centro;    // tamanio arreglo 2;

  //arreglos temporales
	int Izq[4], Der[3]; // tamanio1 = 4 y tamanio2 = 3

	for (int i = 0; i < 4; i++)//llenando arreglo L[4]
	{
		Izq[i] = arr[LimiteIzq + i];
		//L[4] = {38,27,41,3}
	}

	for (int j = 0; j < 3; j++)
	{
		Der[j] = arr[Centro + 1 + j];
		//R[3] = {9,82,10}
	}

	//R[0] = arr[4]; // 9
	//R[1] = arr[5]; // 82
	//R[2] = arr[6]; // 10

	int i = 0; // corredor de arreglo izq
	int j = 0; // corredor de arreglo dere
	int pos = LimiteIzq; //Corredor de arreglo combinado

  //Reagrupar datos
	while (i < tamanio1 && j < tamanio2)
	{
		if (Izq[i] <= Der[j])
		{
			arr[pos] = Izq[i];
			i++;
		}
		else
		{
			arr[pos] = Der[j];
			j++;
		}
		pos++;
	}
}*/

void quicksort(int Arr[], int izq, int der)
{
	int i = izq, j = der, centro, aux;
	centro = (izq + der) / 2;
	do {
		while ((Arr[i] < Arr[centro]) && (j <= der))
		{
			i++;
		}

		while ((Arr[centro] < Arr[j]) && (j > izq))
		{
			j--;
		}

		if (i <= j)
		{
			aux = Arr[i];
			Arr[i] = Arr[j];
			Arr[j] = aux;
			i++;
			j--;
		}
	} while (i <= j);

	if (izq < j)
	{
		quicksort(Arr, izq, j);
	}

	if (i < der)
	{
		quicksort(Arr, i, der);
	}
}

int main()
{
	int tamanio, numero;
	vector<int> linea;
	int arr[] = {5,18,21,100,5,2};
	cout << "Dame un tamanio: ";
	cin >> tamanio;
	cout << endl;
	crearArreglo(linea, tamanio);
	mostrarArreglo(linea);
	cout << endl;
	cout << "Buscar: ";
	cin >> numero;
	cout << endl;
	BusquedaOrdenada(linea,numero); 
	mostrarArreglo(linea);
	cout << endl;
	cout << "El numero " << numero << " esta en la posicion: " << BusquedaOrdenada(linea, numero) + 1 << endl;
	cout << "\n" << "\n";
	cout << "Sequencial: "; BusquedaSequencial(linea, numero);
	mostrarArreglo(linea);
	cout << endl;
	cout << endl;
	cout << "///////////////////////////////////////////////"<<endl;
	mostrarArreglo(arr, 6);
	cout << endl;
	quicksort(arr, 0, 5);
	cout << "Quicksort: ";
	mostrarArreglo(arr, 6);
}
