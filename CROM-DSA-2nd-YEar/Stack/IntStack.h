#ifndef INTSTACK_H
#define INTSTACK_H

class IntStack {
	private:
		int *stackArray;
		int stackSize;
		int top;
	public:
		IntStack(int size);
		void push(int num);
		void pop(int &num);
		bool isFull();
		bool isEmpty();
};

#endif
