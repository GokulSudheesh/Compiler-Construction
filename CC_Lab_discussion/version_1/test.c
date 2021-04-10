#include<stdio.h>
int main()
{
	int a[10][20][30]={0};
	int (*p)[10][20][30]=&a;
	int (*q)[30]=(a+5)[3];
//	p=a;
	int i;
//	i=(*p)[3][5];
//	(*p)[2]=&a[5];
//	printf("%d %d",(p[0]+3)[2][5],(*q)[4]);

}

