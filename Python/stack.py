import main

class stack:
	array = []
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
			push()
		elif num == 2:
			pop() 
		elif num == 3:
			peek()
		elif num == 4:
			display_boolean_handler(isEmpty())
		elif num == 5:
			display()
		elif num == 6:
			main.show_data_structures_menu()
		else:
			print("Invalid. Please try again.")

def create_stack():
	stack.size = main.prompt("Enter the size of the stack: ")

def push():
	val = main.prompt("Enter a value to push: ")
	stack.top += 1
	stack.array.append(val)

	#Display status
	print("Value has been pushed!")
	main.pause_screen()

def pop():
	if(isEmpty()):
		print("The stack is empty")
	else:
		stack.top -= 1
		stack.array[stack.top]
		
		#Display status
		print("Value has been popped!")
		main.pause_screen()

def peek():
	if(isEmpty()):
		print("The stack is empty")
	else:
		print("The top of the stack is", stack.array[stack.top])

def isEmpty():
	status = True if stack.top == -1 else False
	return status

def display_boolean_handler(bool):
	printout = "The stack is EMPTY!" if bool else "The stack is not empty"

	print(printout)
	main.pause_screen()

def display():
	if(isEmpty()):
		print("The stack is empty")
	else:
		for i in range(stack.top+1):
			print(stack.array[i],end=" ")

		main.pause_screen()
		
