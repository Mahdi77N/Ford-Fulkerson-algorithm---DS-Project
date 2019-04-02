#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std; 

struct Queue 
{ 
	int rear, front; 

	int size; 
	int *arr; 

	Queue(int s)
	{ 
		front = rear = -1; 
		size = s; 
		arr = new int[s]; 
	} 

	void push(int value); 
	int pop();
	int Front();
	bool empty();
}; 

#endif