#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define NULL 0

struct llist
{
	int val;
	int count;
	struct llist *next;
};
typedef struct llist node;
node *head;
void insertfirst(int);
void display(node *);
void main()
{
	int n,i,max,*a;
	node *temp2,*maxnode;
	clrscr();
	printf("enter no of elements\n");
	scanf("%d",&n);
	a=(int *)malloc(n);
	temp2=(node *)malloc(sizeof(node));
	maxnode=(node *)malloc(sizeof(node));
	head=(node *)malloc(sizeof(node));
	head=NULL;


	for(i=1;i<=n;i++)
	{
	scanf("%d",&a[i]);
	insertfirst(a[i]);
	}
	display(head);
	max=head->count;
	temp2=head;
	maxnode=temp2;
	while(temp2!=NULL)
	{
		if(temp2->count>max)
		{
		maxnode=temp2;
		max=temp2->count;

		}
		temp2=temp2->next;
	}
	printf("max occurd element is %d",maxnode->val);


	getch();
}
void insertfirst(int x)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp=head;
	while(temp!=NULL)
	{
	if(x!=temp->val)
	temp=temp->next;
	else
	{
	temp->count++;
	break;
	}
	}
	if(temp==NULL)
	{
	node *current=(node *)malloc(sizeof(node));
	current->next=head;
	head=current;
	head->val=x;
	head->count=1;
	}


}
void display(node *head)
{
	node *temp=(node *)malloc(sizeof(node));
	temp=head;
	while(temp!=NULL)
	{
		printf("(%d,%d)-->",temp->val,temp->count);
		temp=temp->next;
	}

}