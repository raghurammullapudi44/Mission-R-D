#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#pragma warning(disable: 4996)

void testcases();

char *malloc_char(char ip[]);

int convert_to_list(char *);

struct sll * insert_in_list(int,struct sll *);

int find_median(struct sll *);

int ll_median_cmp(int,int);

struct test
{
	char input[44];
	int median;
}testDB[10]={{"12345678",5},
	{"0123456",3},
	{"11111111",1},
	{"22225678",5},
	{"222245678",4},
	{"0001",0},
	{"876542222",4},
	{"87652222",2},
	{"87654321",4},
	{"6543210",3}};

struct sll
{
	int data;
	struct sll *ptr;
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

int ll_median_cmp(int a,int b)
{
	if(a==b)
		return 0;
	else
		return 1;
}

int convert_to_list(char a[])
{
	int i=0;
	struct sll *head=NULL;

	while(a[i]!='\0')
	{
		head=insert_in_list(a[i]-'0',head);
		i++;
	}

	return find_median(head);
}

int find_median(struct sll * head)
{
	struct sll *temp=head,*median=head;
	int count=0;

	while(temp)
	{
		if((count%2)!=0)
			median=median->ptr;
		temp=temp->ptr;
		count++;
	}
	return median->data;
}

struct sll * insert_in_list(int n,struct sll *head)
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
	int i,check,median;
	char *a;

	for(i=0;i<10;i++)
	{
		a=malloc_char(testDB[i].input);

		median=testDB[i].median;
		
		check=ll_median_cmp(median,convert_to_list(a));

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
