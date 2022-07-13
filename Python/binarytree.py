import main

class Node:
	def __init__(self, key):
		self.left = None
		self.right = None
		self.val = key

def insert(root, key):
	if root is None:
		return Node(key)
	else:
		if root.val == key:
			return root
		elif root.val < key:
			root.right = insert(root.right, key)
		else:
			root.left = insert(root.left, key)
	return root

def display_in_order(root):
	if root:
		display_in_order(root.left)
		print(root.val, end=" ")
		display_in_order(root.right)

def display_pre_order(root):
	if root:
		print(root.val, end=" ")
		display_in_order(root.left)
		display_in_order(root.right)

def display_post_order(root):
	if root:
		display_in_order(root.left)
		display_in_order(root.right)
		print(root.val, end=" ")

def show_binarytree_menu():
	while True:
		choices = ["In-order traversal", "Pre-order traversal", "Post-order traversal", "Go back"]
		main.generate_menu_header("Binary Tree", choices)

		num = main.prompt("Enter choice: ")
		
		root = Node(6)
		root = insert(root, 5)
		root = insert(root, 8)
		root = insert(root, 3)
		root = insert(root, 12)
		root = insert(root, 9)
		root = insert(root, 7)

		# start of binary tree menu:
		if num == 1:

			print("\nIn-order Traversal:")
			display_in_order(root)
			main.pause_screen()
			
		elif num == 2:

			print("\nPre-order Traversal:")
			display_pre_order(root)
			main.pause_screen()
			
		elif num == 3:
			
			print("\nPost-order Traversal:")
			display_post_order(root)
			main.pause_screen()

		elif num == 4:
			main.show_data_structures_menu()
		else:
			print("Invalid. Please try again.")
		