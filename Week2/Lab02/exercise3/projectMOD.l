%option yylineno

%{
	#include<stdio.h>
	#include"y.tab.h"
	#include<math.h>
%}

%%
"#include<stdio.h>" {return HEADER;}
"int"	{return INT;}
"float" {return FLOAT;}
"double" {return DOUBLE;}
"char" {return CHAR;}
"main"	{return MAIN;}
"("	{return LB;}
")"	{return RB;}
"{"	{return LCB;}
"}"	{return RCB;}
","	{return COMA;}
";"	{return SC;}
[\+\-\*\/] {return OP;}
"="	{return EQ;}
"if"|"while"|"do"|"for" {return KEY;}
([A-Z]+|[a-z]+)([A-Z]+|[a-z]+|[0-9]+)*  {return VAR;}
[\n\t ]+  {/*new line or space*/}
. {printf("invalid character sequence %s\n",yytext); exit(0);}
%%


int yywrap(void)
{
    return 1;
}
