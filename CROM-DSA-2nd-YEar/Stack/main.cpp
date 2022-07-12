#include <bits/stdc++.h>
#include "IntStack.h"

using namespace std;

IntStack::IntStack(int size) {
	stackArray = new int[size];
	stackSize = size;
	top = -1;
}

void IntStack::push(int num) {
	if (isFull()) {
		cout << "The stack is full.\n";
	} else {
		top++;
		stackArray[top] = num;
	}
}

void IntStack::pop(int &num) {
	if (isEmpty()) {
		cout << "The stack is empty.\n";
	} else {
		num = stackArray[top];
		top--;
	}
}

bool IntStack::isFull() {
	bool status;
	if (top == stackSize - 1) {
		status = true;
	} else {
		status = false;
	}
	return status;
}

bool IntStack::isEmpty() {
	bool status;
	if (top == -1) {
		status = true;
	} else {
		status = false;
	}
	return status;
}

int main() {
	IntStack stack(5);
	int catchVar;
	
	cout << "Pushing 5\n";
	stack.push(5);
	cout << "Pushing 10\n";
	stack.push(10);
	cout << "Pushing 15\n";
	stack.push(15);
	cout << "Pushing 20\n";
	stack.push(20);
	cout << "Pushing 25\n";
	stack.push(25);
	
	cout << "Popping...\n";
	// top = 4
	stack.pop(catchVar);
	cout << catchVar << endl;
	// top = 3
	stack.pop(catchVar);
	cout << catchVar << endl;
	// top = 2
	stack.pop(catchVar);
	cout << catchVar << endl;
	// top = 1
	stack.pop(catchVar);
	cout << catchVar << endl;
	// top = 0
	stack.pop(catchVar);
	cout << catchVar << endl;
	return 0;
}
