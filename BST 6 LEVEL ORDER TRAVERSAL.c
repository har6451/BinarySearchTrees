#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct Node
{
    int data;
    struct Node*left;
    struct Node*right;
};

struct Node*queue[MAX];
int front=-1;
int rear=-1;

struct Node*creatNode(int n)
{
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=n;
    newNode->left=newNode->right=NULL;
    return newNode;
}

struct Node*insert(struct Node*root,int n)
{
    if(root==NULL)
    {
        root=creatNode(n);
    }
    else if(n<=root->data)
    {
        root->left=insert(root->left,n);
    }
    else
    {
        root->right=insert(root->right,n);
    }
    return root;
}

void insert_queue(struct Node*item)
{
    if(rear==MAX-1)
    {
        printf("Queue Overflow\n");
        return ;
    }
    if(front==-1)
    front=0;
    rear=rear+1;
    queue[rear]=item;
}

struct Node*del_queue()
{
    struct Node*item;
    if(front==-1 || front==rear+1)
    {
        printf("Queue is Empty\n");
        return 0;
    }
    item=queue[front];
    front=front+1;
    return item;
}

int queue_empty()
{
    if(front==-1 || front==rear+1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void levelorder(struct Node*root)
{
    struct Node*ptr=root;
    if(ptr==NULL)
    {
        printf("Tree is empty\n");
        return ;
    }
    insert_queue(ptr);
    while(!queue_empty())
    {
        ptr=del_queue();
        printf("%d",ptr->data);
        if(ptr->left!=NULL)
        {
            insert_queue(ptr->left);
        }
        if(ptr->right!=NULL)
        {
            insert_queue(ptr->right);
        }
    }
}

int main(){
    struct Node*root=NULL;
    int n;
    int c;
    do{
    printf("Enter a number : ");
    scanf("%d",&n);
    root=insert(root,n);
    
    printf("Do you want to insert more (y/n) ?");
    scanf("%d",&c);
}while(c==1);

levelorder(root);
getch();
return 0;
}