#pragma once
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;


template <class T>
void Arreglo(vector<T> &lista, int n)
{
	for(int i=0; i<n;i++)
	{
		//cout << rand() % 20 - 1<<endl;
		lista.push_back(rand() % (20 - 1));
	}
}


template <class T>
void mostrarArreglo(vector<T> lista)
{
	for (int i = 0; i < lista.size(); i++)
	{
		cout << lista[i] << " ";
	}
}




//Intercambio
template <class T>
void Intercambio(vector<T> &lista)
{
	T num;
	for (int i=0;i<lista.size()-1; i++)
	{ 
		for(int j=i+1;j<lista.size();j++)
		{
			if(lista[i]>lista[j])
			{
				num = lista[i];
				lista[i] = lista[j];
				lista[j] = num;
			}
		}
	}
}


//Burbuja
template <class T>
void Burbuja(vector<T>& lista)
{
	T cont;
	for(int i=0; i<lista.size()-1; i++)
	{
		for(int j = 0; j<lista.size()-1-i; j++)
		{
			if(lista[j+1]<lista[j])
			{
				cont = lista[j];
				lista[j] = lista[j+1];
				lista[j+1] = cont;
			}
		}
	}
}



//Seleccion
template <class T>
void Seleccion(vector<T> &lista)
{
	T num, menor, cont;
	for(int i=0; i<lista.size()-1; i++)
	{	
		menor = lista[i];
		cont = i;
		for (int j = i+1; j < lista.size(); j++)
		{
			if (menor > lista[j])
			{
				menor = lista[j];
				cont = j;
			}
		}
		lista[cont] = lista[i];
		lista[i] = menor;
	}
}

//Insercion
template <class T>
void Insercion(vector<T> &lista)
{
	T num, cont;
	for(int i=1; i<lista.size(); i++)
	{
		cont = i;
		num = lista[i];
		while(cont >0 && (num<lista[cont-1]))
		{
			lista[cont] = lista[cont - 1];
			cont --;
		}
		lista[cont] = num;
	}
}

int main()
{
	srand(time(NULL));
	vector<int> linea;

	Arreglo(linea, 4);
	vector<int> lineaO = linea;
	
	Intercambio(linea);
	mostrarArreglo(linea);
	cout << endl;
	linea = lineaO;

	Burbuja(linea);
	mostrarArreglo(linea);
	cout << endl;
	linea = lineaO;

	Seleccion(linea);
	mostrarArreglo(linea);
	cout << endl;
	linea = lineaO;

	Insercion(linea);
	mostrarArreglo(linea);

}

