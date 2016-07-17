#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#pragma warning(disable: 4996)

void testcases();

char *malloc_char(char ip[]);

struct sll * convert_to_list(char *);

struct sll * insert_in_list(int,struct sll *);

struct sll * adder(struct sll *,struct sll *);

int length(struct sll *);

int store(struct sll *,int);

struct sll * add(struct sll *,struct sll *,int);

int ll_cmp(struct sll *,struct ll *);

struct test
{
	char input1[44];
	char input2[44];
	char output[44];
}testDB[10]={{{"365"},{"248"},{"613"}},
			{{"343"},{"965"},{"1308"}},
{{"221"},{"122"},{"343"}},
{{"321"},{"654"},{"975"}},
{{"000"},{"321"},{"321"}},
{{"321"},{"9"},{"330"}},
{{"329"},{"88"},{"417"}},
{{"02021"},{""},{"02021"}},
{{"1"},{"00001"},{"00002"}},
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

		temp->ptr=head;
		head=temp;

		//printf("%d ",temp->data);

		return head;
	}
}

int length(struct sll * head)
{
	int len=0;

	struct sll *temp=head;

	while(temp!=NULL)
	{
		temp=temp->ptr;
		len++;
	}
	return len;
}

struct sll * adder(struct sll * ahead,struct sll * bhead)
{
	if(length(ahead) >= length(bhead))
		return add(ahead,bhead,0);
	else
		return add(bhead,ahead,0);
}

struct sll * add(struct sll *ahead,struct sll *bhead,int cary)
{
	int sum;

	struct sll *atemp=ahead,*btemp=bhead,*chead=atemp,*ctemp=chead;

	while(atemp!=NULL)
	{
		if(btemp!=NULL)
		{
			if(atemp==ahead)
			{
				sum=(atemp->data)+(btemp->data);

				if(ctemp->ptr==NULL)
				{
					ctemp->data=sum;
					break;
				}
				cary=store(chead,sum);
			}
			else
			{
				sum=(atemp->data)+(btemp->data)+cary;

				if(ctemp->ptr==NULL)
				{
					if(sum<10)
					{
						ctemp->data=sum;
					}
					else
					{
						ctemp->data=sum%10;

						struct sll *temp;
						temp=(struct sll *)malloc(sizeof(struct sll));
						temp->data=sum/10;
						temp->ptr=NULL;
						ctemp->ptr=temp;
						free(temp);
					}
					break;
				}
				cary=store(ctemp,sum);
			}
			btemp=btemp->ptr;
		}
		else
		{
			sum=(atemp->data)+cary;
			cary=store(ctemp,sum);
		}
		atemp=atemp->ptr;
		ctemp=ctemp->ptr;
	}
	return chead;
}

int store(struct sll *temp,int sum)
{
	int cary=0;

	if(sum<10)
	{
		temp->data=sum;
	}
	else
	{
		temp->data=sum%10;
		cary=sum/10;
	}
	return cary;
}

	
void testcases()
{
	int i,check;
	char *a,*op,*b;

	for(i=0;i<10;i++)
	{
		struct sll *ohead,*ihead,*j;

		a=malloc_char(testDB[i].input1);
		b=malloc_char(testDB[i].input2);

		op=malloc_char(testDB[i].output);

		ihead=adder(convert_to_list(a),convert_to_list(b));

		ohead=convert_to_list(op);

		for(j=ihead;j!=NULL;j=j->ptr)
			printf("%d ",j->data);

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
	testcases();
	getchar();
	return 0;
}
