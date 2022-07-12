#ifndef INTQUEUE_H
#define INTQUEUE_H

class IntQueue {
	private:
		int *queueArray;
		int queueSize;
		int front;
		int rear;
		int numItems;
	public:
		IntQueue(int);
		~IntQueue();
		void enqueue(int);
		void dequeue(int &);
		bool isEmpty();
		bool isFull();
		void clear();
};

#endif
