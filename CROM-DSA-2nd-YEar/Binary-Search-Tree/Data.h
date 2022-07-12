#ifndef DATA_H
#define DATA_H

class IntBinaryTree {
	private:
		struct TreeNode {
			int value;
			TreeNode *left;
			TreeNode *right;
		};
		TreeNode *root;
		void destroySubTree(TreeNode *);
		void deleteNode(int, TreeNode *&);
		void makeDeletion(TreeNode *&);
		void displayInOrder(TreeNode *);
		void displayPreOrder(TreeNode *);
		void displayPostOrder(TreeNode *);
	public:
		IntBinaryTree() {
			root = NULL;
		}
		~IntBinaryTree() {
//			destroySubTree(root);
		}
		void insertNode(int);
		bool searchNode(int);
		void remove(int);
		void showNodesInOrder(void) {
			displayInOrder(root);
		}
		void showNodesPreOrder() {
			displayPreOrder(root);
		}
		void showNodesPostOrder() {
			displayPostOrder(root);
		}
};

#endif
