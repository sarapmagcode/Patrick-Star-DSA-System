import main

def show_linkedlist_menu():
	choices = ["Append Mode", "Delete Node", "Delete node at a given position", "Display", "Go back"]
	main.generate_menu_header("Linked List", choices)

	while True:
		num = main.prompt("Enter choice: ")
		
		# start of linked list menu:
		if num == 1:
			print("Append Node")
			pass
		elif num == 5:
			main.show_data_structures_menu()
		else:
			print("Invalid. Please try again.")
		