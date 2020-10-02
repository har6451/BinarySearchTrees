#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<math.h>
#include<malloc.h>

struct node
{
    int data; //node will store an integer
    struct node *right_child; // right child
    struct node *left_child; // left child
};


int search(struct node *root, int x)
{

	
    if(root==NULL)                                        //if root->data is x then the element is found
        return 0;

    
    else if(root->data==x)
    return 1;
    

    else if(x >root->data)                             // x is greater, so we will search the right subtree
        return search(root->right_child , x);
        
        
    else                                              //x is smaller than the data, so we will search the left subtree
	    return search(root->left_child , x);
}


//function to find the minimum value in a node
struct node* find_minimum(struct node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left_child != NULL) // node with minimum value will have no left child
        return find_minimum(root->left_child); // left most element will be minimum
    return root;
}


void minValue(struct node*root)  
{  
  
/* loop down to find the leftmost leaf */
while (root->left_child != NULL)  
{  
    root = root->left_child;  
}  
printf("The Minimum Value of the Tree is :%d",root->data);  
}  


void maxValue(struct node*root)  
{  
/* loop down to find the leftmost leaf */
while (root->right_child != NULL)  
{  
    root = root->right_child;  
}  
printf("The Maximum Value of the Tree is :%d",root->data);  
}


//function to create a node
struct node* new_node(int x)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left_child = NULL;
    p->right_child = NULL;
    
    return p;
}

int isBSTUtil(struct node* root, int min, int max); 

/* Returns true if the given tree is a binary search tree 
(efficient version). */
int isBST(struct node* root) 
{ 
return(isBSTUtil(root, INT_MIN, INT_MAX)); 
} 

/* Returns true if the given tree is a BST and its 
values are >= min and <= max. */
int isBSTUtil(struct node* root, int min, int max) 
{ 
/* an empty tree is BST */
if (root==NULL) 
	return 1; 
		
/* false if this node violates the min/max constraint */
if (root->data < min || root->data > max) 
	return 0; 

/* otherwise check the subtrees recursively, 
tightening the min or max constraint */
return
	isBSTUtil(root->left_child, min, root->data) && // Allow only distinct values 
	isBSTUtil(root->right_child, root->data, max); // Allow only distinct values 
} 

struct node* insert(struct node *root, int x)
{
    //searching for the place to insert
    if(root==NULL)
        return new_node(x);
    else if(x>root->data) // x is greater. Should be inserted to right
        root->right_child = insert(root->right_child, x);
    else // x is smaller should be inserted to left
        root->left_child = insert(root->left_child,x);
    return root;
}

// function to delete a node
struct node* delete(struct node *root, int x)
{
    //searching for the item to be deleted
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right_child = delete(root->right_child, x);
    else if(x<root->data)
        root->left_child = delete(root->left_child, x);
    else
    {
        //No Children
        if(root->left_child==NULL && root->right_child==NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
        else if(root->left_child==NULL || root->right_child==NULL)
        {
            struct node *temp;
            if(root->left_child==NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            free(root);
            return temp;
        }

        //Two Children
        else
        {
            struct node *temp = find_minimum(root->right_child);
            root->data = temp->data;
            root->right_child = delete(root->right_child, temp->data);
        }
    }
    return root;
}

void inorder(struct node *root)
{
    if(root!=NULL) // checking if the root is not null
    {
        inorder(root->left_child); // visiting left child
        printf(" %d ", root->data); // printing data at root
        inorder(root->right_child);// visiting right child
    }
}

int Height(struct node* root)  
{ 
   if (root==NULL)  
       return -1; 
   else 
   { 
       /* compute the depth of each subtree */
       int left = Height(root->left_child); 
       int right =Height(root->right_child); 
  
       /* use the larger one */
       if (left > right)  
           return(left+1); 
       else return(right+1); 
       return right;
   } 
}

struct node*removed(struct node*root,int max,int min)
{
if (root==NULL)
{
	return NULL;
}	
else
{
	root->left_child=removed(root->left_child,max,min);
	root->right_child=removed(root->right_child,max,min);
	if(root->data< min){
		return root->right_child;
	}
	else if(root->data>max){
		return root->left_child;
	}
}
	return root;
}
// int Height(struct node*root){
//	if(root==NULL)
//	{
//		return -1;
//	}
//	else
//	{
//		return max(Height(root->left_child),Height(root->right_child))+1;
//	}
//}

void preorder(struct node*root)
{
    if(root!=NULL)
    {
        printf(" %d ",root->data);
        preorder(root->left_child);
        preorder(root->right_child);
    }
}

void postorder(struct node*root)
{
    if(root!=NULL)
    {
        postorder(root->left_child);
        postorder(root->right_child);
        printf(" %d ", root->data);
    }
}

int sumOfNodes(struct node*root,int k)
{
	if (root==NULL){
		return 0;
	}
	if(k==1){
		return root->data;
	}
	
	return sumOfNodes(root->left_child,k-1) + sumOfNodes(root->right_child,k-1);
}

//int isBinarySearchTree(struct node*root,)

int main()
{
    int choice;
    int number;
    struct node *root;
    root = new_node(50);
    //insert(root,50);
    insert(root,20);
    insert(root,0);
    insert(root,40);
    insert(root,10);
    insert(root,5);
    insert(root,90);
    insert(root,60);
    insert(root,80);
    insert(root,70);
    //insert(root,42);
   // insert(root,23);

    printf("\n");
  //  root=insert(root,97);
    while(1){
    printf("Enter the choice:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:    
    inorder(root);
    break;
    
    case 2:
    preorder(root);
    break;
    
    case 3:
    postorder(root);
    break;
    
    case 4:
    printf("Enter the number to be searched :");
    scanf("%d",&number);
    if(search(root,number)==1)
    printf("Found");
    else
    printf("Not found");
    break;
    
    case 5:
    minValue(root);
    break;
    
    case 6:
    maxValue(root);
    break;
    
    case 7:
    printf("The height of the Tree is : %d" ,Height(root));	
    break;
    
//    case 8
//  if(isBST(root))
//  printf("It is a Binary Search Tree");
//  else
//  printf("It is Not a Binary Search Tree");
//    break;
    
    case 9:
    exit(0);
    break;
    
    case 10:
    	printf("%d",sumOfNodes(root,1));
    	break;
    case 11:
    	removed(root,50,20);
    	break;
    }
    printf("\n");
    }
    return 0;
}

