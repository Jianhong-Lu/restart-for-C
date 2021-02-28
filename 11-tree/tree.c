#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *right;
	struct Node *left;
};
typedef struct Node Node;

Node *CreateTree(int *a, int size)
{
	Node *p[11] = {0};
	int i;
	for(i = 0; i < size; i ++)
	{
		p[i] = (Node *)malloc(sizeof(Node) * 1);
		p[i] -> data = a[i];
		p[i] -> right = NULL;
		p[i] -> left = NULL;
	}

	for(i = 0; i < 5; i ++)
	{
		p[i] -> left = p[2 * i + 1];
		p[i] -> right = p[2 * i + 2];
	}

	return p[0];
	
}

void PreOrderTree(Node *root)
{
	if(NULL == root)
	{
		return ;
	}

	//根－左－右
	printf("%d ", root -> data);
	PreOrderTree(root -> left);
	PreOrderTree(root -> right);
}

void MidOrderTree(Node *root)
{
	if(NULL == root)
	{
		return ;
	}

	//左－根－右
	MidOrderTree(root -> left);
	printf("%d ", root -> data);
	MidOrderTree(root -> right);
}

void PostOrderTree(Node *root)
{
	if(NULL == root)
	{
		return ;
	}

	//左－右－根
	PostOrderTree(root -> left);
	PostOrderTree(root -> right);
	printf("%d ", root -> data);
}
int main()
{
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	//得到根结点
	Node *root = CreateTree(array, sizeof(array) / sizeof(array[0]));

	PreOrderTree(root);
	printf("\n");

	MidOrderTree(root);
	printf("\n");

	PostOrderTree(root);
	printf("\n");
	return 0;
}
