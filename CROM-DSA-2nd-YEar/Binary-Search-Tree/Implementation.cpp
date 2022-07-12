#include <bits/stdc++.h>
#include "Data.h"

using namespace std;

void IntBinaryTree::insertNode(int num) {
	TreeNode *newNode, *nodePtr;
	newNode = new TreeNode;
	newNode->value = num;
	newNode->left = newNode->right = NULL;
	if (!root) {
		root = newNode;
	} else {
		nodePtr = root;
		while (nodePtr != NULL) {
			if (num < nodePtr->value) {
				if (nodePtr->left) {
					nodePtr = nodePtr->left;
				} else {
					nodePtr->left = newNode;
					break;
				}
			} else if (num > nodePtr->value) {
				if (nodePtr->right) {
					nodePtr = nodePtr->right;
				} else {
					nodePtr->right = newNode;
					break;
				}
			} else {
				cout << "Duplicate value found in tree.\n";
				break;
			}
		}
	}
}

void IntBinaryTree::displayInOrder(TreeNode *nodePtr) {
	if (nodePtr) {
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << endl;
		displayInOrder(nodePtr->right);
	}
}

void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) {
	if (nodePtr) {
		cout << nodePtr->value << endl;
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}

void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) {
	if (nodePtr) {
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << nodePtr->value << endl;
	}
}

bool IntBinaryTree::searchNode(int num) {
	TreeNode *nodePtr = root;
	while (nodePtr) {
		if (nodePtr->value == num) {
			return true;
		} else if (num  < nodePtr->value) {
			nodePtr = nodePtr->left;
		} else {
			nodePtr = nodePtr->right;
		}
	}
	return false;
}

void IntBinaryTree::remove(int num) {
	deleteNode(num, root);
}

void IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr) {
	if (num < nodePtr->value) {
		deleteNode(num, nodePtr->left);
	} else if (num > nodePtr->value) {
		deleteNode(num, nodePtr->right);
	} else {
		makeDeletion(nodePtr);
	}
}

void IntBinaryTree::makeDeletion(TreeNode *&nodePtr) {
	TreeNode *tempNodePtr;
	if (nodePtr == NULL) {
		cout << "Cannot delete empty node.\n";
	} else if (nodePtr->right == NULL) {
		tempNodePtr = nodePtr;
		nodePtr	= nodePtr->left;
		delete tempNodePtr;
	} else if (nodePtr->left == NULL) {
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	} else {
		tempNodePtr = nodePtr->right;
		while (tempNodePtr->left) {
			tempNodePtr = tempNodePtr->left;
		}
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}
