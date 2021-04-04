#include<stdio.h>
#include"string.h"
int main()
{
	int i;
	char c;
	char str[20],**ptr;
	int***p;
	
	ptr=&str;
	**p=&i;
	*(str+2)=c;//have to handle pointer arithmetic involving numbers

}

