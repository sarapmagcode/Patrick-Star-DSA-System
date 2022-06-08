import os
import array
import queue
import stack
import linkedlist
import binarytree
import graph

def pause_screen():
	inp = input("\nPress enter to continue...")

def prompt(question):
	try:
		inp = int(input(question))
		return inp
	except ValueError:
		print("Invalid. Please try again.")
		return -1

def generate_menu_header(title, choices):
	os.system("clear")
	print("<<Patrick Star DSA Program>>")
	print(f"===== {title} =====")
	print("Choose:")
	for i in range(len(choices)):
		print(f"{i + 1}. {choices[i]}")

def show_data_structures_menu():
	choices = ["Array", "Queue", "Stack", "Linked List", "Binary Tree", "Graph Theory", "Go back"]
	generate_menu_header("Data Structures", choices)
	
	while True:
		choice = prompt("Enter choice: ")
		if choice == -1:
			continue

		# start of data structures menu:
		if choice == 1:
			array.show_array_menu()
			break
		elif choice == 2:
			queue.show_queue_menu()
			break
		elif choice == 3:
			stack.show_stack_menu()
			break
		elif choice == 4:
			linkedlist.show_linkedlist_menu()
			break
		elif choice == 5:
			binarytree.show_binarytree_menu()	
			break
		elif choice == 6:
			graph.show_graph_menu()
			break
		elif choice == 7:
			main()
			break
		else:
			print("Invalid. Please try again.")

def show_algorithms_menu():
	choices = ["Searching Algorithms", "Sorting Algorithms", "Graph Algorithms"]
	generate_menu_header("Algorithms", choices)

def main():
	generate_menu_header("Main Menu", ["Data Structures", "Algorithms", "Exit"])

	while True:
		choice = prompt("Enter choice: ")
		if choice == -1:
			continue

		# choices in main menu
		if choice == 1:
			show_data_structures_menu()
			break
		elif choice == 2:
			show_algorithms_menu()
			break
		elif choice == 3:
			print("Exiting...")
			quit()
		else:
			print("Invalid. Please try again.")

if __name__ == "__main__":
	main()
