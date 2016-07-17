#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#pragma warning(disable: 4996)

void testcases1();

void testcases2();

char *malloc_char(char ip[]);

struct sll * convert_to_list(char *);

struct sll * insert_in_list(int,struct sll *);

struct sll * sort012_1(struct sll *);

struct sll * sort012_2(struct sll *);

int ll_cmp(struct sll *,struct ll *);

struct test
{
	char input[44];
	char output[44];
}testDB[10]={{{"2001"},{"0012"}},
			{{"002001"},{"000012"}},
			{{"221"},{"122"}},
			{{"11222111000"},{"00011111222"}},
			{{"2222222222"},{"2222222222"}},
			{{"0"},{"0"}},
			{{"1111"},{"1111"}},
			{{"02021"},{"00122"}},
			{{"00001"},{"00001"}},
			{{""},{""}}};


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

int ll_cmp(struct sll *ihead,struct sll *ohead)
{
	int count=0,count1=0;
	struct sll *temp=ihead;

	while(temp)
	{
		count++;
		temp=temp->ptr;
	}

	while(ihead)
	{
		if(ihead->data==ohead->data)
			count1++;
		ihead=ihead->ptr;
		ohead=ohead->ptr;
	}
	if(count==count1)
		return 0;
	else
		return  1;
}

struct sll * convert_to_list(char a[])
{
	int i=0;
	struct sll *head=NULL;

	while(a[i]!='\0')
	{
		head=insert_in_list(a[i]-'0',head);
		i++;
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

struct sll * sort012_1(struct sll * head)
{
	int count0=0,count1=0,count2=0,i=1,j=1,k=1;

	struct sll *temp=head;

	while(temp!=NULL)
	{
		if(temp->data==0)
			count0++;
		else if(temp->data==1)
			count1++;
		else if(temp->data==2)
			count2++;
		temp=temp->ptr;
	}

	if(count0!=0)
	{
		head->data=0;
		count0--;
		temp=head->ptr;
	}
	else if(count1!=0)
	{
		head->data=1;
		count1--;
		temp=head->ptr;
	}
	else if(count2!=0)
	{
		head->data=2;
		count2--;
		temp=head->ptr;
	}

	while(temp!=NULL)
	{
		if(i<=count0)
		{
			temp->data=0;
			i++;
		}
		else if(j<=count1)
		{
			temp->data=1;
			j++;
		}
		else if(k<=count2)
		{
			temp->data=2;
			k++;
		}
		temp=temp->ptr;
	}
	return head;
}

struct sll * sort012_2(struct sll * head)
{
	struct sll *temp=head,*htemp0=NULL,*ttemp0=NULL,*htemp1=NULL,*ttemp1=NULL,*htemp2=NULL,*ttemp2=NULL,*i;

	while(temp!=NULL)
	{
		if(temp->data==0)
		{
			if(htemp0==NULL)
			{
				htemp0=temp;
				ttemp0=htemp0;
			}
			else
			{
				ttemp0->ptr=temp;
				ttemp0=ttemp0->ptr;
			}
		}
		else if(temp->data==1)
		{
			if(htemp1==NULL)
			{
				htemp1=temp;
				ttemp1=htemp1;
			}
			else
			{
				ttemp1->ptr=temp;
				ttemp1=ttemp1->ptr;
			}
		}
		else if(temp->data==2)
		{
			if(htemp2==NULL)
			{
				htemp2=temp;
				ttemp2=htemp2;
			}
			else
			{
				ttemp2->ptr=temp;
				ttemp2=ttemp2->ptr;
			}
		}
		temp=temp->ptr;
	}
	//for(i=htemp2;i!=ttemp2->ptr;i=i->ptr)
		//printf("%d",i->data);

	if(htemp0!=NULL)
	{
		if(htemp1!=NULL)
		{
			if(htemp2!=NULL)
			{
				ttemp1->ptr=htemp2;
				ttemp2->ptr=NULL;
				ttemp0->ptr=htemp1;
				return htemp0;
			}
			else
			{
				ttemp1->ptr=NULL;
				return htemp0;
			}
		}
		else if(htemp2!=NULL)
		{
			ttemp0->ptr=htemp2;
			ttemp2->ptr=NULL;
			return htemp0;
		}
		else
		{
			ttemp0->ptr=NULL;
			return htemp0;
		}
	}
	else if(htemp1!=NULL)
	{
		if(htemp2!=NULL)
		{
			ttemp1->ptr=htemp2;
			ttemp2->ptr=NULL;
			return htemp1;
		}
		else
		{
			ttemp1->ptr=NULL;
			return htemp1;
		}
	}
	else if(htemp2!=NULL)
	{
		ttemp2->ptr=NULL;
		return htemp2;
	}
}

	
void testcases1()
{
	int i,check;
	char *a,*op;

	for(i=0;i<10;i++)
	{
		struct sll *ihead,*ohead,*j;

		a=malloc_char(testDB[i].input);

		op=malloc_char(testDB[i].output);

		ihead=sort012_1(convert_to_list(a));

		ohead=convert_to_list(op);

		//for(j=ihead;j!=NULL;j=j->ptr)
			//printf("%d ",j->data);

		//for(j=ohead;j!=NULL;j=j->ptr)
			//printf("%d ",j->data);

		check=ll_cmp(ihead,ohead);

		if(check==0)
			printf("passed\n");
		else 
			printf("failed\n");
	}
}
void testcases2()
{
	int i,check;
	char *a,*op;

	for(i=0;i<10;i++)
	{
		struct sll *ihead,*ohead,*j;

		a=malloc_char(testDB[i].input);

		op=malloc_char(testDB[i].output);

		ihead=sort012_2(convert_to_list(a));

		ohead=convert_to_list(op);

		//for(j=ihead;j!=NULL;j=j->ptr)
			//printf("%d ",j->data);

		//for(j=ohead;j!=NULL;j=j->ptr)
			//printf("%d ",j->data);

		check=ll_cmp(ihead,ohead);

		if(check==0)
			printf("passed\n");
		else 
			printf("failed\n");
	}
} 


int main()
{
	printf("1st algorithm:\n");
	testcases1();
	printf("2nd algorithm:\n");
	testcases2();
	getchar();
	return 0;
}
