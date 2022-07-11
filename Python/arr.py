import main

# NOTE: adding 'sep' or 'end' parameters isn't possible
# to 'input' func within 'prompt'

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
		elif num == 2:
			show_original()
		elif num == 3:
			show_sorted()
		elif num == 4:
			search_element()
		elif num == 5:
			main.show_data_structures_menu()
		else:
			print("Invalid. Please try again.")

def create_array():
	main.clear_screen()
	n = main.prompt("Enter the size of the array: ") # Pseudo asks for 'size'

	# Global arr var
	global array

	# Make sure list is empty
	array.clear()

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
	# Note adding '.sort' inside print func returns NONE
	# so sorting of list is seperated
	
	# Create a temp sorted arr var to be sorted
	# for every func call~
	sorted_array = array.copy()
	sorted_array.sort()
	print(sorted_array)

def search_element():
	# Instantiate var 'n' as value to hold for searching a 
	# specific element
	n = main.prompt("Enter the value of an element to search: ")

	# Basic check if inside array
	if (n in array):
		print(str(n) + " is found within the array!") # TODO: Optimize printout
	else:
		print(str(n) + " is NOT found within the array!\
							 Try to see if the entered value is correct\
								 then try again.") # TODO: Optimize printout
