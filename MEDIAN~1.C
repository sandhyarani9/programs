#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void display(int x,int *y);
void main()
{
int *a,*b;
int i,n1,n2,n3,j,temp;
printf("enter first array size\n");
scanf("%d",&n1);
printf("second array size");
scanf("%d",&n2);
n3=n1+n2;
printf("\nenter %d elements in an order",n1);
a=(int *)malloc(n1*sizeof(int));
b=(int *)malloc(n3*sizeof(int));
for(i=0;i<n1;i++)
scanf("%d",&a[i]);
printf("\n enter %d elements in an order",n2);
for(j=0;j<n2;j++)
scanf("%d",&b[j]);
display(n2,b);
display(n1,a);
printf("\n\n");
temp=n3;
n1--;
n2--;
n3--;
while(n1>=0&&n2>=0)
{
    if(a[n1]>b[n2])
	{
	b[n3--]=a[n1--];
	}
	else
	{
	b[n3--]=b[n2--];
	}
}
	if(n2==-1)
	{
	while(n1>=0)
	{
	b[n3--]=a[n1--];
	}
	}
    else
    while(n2>=0)
    {
	b[n3--]=b[n2--];
	}
	display(temp,b);
	if(temp%2==0)
	printf("median is %f",(float)(b[temp/2]+b[(temp/2)-1])/2);
	else
	printf("median is %d",b[temp/2]);

getch();
}
void display(int n,int *y)
{
 int i;
printf("array elements");
for(i=0;i<n;i++)
printf("%d,",y[i]);
}