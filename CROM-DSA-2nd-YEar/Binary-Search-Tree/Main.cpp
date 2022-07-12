#include <bits/stdc++.h>
#include "Data.h"
#include "Implementation.cpp"

using namespace std;

int main(){
	
	IntBinaryTree tree;
	
	// inserting nodes
	cout << "Inserting nodes. ";
	tree.insertNode(5);
	tree.insertNode(8);
	tree.insertNode(3);
	tree.insertNode(12);
	tree.insertNode(9);
	tree.insertNode(7); // -> for two children of '8'
	cout << endl;
	
	// traversing the binary tree
	//	cout << "Inorder Traversal:\n";
	//	tree.showNodesInOrder();
	//	cout << "\nPreOrder Traversal:\n";
	//	tree.showNodesPreOrder();
	//	cout << "\nPostorder Traversal:\n";
	//	tree.showNodesPostOrder();

	// searching an element in the binary tree
	//	if (tree.searchNode(3)) {
	//		cout << "3 is found in the tree.\n";
	//	} else {
	//		cout << "3 was not found in the tree.\n";
	//	}

	// deleting a node in the binary tree
	//	cout << "Here are the values in the tree:\n";
	//	tree.showNodesInOrder();
	//	cout << "Deleting 8...\n";
	//	tree.remove(8);
	//	cout << "Deleting 12...\n";
	//	tree.remove(12);
	//	cout << "Now, here are the nodes:\n";
	//	tree.showNodesInOrder();
	
	return 0;
}
