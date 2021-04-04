#include<stdio.h>
#include<string.h>
int main()
{
	int i;
	char str[20];
	int a[20][30][40];
	int prelength;
	for (i=0;i<prelength;i++)
	{
		str[i]=str[i]+i;
	}
	for (i=0;i<prelength;i++)
	{
		a[i][i][i]=i;
	}
	for (i=0;i<prelength;i++)
	{
		a[i][i][i]=a[i][i][i]*a[i][i][i];
	}
	
}

