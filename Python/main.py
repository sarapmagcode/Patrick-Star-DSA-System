import os
import arr
import queue
import stack
import linkedlist
import binarytree
import graph

# TODO Error handling? 

def pause_screen():
	inp = input("\n\nPress enter to continue...")
	print()

def clear_screen():
	os.system("clear")

def prompt(question):
	try:
		inp = int(input(question))
		return inp
	except ValueError:
		print("Invalid. Please try again.")
		return -1

def generate_menu_header(title, choices):
	os.system("clear")
	print("<<Patrick Star DS Program>>")
	print(f"===== {title} =====")
	print("Choose:")
	for i in range(len(choices)):
		print(f"{i + 1}. {choices[i]}")

def show_data_structures_menu():
	choices = ["Array", "Queue", "Stack", "Linked List", "Binary Tree", "Graph Theory", "Exit"]
	generate_menu_header("Data Structures", choices)
	
	while True:
		choice = prompt("Enter choice: ")
		if choice == -1:
			continue

		# start of data structures menu:
		if choice == 1:
			arr.show_array_menu()
		elif choice == 2:
			queue.show_queue_menu()
		elif choice == 3:
			stack.show_stack_menu()
		elif choice == 4:
			linkedlist.show_linkedlist_menu()
		elif choice == 5:
			binarytree.show_binarytree_menu()	
		elif choice == 6:
			graph.show_graph_menu()
		elif choice == 7:
			print("Program exiting...")
			exit()
		else:
			print("Invalid. Please try again.")

def main():
	show_data_structures_menu()

if __name__ == "__main__":
	main()
