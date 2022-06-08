import main

def show_queue_menu():
	choices = ["Create queue", "Check if full", "Check if empty", "Enqueue/insert", "Dequeue/remove", "Get front/first element", "Get rear/back element", "Go back"]
	main.generate_menu_header("Queue", choices)
	
	while True:
		num = main.prompt("Enter choice: ")
		
		# start of queue menu:
		if num == 1:
			break
		elif num == 2:
			break
		elif num == 3:
			break
		elif num == 4:
			break
		elif num == 5:
			break
		elif num == 6:
			break
		elif num == 7:
			break
		elif num == 8:
			main.show_data_structures_menu()
			break
		else:
			print("Invalid. Please try again.")
