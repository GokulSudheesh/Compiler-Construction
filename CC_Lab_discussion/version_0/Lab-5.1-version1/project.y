%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	int yylex(void);
	int yyerror(const char *s);

	int dummy;
%}


%union{//yylval spec, shared memory of size 30 bytes
char test_name[30];//whole memory will be utilized
int type_info;//first 4 bytes will be interpreted as an integer, rest unused
}
%token HEADER MAIN 
%token LB RB LCB RCB SC COMA 

%token<test_name>VAR_LABEL

%token<type_info>INT

%start prm

%%
prm	: HEAD PROC {}

HEAD : HEADER 			{			
					printf("\n From Parser: procesed headr file.. next main procedure..");
		//			scanf("%d",&dummy); 
				}

PROC: MAIN_TYPE MAIN LB RB LCB BODY RCB {
							printf("\n From Parser: parsing successful");getchar();
		//					scanf("%d",&dummy); 
					}
MAIN_TYPE : INT 		{}


BODY	: STATEMENTS		{
					printf("\n From Parser:all statements successfully completed");
		//			scanf("%d",&dummy); 
				}



STATEMENTS	: STATEMENT STATEMENTS
	   	| STATEMENT


STATEMENT	: DECLARATION_STATEMENT {
						printf("\n From Parser: Parsed a declaration statement");
	//					scanf("%d",&dummy); 
					}



DECLARATION_STATEMENT: DATA_TYPE VAR_LIST SC {}

DATA_TYPE: INT			{
					printf("\n From Parser:parsed \"int\" in input..");
	//				scanf("%d",&dummy); 
				}


VAR_LIST : VAR_LABEL COMA VAR_LIST	{
						printf("\n From Parser:parsed variable %s",$1);
						scanf("%d",&dummy); 
			     		}

	 | VAR_LABEL 		{
					printf("\n From Parser:parsed variable %s",$1);
	//				scanf("%d",&dummy); 
				}  

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
	return 0;
}

