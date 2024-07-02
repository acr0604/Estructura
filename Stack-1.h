#pragma once
#include "Node.h"
#ifndef Stack_H
#define Stack_H

template<class T>
class Stack
{
public:
	Stack();
	void push(T data);
	bool isEmpty();
	T pop();
	void clear();
	void show();
	Node<T>* getTop() { return top; };
	int getSize() { return size; };

private:
	Node<T>* top;
	int size;
};

template<class T>
Stack<T>::Stack()
{
	top = NULL;
	size = 0;
}

template<class T>
void Stack<T>::push(T data)
{
	top = new Node<T>(data, top);
	size++;
}

template<class T>
bool Stack<T>::isEmpty()
{
	return (top == NULL);

	/* Otra forma de hacerlo
	if(top == NULL)
	{
		return true;
	}
	return false;*/
}

template<class T>
T Stack<T>::pop()
{
	if (!isEmpty())
	{
		T data = top->getData(); //obtenga los datos del nodo a donde esta apuntando top
		Node<T>* aux = top;// se utiliza aux para borrar el node
		top = top->getNext();//actualizamos top
		delete aux;//borramos el nodo que antes era el top
		size--;
		return data;
	}
	return NULL;
}

template<class T>
void Stack<T>::clear()
{
	while(top!= NULL)
	{
		Node<T>* aux = top;
		top = top->getNext();
		delete aux;
	}
	size = 0;
}

template<class T>
void Stack<T>::show()
{

	if (!isEmpty())
	{
		Node<T>* aux = top;
		while (top != NULL)
		{
			cout << "Dato-> " << top->getData() << endl;
			top = top->getNext();
		}

	}
	else
	{
		cout << "La pila esta vacia " << endl;
	}
}

#endif // !Stack_H

