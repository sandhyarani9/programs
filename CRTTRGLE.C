#include<stdio.h>
#include<math.h>
#include<conio.h>
float x1,y1,x2,y2,x3,y3;
float a,b,c;
int istriangle(float,float,float);
int isequilateral();
int isrightangle(float,float,float);
int isisosceles();
float slope(float,float,float,float);

void main()
{
	float m1,m2,m3;
	clrscr();
	printf("enter coordinates,press enter after entering one coordinate\n");
	scanf("%f %f\n%f %f\n%f %f",&x1,&y1,&x2,&y2,&x3,&y3);
	m1=slope(x1,x2,y1,y2);
	m2=slope(x2,x3,y2,y3);
	m3=slope(x1,x3,y1,y3);
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	printf("%f\t%f\t%f",a,b,c);

	if(istriangle(m1,m2,m3))
	{
		printf("the coordinates forms a triangle\n");
		if(isequilateral())
		{
		printf("It is an equilateral triangle of side %d\n",a);
		}
		else if(isrightangle(m1,m2,m3))
		{
		if(isisosceles())
		printf("It is a right angled isosceles triangle\n");
			else
		printf("It is a right angle triangle\n");
		}
		else if(isisosceles())
		printf("It is a isosceles triangle\n");
		else
		printf("It is a miscillenous triangle\n");
	}
	else
	printf("The coordinates don't form a triangle\n");
	getch();
}
float slope(float x1,float x2,float y1,float y2)
{
	float m1;
	if((x2-x1)!=0)
	{

	m1=((y2-y1)/(x2-x1));

	}
	else
	{

	m1=9999;
	}
	return m1;
}
int istriangle(float m1,float m2,float m3)
{
	if(m1==m2||m2==m3||m1==m3)
	return 0;
	else
	return 1;
}
int isequilateral()
{
	if(a==b&&b==c)
	return 1;
	else
	return 0;
}
int isrightangle(float m1,float m2,float m3)
{
	if(ceil(m1*m2)==-1)
	return 1;
	else if(ceil(m2*m3)==-1)
	return 1;
	else if(ceil(m3*m1)==-1)
	return 1;
	else if(m1==9999||m2==9999||m3==9999)
	       {
	       if(m1==0||m2==0||m3==0)
	       return 1;
	       }
	return 0;

}
int isisosceles()
{
	if(a==b||b==c||c==a)
	return 1;
	else
	return 0;
}
