from hashlib import new
import main

class Node:
	def __init__(self, data):
		self.data = data
		self.next = None

class LinkedList:
	def __init__(self):
		self.head = None
	
	def append(self, new_data):
		new_node = Node(new_data)
		
		if self.head is None:
			self.head = new_node
			return

		last = self.head
		while last.next:
			last = last.next
		
		last.next = new_node

	def display_linked_list(self):
		temp = self.head
		while temp:
			print(temp.data, end=" ")
			temp = temp.next
	
	def delete_node_by_value(self):
		pass
	

def show_linkedlist_menu():
	lst = LinkedList()
	while True:
		choices = ["Append Mode", "Delete node by value", "Delete node at a given position", "Display linked list", "Go back"]
		main.generate_menu_header("Linked List", choices)

		num = main.prompt("Enter choice: ")
		
		# start of linked list menu:
		if num == 1:

			print("\nAppend Node:")
			print("Enter value: ", end="")
			val = int(input())

			lst.append(val)
			
			print("Node successfully appended!")
			main.pause_screen()

		elif num == 2:
			pass

		elif num == 3:
			pass

		elif num == 4:

			print("\nLinked List:")
			lst.display_linked_list()
			main.pause_screen()

		elif num == 5:
			main.show_data_structures_menu()
		else:
			print("Invalid. Please try again.")
		