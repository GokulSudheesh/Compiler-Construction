%{
	#include<stdio.h>
	#include<math.h>
%}

%%
"#include<stdio.h>" {printf("HEADER");}
"int"	{printf("INT");}
"float" {printf("FLOAT");}
"double" {printf("DOUBLE");}
"char" {printf("CHAR");}
"main"	{printf("MAIN");}
"("	{printf("LB");}
")"	{printf("RB");}
"{"	{printf("LCB");}
"}"	{printf("RCB");}
","	{printf("COMA");}
";"	{printf("SC");}
[\+\-\*\/] {printf("OP");}
"="	{printf("EQ");}
"if"|"while"|"do"|"for" {printf("KEY");}
([A-Z]+|[a-z]+)([A-Z]+|[a-z]+|[0-9]+)*   {printf("VAR");}
[\n\t ]+  {/*new line or space*/}
. {printf("invalid character sequence %s\n",yytext); exit(0);}
%%


main(){
	yylex();
}
