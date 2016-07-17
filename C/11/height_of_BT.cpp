#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#pragma warning(disable: 4996)

void testcases();

int * malloc_int(int *,int);

int a_cmp(int,int);

struct BST * make_BT(int *,int,int);

int find_height(struct BST *);


struct test
{
	int input[44];
	int n;
	int height;
}testDB[15]={{{2,4,6,8,11,10},6,2},
			{{1,4,3,2},4,2},
			{{1,2,3,4,5,6,7,8},8,3},
			{{1,2,3,10,11,6,7,8,9},9,3},
			{{-1,0,1,2,3},5,2},
			{{1,3,8,3,5,7},6,2},
			{{10,2,2,2,2,1,2,3,0},5,2},
			{{},0,-1},
			{{3,3,3,3,3,1,2,3},5,2},
			{{8,3,4,5,5,6,1,2,7},5,2},
			{{5,4,5,5,5,6,0},6,2},
			{{1},1,0},
			{{0,1,2,3,4,4,5,4,5,5,6,6},12,3},
			{{-5,-4,-3,-10,-1},5,2},
			{{1,3,2},3,1}};

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

int a_cmp(int a,int b)
{
	if(a==b)
		return 0;
	else
		return 1;
}

int find_height(struct BST *root)
{
	int l,r;

	if(root==NULL)
		return -1;

	l=find_height(root->left);
	r=find_height(root->right);

	if(l>r)
		return l+1;
	else
		return r+1;
}


struct BST * make_BT(int a[],int low,int high)
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

		root->left=make_BT(a,low,mid-1);
		root->right=make_BT(a,mid+1,high);

		return root;
	}
}


void testcases()
{
	int i,*a,n,h,op,check;

	for(i=0;i<15;i++)
	{
		n=testDB[i].n;
		a=malloc_int(testDB[i].input,n);
		h=testDB[i].height;

		struct BST *root=make_BT(a,0,n-1);

		op=find_height(root);

		check=a_cmp(h,op);

		if(check==0)
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