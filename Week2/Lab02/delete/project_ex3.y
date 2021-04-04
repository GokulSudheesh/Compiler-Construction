%{
	#include<stdio.h>
	#include<stdlib.h>
	int yylex(void);
	int yyerror(const char *s);
	int success = 1;
%}

%token HEADER INT FLOAT DOUBLE CHAR MAIN LB RB LCB RCB SC COMA KEY VAR EQ OP
%start prm

%%
prm	: HEADER INT MAIN LB RB LCB BODY RCB {printf("\n parsing successful\n");}
BODY	: DECLARATION_STATEMENTS PROGRAM_STATEMENTS
DECLARATION_STATEMENTS : DECLARATION_STATEMENT DECLARATION_STATEMENTS {printf("\n Declaration section successfully parsed\n");}
			| DECLARATION_STATEMENT
PROGRAM_STATEMENTS : PROGRAM_STATEMENT PROGRAM_STATEMENTS {printf("\n program statements successfully parsed\n");}
			| PROGRAM_STATEMENT
DECLARATION_STATEMENT:INT VAR_LIST SC | FLOAT VAR_LIST SC | DOUBLE VAR_LIST SC | CHAR VAR_LIST SC | INT KEYWORDS SC {printf("Keyword cannot be used as variable."); exit(0);} 
			| FLOAT KEYWORDS SC {printf("Keyword cannot be used as variable."); exit(0);} | DOUBLE KEYWORDS SC {printf("Keyword cannot be used as variable."); exit(0);} | CHAR KEYWORDS SC {printf("Keyword cannot be used as variable."); exit(0);}
KEYWORDS : KEY COMA KEYWORDS | KEY
VAR_LIST : VAR COMA VAR_LIST {printf("\n variable list successfully parsed\n");} | VAR {}
PROGRAM_STATEMENT : VAR EQ A_EXPN SC {} | KEY EQ A_EXPN SC {printf("Keyword cannot be used as variable."); exit(0);}
A_EXPN		: A_EXPN OP A_EXPN
		| LB A_EXPN RB 
		| VAR
%%

int main()
{
    yyparse();
/*    if(success)
    	printf("Parsing Successful\n");*/
    return 0;
}

int yyerror(const char *msg)
{
	extern int yylineno;
	printf("Parsing Failed\nLine Number: %d %s\n",yylineno,msg);
	success = 0;
	return 0;
}

