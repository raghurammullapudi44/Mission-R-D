#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#pragma warning(disable: 4996)

void testcases();

char *malloc_char(char ip[]);

struct dll * convert(char *);

struct sll * insert(int,struct sll *);

struct dll * convert_dll(struct sll *);

int ll_cmp(char *,struct dll *);

struct test
{
	char input[44];
}testDB[13]={"12345678","01234","4444","001234","123400","00000","12340056","1","0","101011","","\0","11"};

struct sll
{
	int data;
	struct sll *ptr;
};

struct dll
{
	int data;
	struct dll *right;
	struct dll *left;
};

char * malloc_char(char ip[])
{
	int i;
	char *a;
	a=(char *)malloc(sizeof(char)*1);
	for(i=0;ip[i]!='\0';i++)
	{
		a=(char *)realloc(a,sizeof(char)*(i+1));
		a[i]=ip[i];
	}
	a[i]='\0';
	return a;
}

int ll_cmp(char a[],struct dll *head)
{
	int count=0,i=0;

	while(a[i]!=0)
	{
		if(head->data==(a[i]-'0'))
			count++;

		head=head->right;
		i++;
	}
	if(count==strlen(a))
		return 0;
	else 
		return 1;
}

struct dll * convert(char a[])
{
	int i=0;
	struct sll *head=NULL;

	while(a[i]!='\0')
	{
		head=insert(a[i]-'0',head);
		i++;
	}

	return convert_dll(head);
}

struct dll * convert_dll(struct sll *head)
{
	struct dll *head1=NULL,*temp,*temp1=NULL;

	while(head != NULL)
	{
		if(head1==NULL)
		{
			head1=(struct dll *)malloc(sizeof(struct dll));
			head1->data=head->data;
			head1->right=NULL;
			head1->left=NULL;
			temp1=head1;
		}
		else
		{
			temp=(struct dll *)malloc(sizeof(struct dll));
			temp->data=head->data;
			temp->left=NULL;
			temp->right=NULL;

			temp1->right=temp;
			temp1=temp1->right;
		}
		head=head->ptr;
	}
	return head1;
}

struct sll * insert(int n,struct sll *head)
{
	if(head==NULL)
	{
		head=(struct sll *)malloc(sizeof(struct sll));
		head->data=n;
		head->ptr=NULL;
		return head;
		//printf("%d ",head->data);
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

		return head;

		// printf("%d ",temp->data);
	}
}

	
void testcases()
{
	int i,check;
	char *a;

	for(i=0;i<13;i++)
	{
		a=malloc_char(testDB[i].input);
		
		check=ll_cmp(a,convert(a));

		if(check==0)
			printf("passed\n");
		else 
			printf("failed\n");
	}
}

int main()
{
	testcases();
	getchar();
	return 0;
}
