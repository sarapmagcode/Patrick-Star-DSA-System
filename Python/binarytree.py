import main

def show_binarytree_menu():
	choices = ["Display tree", "In-order traversal", "Pre-order traversal", "Post-order traversal", "Go back"]
	main.generate_menu_header("Binary Tree", choices)

	while True:
		num = main.prompt("Enter choice: ")
		
		# start of binary tree menu:
		if num == 1:
			break
		elif num == 5:
			main.show_data_structures_menu()
			break
		else:
			print("Invalid. Please try again.")
		