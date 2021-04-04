%{
	#include<stdio.h>
	int yyerror();
	int val=0;
%}
%token NUMBER
%start X
%%
X:	Y {val=$1;}
Y:    NUMBER Y{$$=$1+$2;}
	| NUMBER {$$=$1;}
%%
void main()
{
	yyparse();
	printf("Value=%d",val);
}
int yyerror()
{
	printf("\n Invalid Input\n");
}