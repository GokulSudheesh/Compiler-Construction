#include<stdio.h>
int main()
{
	int i;
	unsigned char c;
	char str[20],**ptr;
	long int***p;
	
	ptr=&(str+2);
	**p=&*&i;
	*(str+2)=c;

}

