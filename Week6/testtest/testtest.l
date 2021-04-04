%option yylineno

%{
	#include<stdio.h>
	#include<string.h>
	#include"y.tab.h"
	#include<math.h>
	extern int var_count;

%}

%%
"include" {return INCLUDE; }
"int"	{yylval.data_type=0;return INT;}
"char" {yylval.data_type=1; return CHAR;}
"double" {yylval.data_type=2; return DOUBLE;}
"float" {yylval.data_type=3; return FLOAT;}
"main" {return MAIN;}
([a-z]+|[A-Z]+)+["."][h] {return HEADER_FILE;}
".h" {return DOTH; }
".c" {return DOTC; }
"#" {return HASH; }
"("	{return LB;}
")"	{return RB;}
"{"	{return LCB;}
"}"	{return RCB;}
"[" {return LSB;}
"]" {return RSB;}
","	{return COMMA;}
";"	{return SC;}
"++" {return UPLUS;}
"--" {return UMINUS;}
"^" {return EXP;}
"?" {return QUESM;}
":" { return COLON; }
"*" {return STAR;}
"&" {return AMPERSAND;}
\/\/(.*) {return COMMENT; }
[+] {return PLUS;}
[-] {return MINUS;}
"%" {return MOD;}
[/] {return DIV;}
"==" {return EQCOMPARE;}
"!=" {return NEQCOMPARE;}
"="	{return EQ;}
">=" {return GTE;}
"<=" {return LTE;}
">" {return GT;}
"<" {return LT;}
"!" {return NOT;}
"&&" {return AND;}
"||" {return OR;}
"if" {return IF;}
"else" {return ELSE;}
"for" {return FOR; }
"while" {return WHILE;}
"do" {return DO; }
[\"] {return DOUBLEQ; }
[a-z]+  {strcpy(yylval.var_name,yytext);return VAR;}
[1-9][0-9]* {yylval.num_int = atoi(yytext); return NUMINT; }
[0]  		{yylval.num_int = atoi(yytext); return NUMINT; }
[\n\t ]+  {/*new line or space*/}
. {printf("invalid character sequence %s\n",yytext); exit(0);}
%%


int yywrap(void)
{
    return 1;
}
