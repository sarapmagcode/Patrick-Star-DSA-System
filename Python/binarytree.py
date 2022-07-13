import main

def show_binarytree_menu():
	choices = ["In-order traversal", "Pre-order traversal", "Post-order traversal", "Go back"]
	main.generate_menu_header("Binary Tree", choices)

	while True:
		num = main.prompt("Enter choice: ")
		
		# start of binary tree menu:
		if num == 1:
			pass
		elif num == 4:
			main.show_data_structures_menu()
		else:
			print("Invalid. Please try again.")
		