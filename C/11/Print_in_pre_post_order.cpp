#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#pragma warning(disable: 4996)

void testcases();

int * malloc_int(int *,int);

int a_cmp(int *,int *);

struct BST * make_BST(struct BST *,struct BST *);

bool inorder(struct BST *,struct BST *);

void Print_inorder(struct BST *);

void Print_preorder(struct BST *);

void Print_postorder(struct BST *);

struct test
{
	int input[44];
	int n;
}testDB[15]={{{2,4,6,8,11,10},6},
			{{1,4,3,2},4},
			{{1,2,3,4,5,6,7,8},8},
			{{1,2,3,10,11,6,7,8,9},9},
			{{-1,0,1,2,3},5},
			{{1,3,8,3,5,7},6},
			{{2,2,2,2,1},5},
			{{},},
			{{3,3,3,3,3},5},
			{{3,4,5,5,6},5},
			{{5,4,5,5,5,6},6},
			{{1},1},
			{{0,1,2,3,4,4,5,4,5,5,6,6},12},
			{{-5,-4,-3,-2,-1},5},
			{{1,3,2},3}};

struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
};

int * malloc_int(int ip[],int n)
{
	int i,*a;
	a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		a[i]=ip[i];
	return a;
}

void Print_inorder(struct BST *root)
{
 	if(root==NULL)
		return;
	
	Print_inorder(root->left);
	printf("%d ",root->data);
	Print_inorder(root->right);
}

void Print_preorder(struct BST *root)
{
 	if(root==NULL)
		return;

	printf("%d ",root->data);
	Print_preorder(root->left);
	Print_preorder(root->right);
}

void Print_postorder(struct BST *root)
{
 	if(root==NULL)
		return;
	
	Print_postorder(root->left);
	Print_postorder(root->right);
	printf("%d ",root->data);
}

bool inorder(struct BST *root,struct BST *prev)
{
    if (root!=NULL)
    {
        if (!inorder(root->left,prev))
          return false;
 
        if (prev != NULL && root->data < prev->data)
          return false;

        prev = root;
		//printf("%d ",root->data);

        return inorder(root->right,prev);
    }
    return true;
}


struct BST * make_BST(struct BST *root,struct BST *temp)
{

	if (temp->data <= root->data)
	{
      if (root->left == NULL)
	  {
         root->left = temp;
	  }
      else
         make_BST(root->left, temp);
   }
 
   else if (temp->data > root->data)
   {
      if (root->right == NULL)
	  {
         root->right = temp;
	  }
      else
         make_BST(root->right, temp);
   }
   return root;
}


void testcases()
{
	int i,*a,n,j;

	for(i=0;i<15;i++)
	{
		n=testDB[i].n;
		a=malloc_int(testDB[i].input,n);

		struct BST *root=(struct BST *)malloc(sizeof(struct BST));
		
		root->data=a[0];
		root->left=NULL;
		root->right=NULL;

		for(j=1;j<n;j++)
		{
			struct BST *temp = (struct BST *)malloc(sizeof(struct BST));
			temp->data=a[j];
			temp->left=NULL;
			temp->right=NULL;
			root=make_BST(root,temp);
		}

		if(root!=NULL && n!=0)
		{
			if(inorder(root,NULL)==true)
			{
				printf("Valid BST\n");
				printf("IN ORDER:");
				Print_inorder(root);
				printf(",");
				printf("PRE ORDER:");
				Print_preorder(root);
				printf(",");
				printf("POST ORDER:");
				Print_postorder(root);
				printf("\n");
			}
			else
				printf("NOT BST\n");
		}
		else if(n==0)
			printf("Valid BST\n");
		else
			printf("NOT BST\n");
	}
}


int main()
{
	testcases();
	getch();
	return 0;
}