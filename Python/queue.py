import main

#	Global q array variable
queueArray = []
size = 0 #  Max Size of array/queue
items = 0 # Actual Elements/Items within the array/queue
front = -1 # Index tracking for first & last in the queue
rear = -1 

def show_queue_menu():
	choices = ["Create queue", "Display", "Check if full", "Check if empty", "Enqueue/insert", "Dequeue/remove", "Get front/first element", "Get rear/back element", "Go back"]
	main.generate_menu_header("Queue", choices)
	
	while True:
		num = main.prompt("Enter choice: ")
		
		# start of queue menu:
		if num == 1:
			create_queue()
		elif num == 2:
			display()
		elif num == 3:
			print(isFull()) # TODO: Rework | False = FULL || True = NOT full
		elif num == 4:
			print(isEmpty()) # TODO: Rework | False = NOT empty || True = EMPTY
		elif num == 5:
			enqueue() # TODO: Prompt if success or empty
		elif num == 6:
			dequeue() # TODO: Prompt if success or empty
		elif num == 7:
			first_queue()
		elif num == 8:
			last_queue()
		elif num == 9:
			main.show_data_structures_menu()
		else:
			print("Invalid. Please try again.")


def create_queue():
	main.clear_screen()

	# Connect to global vars
	global queueArray, size, items, front, rear

	size = main.prompt("Enter the size of the queue: ") # Pseudo asks for 'size'

	# Basic range loop for appending elements into
	# the empty list
	for x in range(size):
		# [Optional]
		# Check before appending if queue is already 'full'
		#	if 

		queueArray.append(main.prompt("Enter the " + str(x+1) + " element to enqueue: ")) # TODO: Optimize printout
		# Count number of items queued
		items += 1

def display():
	#NOTE: Basic display output
	print(queueArray)

def isFull():
	status = False if items < size else True
	return status

def isEmpty():
	status = False if items else True
	return status

def enqueue():
	# Connect to global vars
	global queueArray, items, rear

	if isFull():
		print("The queue is full")
	else:
		val = main.prompt("Enter an element to enqueue: ")
		rear = (rear + 1) % size
		queueArray[rear] = val
		items += 1

def dequeue():
	# Connect to global vars
	global items, front

	if isEmpty():
		print("The queue is empty")
	else:
		# Pseudo pop first in the queue
		front = (front + 1) % size
		items -= 1

# NOTE: Doesn't actually utilize the front/rear
# index trackers for first and last queue methods!

def first_queue():
	if isEmpty():
		print("The queue is empty")
	else:
		print(queueArray[0],"is first in the queue")
def last_queue():
	if isEmpty():
		print("The queue is empty")
	else:
		print(queueArray[size-1],"is the last one in the queue")




