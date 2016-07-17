#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#pragma warning(disable: 4996)

void testcases();

int * malloc_int(int *,int);

int a_cmp(int *,struct sll *,int);

struct BST * make_BT(int *,int,int);

int find_height(struct BST *,int,int);

struct sll * insert_in_list(int,struct sll *);

struct sll * find_nodes(struct BST *,int,int *);

struct test
{
	int input[44];
	int n;
	int output[44];
	int n1;
}testDB[15]={{{2,4,6,8,11,10},6,{6},1},
{{1,4,3,2},4,{4},1},
{{1,2,3,4,5,6,7,8},8,{8},1},
{{1,2,3,10,11,6,7,8,9},9,{10,9},2},
{{-1,0,1,2,3},5,{},0},
{{1,3,8,3,5,7},6,{},0},
{{10,2,2,2,2,1,2,3,0},10,{10,2,1,0},4},
{{},0,{},0},
{{3,3,3,3,3,1,2,3},5,{},0},
{{8,3,4,5,5,6,1,2,7},5,{8,5},2},
{{5,4,5,5,5,6,0},6,{4,5,6},3},
{{1},1,{1},1},
{{0,1,2,3,4,4,5,4,5,5,6,6},12,{},0},
{{-5,-4,-3,-10,-1},5,{},0},
{{1,3,2},3,{3},1}};

struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
};

struct sll
{
	int data;
	struct sll *ptr;
};

int * malloc_int(int ip[],int n)
{
	int i,*a;
	a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		a[i]=ip[i];
	return a;
}

int a_cmp(int a[],struct sll *head,int n)
{
	int i=0;
	while(i<n && head!=NULL)
	{
		if(a[i] != head->data)
			return 1;
		i++;
		head=head->ptr;
	}
	return 0;
}

int find_height(struct BST *root,int n,int level)
{
	if (root == NULL)
        return 0;
 
    if (root->data == n)
        return level;
 
    int downlevel = find_height(root->left, n, level+1);
    if (downlevel != 0)
        return downlevel;
 
    downlevel = find_height(root->right, n, level+1);
    return downlevel;
}

struct sll * find_nodes(struct BST *root,int level,struct sll * head)
{
	if(root==NULL)
		return head;
	if(level == 1)
	{
		return insert_in_list(root->data,head);
	}
	else
	{
		head=find_nodes(root->left, level-1,head);
		head=find_nodes(root->right, level-1,head);
	}
	return head;
}

struct sll * insert_in_list(int n,struct sll *head)
{
	if(head==NULL)
	{
		head=(struct sll *)malloc(sizeof(struct sll));
		head->data=n;
		head->ptr=NULL;
		//printf("%d ",head->data);
		return head;
	}
	else
	{
		struct sll *temp,*temp1;
		temp=(struct sll *)malloc(sizeof(struct sll));

		temp->data=n;
		temp->ptr=NULL;

		temp1=head;

		while(temp1->ptr!=NULL)
			temp1=temp1->ptr;

		temp1->ptr=temp;

		//printf("%d ",temp->data);

		return head;
	}
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
	int i,*a,n,check=0,level,*output,n1;

	for(i=0;i<15;i++)
	{
		n=testDB[i].n;
		n1=testDB[i].n1;
		a=malloc_int(testDB[i].input,n);
		output=malloc_int(testDB[i].output,n1);
		
		struct BST *root=make_BT(a,0,n-1);

		level=find_height(root,n,1);

		struct sll *head=NULL;

		head=find_nodes(root,level,head);

		check=a_cmp(output,head,n1);

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