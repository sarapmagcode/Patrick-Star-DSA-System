import main

def show_stack_menu():
	choices = ["Push", "Pop", "Peek", "Check if empty", "Display", "Go back"]
	main.generate_menu_header("Stack", choices)
	
	while True:
		num = main.prompt("Enter choice: ")
		
		# start of stack menu:
		if num == 1:
			pass
		elif num == 6:
			main.show_data_structures_menu()
		else:
			print("Invalid. Please try again.")
