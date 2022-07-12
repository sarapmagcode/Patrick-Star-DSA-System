import main

def show_queue_menu():
	choices = ["Create queue", "Check if full", "Check if empty", "Enqueue/insert", "Dequeue/remove", "Get front/first element", "Get rear/back element", "Go back"]
	main.generate_menu_header("Queue", choices)
	
	while True:
		num = main.prompt("Enter choice: ")
		
		# start of queue menu:
		if num == 1:
			pass
		elif num == 2:
			pass
		elif num == 3:
			pass
		elif num == 4:
			pass
		elif num == 5:
			pass
		elif num == 6:
			pass
		elif num == 7:
			pass
		elif num == 8:
			main.show_data_structures_menu()
			pass
		else:
			print("Invalid. Please try again.")
