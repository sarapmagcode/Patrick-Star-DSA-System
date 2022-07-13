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
	
	def delete_node_by_value(self, key):
		temp = self.head

		if temp is not None:
			if temp.data == key:
				self.head = temp.next
				temp = None
				return
		
		flag = 0
		while temp:
			if temp.data == key:
				flag = 1
				break
			temp = temp.next
		
		if flag == 0:
			print("Node does not exist.")
			return

		temp = self.head
		while temp is not None:
			if temp.data == key:
				break
			prev = temp
			temp = temp.next
		
		if temp == None:
			return
		
		prev.next = temp.next
		temp = None

		print("Node successfully deleted!")
	
	def delete_node_by_position(self, pos):
		if self.head is None:
			return
		
		if pos == 1:
			self.head = self.head.next
			return self.head
		
		index = 0
		current = self.head
		prev = self.head
		temp = self.head
		flag = 0
		while current is not None:
			if index + 1 == pos:
				flag = 1
				temp = current.next
				break
			prev = current
			current = current.next
			index += 1
		
		if flag == 1:
			prev.next = temp
			print(f"Node at position {pos} successfully deleted.")
			return prev
		else:
			print("Position does not exist.")

def show_linkedlist_menu():
	lst = LinkedList()
	while True:
		choices = ["Append Mode", "Delete node by value", "Delete node at a given position", "Display linked list", "Go back"]
		main.generate_menu_header("Linked List", choices)

		num = main.prompt("Enter choice: ")
		
		# start of linked list menu:
		if num == 1:

			print("\nAppend Node")
			val = int(input("\nEnter value to append: "))

			lst.append(val)
			print("Node successfully appended!")

			main.pause_screen()

		elif num == 2:
			
			print("\nDelete node by value:")
			val = int(input("\nEnter value to delete: "))

			lst.delete_node_by_value(val)
			
			main.pause_screen()

		elif num == 3:
			
			print("\nDelete node at a given position")
			pos = int(input("Enter position: "))

			lst.delete_node_by_position(pos)

			main.pause_screen()

		elif num == 4:

			print("\nLinked List:")
			lst.display_linked_list()
			main.pause_screen()

		elif num == 5:
			main.show_data_structures_menu()
		else:
			print("Invalid. Please try again.")
		