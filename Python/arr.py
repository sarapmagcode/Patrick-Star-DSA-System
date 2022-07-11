import main

# Global arr variable
array = []

def show_array_menu():
	choices = ["Create array", "Show original", "Show sorted", "Search element", "Go back"]
	main.generate_menu_header("Array", choices)

	while True:
		num = main.prompt("Enter choice: ")
		if num == -1:
			continue
		
		# choices in array menu
		if num == 1:
			create_array()
			# break
		elif num == 2:
			show_original()
			# break
		elif num == 3:

			pass
		elif num == 5:
			main.show_data_structures_menu()
			# break
		else:
			print("Invalid. Please try again.")

def create_array():
	main.clear_screen()
	n = main.prompt("Enter the size of the array: ") # Pseudo asks for 'size'

	# Global arr var
	global array

	# Basic range loop for appending elements into
	# the empty list
	for x in range(n):
		array.append(main.prompt("Enter the " + str(x+1) + " element: ")) # TODO: Optimize printout
	
	print("Array Created!")
	# main.pause_screen # Pause Screen not working TODO
	# show_array_menu()

def show_original():
	print(array)

def show_sorted():
	print(array.sort())

def search_element():
	# Instantiate var 'n' as value to hold for searching a 
	# specific element
	n = main.prompt("Enter the value of an element to search: ")

	# Basic for-loop for traversing list
	for arr in array:
		if (n not in arr):
			print("Not here!")
		else:
			print("found it!")
