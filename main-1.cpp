#pragma once
#include <iostream>

using namespace std;

#include "Stack.h"

int main()
{
	Stack<int> pila;

	pila.push(1); 
	pila.push(2); 
	pila.push(3); 
	pila.show();
	cout << "Dato que saque de la pila: " << pila.pop() << endl;
	cout << "Dato que saque de la pila: " << pila.pop() << endl;
	cout << "Dato que saque de la pila: " << pila.pop() << endl;
	pila.show();
	return 0;
}