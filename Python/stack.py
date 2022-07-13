import main

class stack:
	array = []
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
	
	stack.size = main.prompt("Enter the size of the stack: ") # Pseudo asks for 'size'

def push():
	# Check if this is first time/element to push
	# List/Array of Stack doesn't like to push with INDICES
	# WITHOUT first populating the list or using the 'append' function
	#
	# A workaround has been implemented

	val = main.prompt("Enter a value to push: ")
	stack.top += 1

	if(stack.first_time):
		stack.array.append(val)
	else:
		stack.array[stack.top] = val
	
	

def pop():
	if(isEmpty()):
		print("The stack is empty")
	else:
		stack.top -= 1
		stack.array[stack.top]

def peek():
	if(isEmpty()):
		print("The stack is empty")
	else:
		#NOTE: Basic display output
		print("The top of the stack is", stack.array[stack.top])

def isEmpty():
	status = True if stack.top == -1 else False
	return status

def display():
	if(isEmpty()):
		print("The stack is empty")
	else:
		for i in range(stack.top+1):
			print(stack.array[i],end=" ")

		main.pause_screen()
		main.clear_screen
		
