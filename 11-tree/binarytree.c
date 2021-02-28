#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
typedef struct Node Node;

Node *BsTree(Node *root, int num)
{
	if(NULL == root)
	{
		Node *n = (Node *)malloc(sizeof(Node) * 1);
		n -> data = num;
		return n;
	}
	else
	{
		if(num > root -> data)
		{
			root -> right = BsTree(root -> right, num);
		}
		else
		{
			root -> left = BsTree(root -> left, num);
		}
	}
}

void MidOrderTree(Node *root)
{
	if(NULL == root)
	{
		return;
	}

	MidOrderTree(root -> left);
	printf("%d ", root -> data);
	MidOrderTree(root -> right);

}

int main()
{
//	int a[SIZE] = {0};
	Node * root =(Node *)malloc(sizeof(Node) * 1);
	Node * n =(Node *)malloc(sizeof(Node) * 1);
	int i, num;
	for(i = 0; i < SIZE; i ++)
	{
		scanf("%d", &num);
		n = BsTree(root, num);
//		printf("%d ", n -> data);
	}

	MidOrderTree(n);
	printf("\n");
}
