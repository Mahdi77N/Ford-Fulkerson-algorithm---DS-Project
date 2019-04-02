#include "queue.h"

using namespace std;

void Queue::push(int value) 
{ 
	if((front == 0 && rear == size-1) || (rear == (front - 1) % (size - 1))) {
		printf("Queue is Full"); 
		return; 
	}

	else if(front == -1) {
		front = rear = 0; 
		arr[rear] = value; 
	} 

	else if(rear == size-1 && front != 0) {
		rear = 0; 
		arr[rear] = value; 
	} else {
		rear++; 
		arr[rear] = value; 
	} 
}

int Queue::pop() 
{ 
	if(front == -1) {
		printf("\nQueue is Empty"); 
		return INT8_MIN; 
	} 

	int data = arr[front]; 
	arr[front] = -1; 
	if(front == rear) { 
		front = -1; 
		rear = -1; 
	} 
	else if(front == size-1) 
		front = 0; 
	else
		front++; 

	return data; 
} 

int Queue::Front()
{
	if(front == -1)
		return 0;
	return arr[front];
}

bool Queue::empty()
{
	if(front == -1)
		return true;
	return false;
}