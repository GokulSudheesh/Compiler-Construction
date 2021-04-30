%option yylineno

%{
	#include<stdio.h>
	#include<string.h>
	#include"y.tab.h"
	#include<math.h>
%}

%%
[\n]+  {/*new line*/}
[" "]{4} {return TAB;} 
"import" {return IMPORT;}
([a-z]+|[A-Z]+)+["."][h] {strcpy(yylval.var_name,yytext);return HEADER_FILE;}
"if"	{return IF;}
"elif" {return ELSE_IF;}
"else"	{return ELSE;}
"for"	{return FOR;}
"do"	{return DO;}
"while"	{return WHILE;}
"in" {return IN;}
"@" {return AT;}
"set" {return SET;}
"void" {return VOID;}
"int"	{yylval.data_type=0;return INT;}
"char" {yylval.data_type=1; return CHAR;}
"float" {yylval.data_type=2; return FLOAT;}
"double" {yylval.data_type=3; return DOUBLE;}
"return" {return RETURN;}
"print" {return PRINT;}
"println" {return PRINTLN;}
"read" {return SCANF;}
"#" {return HASH;}
"("	{return LB;}
")"	{return RB;}
"{"	{return LCB;}
"}"	{return RCB;}
"[" {return LSQRB;}
"]" {return RSQRB;}
","	{return COMA;}
";"	{return SC;}
":"	{return COLON;}
"?"	{return QMARK;}
"++" {return UPLUS;}
"--" {return UMINUS;}
"^" {return EXP;}
[+] {return PLUS;}
[-] {return MINUS;}
[*] {return MUL;}
[/] {return DIV;}
[%] {return MOD;}
"==" {return ET;}
"is" {return IS;}
"="	{return EQ;}
">" {return GT;}
"<" {return LT;}
">=" {return GTE;}
"<=" {return LTE;}
"!=" {return NE;}
"is not" {return ISNOT;}
"&" {return AMPER;}
"and" {return AND;}
"or" {return OR;}
"!" {return NOT;}
[\"] {return DQUOTE;}
([" "]{4})*\/\/(.*) {/*Single line comment*/};
([" "]{4})*\/\*(.*\n)*.*\*\/  {/*Regular expression for multi line comment*/};	
\"([^\\\"]|\\.)*\" {strcpy(yylval.q_string,yytext); return Q_STRING;}
([A-Z]+|[a-z]+)([A-Z]+|[a-z]+|["_"]+|[0-9]+)* {strcpy(yylval.var_name,yytext);return VAR;}
[0-9]+ {yylval.Number.integer_val = atoi(yytext); strcpy(yylval.Number.code,yytext); return INT_NUMBER;}
[0-9]+(\.[0-9]+) {yylval.Number.float_val = atof(yytext); strcpy(yylval.Number.code,yytext); return FLOAT_NUMBER;}
" "^. {printf("invalid character sequence %s\n",yytext); exit(0);}
%%


int yywrap(void)
{
    return 1;
}
