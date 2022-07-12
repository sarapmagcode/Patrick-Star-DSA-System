import main

# Global stack variables
stck = []
size = 0
top = -1

def show_stack_menu():
	#Asks user first generation of stack size first
	create_stack()

	choices = ["Push", "Pop", "Peek", "Check if empty", "Display", "Go back"]
	main.generate_menu_header("Stack", choices)
	
	while True:
		num = main.prompt("Enter choice: ")
		
		# start of stack menu:
		if num == 1:
			push() # TODO: Prompt if success or empty
		elif num == 2:
			pop() # TODO: Prompt if success or empty
		elif num == 3:
			peek()
		elif num == 4:
			print(isEmpty()) # TODO: Rework | False = NOT empty || True = EMPTY
		elif num == 5:
			display()
		elif num == 6:
			main.show_data_structures_menu()
		else:
			print("Invalid. Please try again.")

def create_stack():
	main.clear_screen()

	# Connect to global vars
	global size
	
	size = main.prompt("Enter the size of the stack: ") # Pseudo asks for 'size'

def push():
	# Connect to global vars
	global stck, top

	val = main.prompt("Enter a value to push: ")
	top += 1
	stck[0] = val

def pop():
	# Connect to global vars
	global stck, top

	if(isEmpty()):
		print("The stack is empty")
	else:
		top -= 1
		stck[top]

def peek():
	if(isEmpty()):
		print("The stack is empty")
	else:
		#NOTE: Basic display output
		print("The top of the stack is", stck[top])

def isEmpty():
	status = True if top == -1 else False
	return status

def display():
	#NOTE: Basic display output
	if(isEmpty()):
		print("The stack is empty")
	else:
		print(stck)
