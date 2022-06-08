from collections import defaultdict
import main

class Graph:
	def __init__(self, sz):
		self.sz = sz
		self.graph = defaultdict(list)
		self.matrix = [] * sz
		for i in range(sz):
			temp = [0] * sz
			self.matrix.append(temp)

	def add_edge(self, u, v):
		self.graph[u].append(v)
		self.matrix[u][v] = 1
		self.is_created = True
	
	def show_adjacency_list(self):
		for u in range(self.sz):
			print((u + 1), end=" ")
			for v in self.graph[u]:
				print("->", (v + 1), end=" ")
			print()

	def show_adjacency_matrix(self):
		for u in range(self.sz):
			if u == 0:
				print(" ", end=" ")
			print((u + 1), end=" ")

		# TODO: fix the spaces on large matrix dimensions
		print()
		for u in range(self.sz):
			print((u + 1), end="")
			for v in range(self.sz):
				print("".ljust(len(str(v))), self.matrix[u][v], end="")
			print()

def graph_prompt(question):
	while True:
		x = main.prompt(question)
		if x == -1:
			continue
		else:
			return x

def show_graph_menu():
	is_created = False
	while True:
		choices = ["Create graph", "Show adjacency list", "Show adjacency matrix", "Go back"]
		main.generate_menu_header("Graph", choices)
		
		num = main.prompt("Enter choice: ")
		if num == -1:
			main.pause_screen()
			continue
		
		# start of graph menu:
		if num == 1:
			print("\nCreate Graph")

			vertices = graph_prompt("Enter no. of vertices: ")
			edges = graph_prompt("Enter no. of edges: ")
	
			g = Graph(vertices)
			
			# TODO: fix the duplicate edges

			print(f"Enter {edges}  edges: ")
			i = 0
			while i < edges:
				print(f"\nFor edge {i + 1}: ")
				u = graph_prompt("Enter origin: ")
				v = graph_prompt("Enter destination: ")
				if u - 1 >= 0 and u - 1 < vertices and v - 1 >= 0 and v - 1 < vertices:
					g.add_edge(u - 1, v - 1)
					print(f"Edge {i + 1} added!")
					i += 1
				else:
					print("\nVertices are out of range. Please try again.")
			
			is_created = True
			print("\nGraph created successfully!")

			main.pause_screen()

		elif num == 2:

			if not is_created:
				print("\nPlease create graph first.")
				main.pause_screen()
				continue

			print("\nAdjacency List: ")
			g.show_adjacency_list()
			main.pause_screen()

		elif num == 3:

			if not is_created:
				print("\nPlease create graph first.")
				main.pause_screen()
				continue

			print("\nAdjacency Matrix: ")
			g.show_adjacency_matrix()
			main.pause_screen()

		elif num == 4:

			main.show_data_structures_menu()
			break

		else:
			print("Invalid. Please try again.")
			main.pause_screen()
		