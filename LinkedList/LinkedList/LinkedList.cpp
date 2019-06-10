// linkedList2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


// linkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
const int stackSize = 20; // Set constant integer for comparison
using namespace std;

// This is a struct, which enables us to create an instance of a struct
// as many times as we want. This struct decalres a node, which has an integer that handles data
// and the line "node * next" is the node declaring a pointer.
struct node
{
	int data;
	node * next;
} *top = NULL, *first;

// Function stubs
node* newNode(int num);
void push(node * start);
void pop();
bool isEmpty();
bool isFull();
void showStack();

// Main function. This function contains the scaffold which sets up the 
// functionality of the program. It initialises an integer to act as a counter, then
// shows the top value of the stack.
// It then uses a for loop to push values into the stack, upto the maximum space
// of the stack, then shows the new result of the top of the stack.
// Then it goes on to pop the elements of the array back out, and shows us the new value
// of the top, which should be 0 as the stack is now empty.
int main()
{
	int i;

	node * point;

	cout << "Testing Stack\n\n";

	showStack();

	cout << "\nTest Push\n\n";
	for (i = 0; i < stackSize; i++)
	{
		point = newNode(i);
		push(point);
	}

	showStack();

	cout << "\nTest Pop\n\n";
	for (i = 0; i < stackSize; i++)
	{
		pop();
	}

	showStack();

	cin.ignore();
	cin.get();
	return 0;
}


// This creates and returns a new node called "first"
node * newNode(int num)
{
	first = new node;
	first->data = num;
	first->next = NULL;
	return(first);
}

// This function sets a pointer to the stack, and then increments the top
// element of the stack by one. It takes data from a for loop and pushes it onto
// the stack
void push(node * start)
{
	if (top == NULL)
	{
		top = start;
	}
	else
	{
		cout << top->data << " has been added" << endl;
		start->next = top;
		top = start;
	}
}

// This function sets a pointer to the stack, then decrements the top element
// of the stack. 
void pop()
{

	cout << top->data << " data has been deleted " << endl;
	first = top;
	top = top->next;
	delete(first);
}


// This function checks if the stack is empty, if its empty, it returns
// the boolean value true. If the stack has onr or more elements it returns false
bool isEmpty()
{
	if (first->data == -1)
		return true;
	else
		return false;
}

// This function checks if the stack is full, if its full, it returns
// the boolean value false. If the stack has one or more elements it returns true
bool isFull()
{
	if (first->data == stackSize)
		return false;
	else
		return true;
}

// This function prints out the values held in the stack. It uses a while loop to print 
// the data whilst the pointer is not equal to null
void showStack()
{
	node * newest;
	newest = top;

	if (top == NULL)
	{
		cout << "Stack is empty" << endl;
	}
	else
	{
		while (newest != NULL)
		{
			cout << newest->data << " ";
			newest = newest->next;
		}
		cout << endl;
	}

}









