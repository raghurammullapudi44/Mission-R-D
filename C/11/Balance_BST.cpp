#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#pragma warning(disable: 4996)

void testcases();

int * malloc_int(int *,int);

int a_cmp(int *,int *);

struct BST * make_BST(int *,int,int);

bool inorder(struct BST *,struct BST *);

struct test
{
	int input[44];
	int n;
}testDB[15]={{{2,4,6,8,10,10},6},
			{{1,2,3,4},4},
			{{1,2,3,4,5,6,7,8},8},
			{{1,2,3,4,5,6,7,8,9},9},
			{{-1,0,1,2,3},5},
			{{1,3,3,5,7},5},
			{{2,2,2,2},4},
			{{},},
			{{3,3,3,3,3},5},
			{{3,4,5,5,6},5},
			{{3,4,5,5,5,6},6},
			{{1},1},
			{{0,1,2,3,4,4,5,5,5,6,6},11},
			{{-5,-4,-3,-2,-1},5},
			{{1,2,3},3}};

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

/*int * inorder(struct BST *root,int a[],static int n)
{
 	if(root==NULL)
		return a;
	
	a=inorder(root->left,a,n);
	if(a[0]==root->data)
	{
		//printf("%d ",root->data);
		a=a+1;
	}
	a=inorder(root->right,a,n);
}*/

bool inorder(struct BST *root,struct BST *prev)
{
    if (root!=NULL)
    {
        if (inorder(root->left,prev)==false)
          return false;
 
        if (prev != NULL && root->data < prev->data)
          return false;

        prev = root;
		//printf("%d ",root->data);

        inorder(root->right,prev);
    }
    return true;
}


struct BST * make_BST(int a[],int low,int high)
{
	int mid;

	if(low>high)
		return NULL;
	else
	{
		mid=(low+high)/2;

		struct BST *root = (struct BST *)malloc(sizeof(struct BST));
		root->data=a[mid];
		root->left=NULL;
		root->right=NULL;

		root->left=make_BST(a,low,mid-1);
		root->right=make_BST(a,mid+1,high);

		return root;
	}
}


void testcases()
{
	int i,*a,n;

	for(i=0;i<15;i++)
	{
		n=testDB[i].n;
		a=malloc_int(testDB[i].input,n);

		struct BST *root=make_BST(a,0,n-1);

		if(root!=NULL)
		{
			if(inorder(root,NULL)==true)
				printf("passed\n");
			else
				printf("failed\n");
		}
		else if(n==0)
			printf("passed\n");
		else
			printf("failed\n");
	}
}


int main()
{
	testcases();
	getch();
	return 0;
}