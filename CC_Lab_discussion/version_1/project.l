%option yylineno
%{
	#include<stdio.h>
	#include<string.h>
	#include"y.tab.h"
	#include<math.h>
	extern int var_count;
	int dummy;
	int ln=0;
%}
%%
"#include<stdio.h>" {
			printf("\n          From LA: have consumed \"%s\" from the input file",yytext);
			return HEADER;
		    }

"int"	{
		yylval.type_info=0;
		printf("\n          From LA: have consumed \"%s\" from the input file",yytext);
		return INT;
	}


"char"	{
		yylval.type_info=1;
		printf("\n          From LA: have consumed \"%s\" from the input file",yytext);
		return CHAR;
	}


"unsigned"	{
		yylval.type_info=1;
		printf("\n          From LA: have consumed \"%s\" from the input file",yytext);
		return UNSIGNED;
	}
"short"	{
		yylval.type_info=1;
		printf("\n          From LA: have consumed \"%s\" from the input file",yytext);
		return SHORT;
	}
"long"	{
		yylval.type_info=2;
		printf("\n          From LA: have consumed \"%s\" from the input file",yytext);
		return LONG;
	}



"main"	{
		printf("\n          From LA: have consumed \"%s\" from the input file",yytext);
		return MAIN;
	}


"("	{
		printf("\n          From LA: have consumed \"%s\" from the input file",yytext);
		return LB;
	}

")"	{
		printf("\n          From LA: have consumed \"%s\" from the input file",yytext);
		return RB;
	}

"{"	{
		printf("\n          From LA: have consumed \"%s\" from the input file",yytext);
		return LCB;
	}

"}"	{
		printf("\n          From LA: have consumed \"%s\" from the input file",yytext);
		return RCB;
	}

";"	{
		printf("\n          From LA: have consumed \"%s\" from the input file",yytext);
		return SC;
	}
","	{
		printf("\n          From LA: have consumed \"%s\" from the input file",yytext);
		return COMA;
	}

"="	{
		printf("\n          From LA: have consumed \"%s\" from the input file",yytext);
		return EQ;
	}

"++"	{
		printf("\n          From LA: have consumed \"%s\" from the input file",yytext);
		return UPLUS;
	}

"+"	{
		printf("\n          From LA: have consumed \"%s\" from the input file",yytext);
		return PLUS;
	}
"*"	{
		printf("\n          From LA: have consumed \"%s\" from the input file",yytext);
		return STAR;
	}
"&"	{
		return AMB;
	}

"[" {return LSB;}
"]" {return RSB;}
[0-9]+ {return NUM;}
[a-z][A-Za-z0-9]*  {
		strcpy(yylval.test_name,yytext);
		printf("\n          From LA: have consumed \"%s\" from the input file",yytext);
		return VAR_LABEL;
	}
[\t ]+  {/*new line or space*/}
[\n]	{printf("\n New line:%d",ln++);}
. 	{
		printf("\n          From LA:invalid character sequence %s\n",yytext); 
		exit(0);
	}
%%


int yywrap(void)
{
    return 1;
}
