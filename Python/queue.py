import main

class queue:
	array = []
	size = 0 #  Max Size of array/queue
	items = -1 # Actual Elements/Items within the array/queue
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
			display_boolean_handler(isFull(), 0)
		elif num == 4:
			display_boolean_handler(isEmpty(), 1) 
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
	'''
		Basic range loop for appending elements into
		the empty list
	'''
	if isFull():
		print("The queue is already FULL!")
		main.pause_screen()
	else:
		queue.size = main.prompt("Enter the size of the queue: ") # Pseudo asks for 'size'

		for x in range(queue.size):
			queue.array.append(main.prompt("Enter the " + str(x+1) + " element to enqueue: ")) 
			# Count number of items queued
			queue.items += 1
		queue.items += 1 # Add additional 1 to be on par with size var

		print("\nQueue has been created!")
		main.pause_screen()

''' 
	Converts isFull/isEmpty Boolean returns into
 	User readable text

	first param for boolen, second is for determining 
	if full or empty func is called

	0 for isFull
	1 for isEmpty
'''
def display_boolean_handler(bool, num):
	if num == 0:
		printout = "The queue is already FULL!" if bool else "The queue is not full yet"
	else:
		printout = "The queue is EMPTY!" if bool else "The queue is not empty"

	print(printout)
	main.pause_screen()

def display():
	#NOTE: Basic display output
	print(queue.array)

def isFull():
	status = False if queue.items < queue.size else True
	return status

def isEmpty():
	status = False if queue.items else True
	return status

def enqueue():
	if isFull():
		print("The queue is full")
	else:
		val = main.prompt("Enter an element to enqueue: ")
		queue.rear = (queue.rear + 1) % queue.size # Calculate index to push
		queue.array[queue.rear] = val
		queue.items += 1

		#Display status
		print("Element successfully enqueued!")
		main.pause_screen()

def dequeue():
	if isEmpty():
		print("The queue is empty")
	else:
		# Pseudo pop first in the queue
		queue.front = (queue.front + 1) % queue.size # Calculate index to pop
		queue.items -= 1

		#Display status
		print("Element successfully dequeued!")
		main.pause_screen()

# NOTE: Doesn't actually utilize the front/rear
# index trackers for first and last queue methods!

def first_queue():
	if isEmpty():
		print("The queue is empty")
	else:
		print(queue.array[0],"is first in the queue")
def last_queue():
	if isEmpty():
		print("The queue is empty")
	else:
		print(queue.array[queue.size-1],"is the last one in the queue")