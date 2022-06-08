import main

def show_array_menu():
	choices = ["Create array", "Show original", "Show sorted", "Search element", "Go back"]
	main.generate_menu_header("Array", choices)

	while True:
		num = main.prompt("Enter choice: ")
		if num == -1:
			continue
		
		# choices in array menu
		if num == 1:
			break
		elif num == 5:
			main.show_data_structures_menu()
			break
		else:
			print("Invalid. Please try again.")
		