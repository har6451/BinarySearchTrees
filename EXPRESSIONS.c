#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>

struct Node {
    char data;
    struct Node*left;
    struct Node*right;
};

struct Node*tree(char postfix[]){
    struct Node*root;
    struct Node*n;
    struct Node*stack[100];
    int i;
    int top=-1;
    for(i=0;postfix[i]!='\0';i++){
        n=(struct Node*)malloc(sizeof(struct Node));
        n->data=postfix[i];
        n->left=n->right=NULL;
        if(isalpha(postfix[i]) || isdigit(postfix[i])){
            stack[++top]=n;
        }
        else
        {
            n->right=stack[top--];
            n->left=stack[top--];
            stack[++top]=n;
        }
    }
        root=stack[top--];
        return root;
}

void inorder(struct Node*root){
    if(root!=NULL)
        inorder(root->left);
        printf("%c",root->data);
        inorder(root->right);
}

void preorder(struct Node*root){
    if(root!=NULL)
        printf("%c",root->data);
        preorder(root->left);
        preorder(root->right);
}

void postorder(struct Node*root){
    if(root!=NULL)
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
}

void main(){
    struct Node*root;
    char postfix[20];
    printf("Enter the Postfix Expression :");
    gets(postfix);
    root=tree(postfix);
    printf("Infix: ");
    inorder(root);
    printf("\nPrefix : "); 
    preorder(root);
    printf("\nPostfix:");
    postorder(root);
    getch();
}
