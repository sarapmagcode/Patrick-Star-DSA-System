#include <bits/stdc++.h>
#include "IntQueue.h"

using namespace std;

IntQueue::IntQueue(int s) {
	queueArray = new int[s];
	queueSize = s;
	front = -1;
	rear = -1;
	numItems = 0;
}

IntQueue::~IntQueue() {
	delete [] queueArray;
}

void IntQueue::enqueue(int num) {
	if (isFull()) {
		cout << "The queue is full.\n";
	} else {
		rear = (rear + 1) % queueSize;
		queueArray[rear] = num;
		numItems++;
	}
}

void IntQueue::dequeue(int &num) {
	if (isEmpty()) {
		cout << "The queue is empty.\n";
	} else {
		front = (front + 1) % queueSize;
		num = queueArray[front];
		numItems--;
	}
}

bool IntQueue::isEmpty() {
	bool status;
	if (numItems) {
		status = false;
	} else {
		status = true;
	}
	return status;
}

bool IntQueue::isFull() {
	bool status;
	if (numItems < queueSize) {
		status = false;
	} else {
		status = true;
	}
	return status;
}

void IntQueue::clear() {
	front = queueSize - 1;
	rear = queueSize - 1;
	numItems = 0;
}

int main() {
	IntQueue iQueue(5);
	cout << "Enqueuing 5 items...\n";
	for (int x = 0; x < 5; x++) {
		iQueue.enqueue(x);
	}
	cout << "Now attempting to enqueue again...\n";
	iQueue.enqueue(5);
	cout << "The values in the queue were:\n";
	while (!iQueue.isEmpty()) {
		int value;
		iQueue.dequeue(value);
		cout << value << " ";
	}
	return 0;
}
