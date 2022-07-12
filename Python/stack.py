import main

# Global stack variables
stackArray = []
size = 0
top = -1
first_time = True

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
	global stackArray, top

	# Check if this is first time/element to push
	# List/Array of Stack doesn't like to push with INDICES
	# WITHOUT first populating the list or using the 'append' function
	#
	# A workaround has been implemented

	val = main.prompt("Enter a value to push: ")
	top += 1

	if(first_time):
		stackArray.append(val)
	else:
		stackArray[top] = val
	
	

def pop():
	# Connect to global vars
	global stackArray, top

	if(isEmpty()):
		print("The stack is empty")
	else:
		top -= 1
		stackArray[top]

def peek():
	if(isEmpty()):
		print("The stack is empty")
	else:
		#NOTE: Basic display output
		print("The top of the stack is", stackArray[top])

def isEmpty():
	status = True if top == -1 else False
	return status

def display():
	# #NOTE: Basic display output
	# if(isEmpty()):
	# 	print("The stack is empty")
	# else:
	# 	print(stackArray)

	if(isEmpty()):
		print("The stack is empty")
	else:
		for i in range(top+1):
			print(stackArray[i],end=" ")

		main.pause_screen()
		main.clear_screen
		
