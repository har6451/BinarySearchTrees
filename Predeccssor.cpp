#include<iostream>
using namespace std;
struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

//Function to find some data in the tree
Node* Find(Node*root, int data) {
	if(root == NULL) return NULL;
	else if(root->data == data) return root;
	else if(root->data < data) return Find(root->right,data);
	else return Find(root->left,data);
}

//Function to find Node with minimum value in a BST
struct Node* FindMin(struct Node* root) {
	if(root == NULL) return NULL;
	while(root->left != NULL)
		root = root->left;
	return root;
}

struct Node* FindMax(struct Node* root) {
	if(root == NULL) return NULL;
	while(root->right!= NULL)
		root = root->right;
	return root;
}

//Function to find Inorder Successor in a BST
struct Node* GetPredeccessor(struct Node* root,int data) {
	// Search the Node - O(h)
	struct Node* current = Find(root,data);
	if(current == NULL) return NULL;
	if(current->left != NULL) {  //Case 1: Node has right subtree
		return FindMax(current->left); // O(h)
	}
	else {   //Case 2: No right subtree  - O(h)
		struct Node* Predeccessor = NULL;
		struct Node* ancestor = root;
		while(ancestor != current) {
			if(current->data > ancestor->data) {
				Predeccessor = ancestor; // so far this is the deepest node for which current node is in left
				ancestor = ancestor->right;
			}
			else
				ancestor = ancestor->left;
		}
		return Predeccessor;
	}
}
 
//Function to visit nodes in Inorder
void Inorder(Node *root) {
	if(root == NULL) return;
 
	Inorder(root->left);       //Visit left subtree
	printf("%d ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}
 
// Function to Insert Node in a Binary Search Tree
Node* Insert(Node *root,char data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}
 
int main() {
	/*Code To Test the logic
	  Creating an example tree
	            5
			   / \
			  3   10
			 / \   \
			1   4   11
    */
	Node* root = NULL;
	root = Insert(root,5); root = Insert(root,10);
	root = Insert(root,3); root = Insert(root,4); 
	root = Insert(root,1); root = Insert(root,11);

	//Print Nodes in Inorder
	cout<<"Inorder Traversal: ";
	Inorder(root);
	cout<<"\n";

	// Find Inorder successor of some node. 
	struct Node* Predeccessor = GetPredeccessor(root,10);
	if(Predeccessor == NULL) cout<<"No successor Found\n";
	else
    cout<<"Predeccessor is "<<Predeccessor->data<<"\n";
}