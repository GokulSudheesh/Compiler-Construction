%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	int yylex(void);
	int yyerror(const char *s);

	int dummy;


	struct symbol_table
	{
	 	char name[30];// variable
		int type;//int only

		//char var;--------> [var_name:=var  |  type:=1] 	
	}var_list[20];

	int var_count=-1;

	int lookup_in_table(char var_name[30]);
	void insert_to_table(char var_name[30], int type);
	int compare(int,int);


	int current_type;//recently seen data type-- int or char--0 or 1

	int type_current=-1;
	int type_so_far=-1;
	int compare(int,int);

%}


%union{//yylval spec, shared memory of size 30 bytes
char test_name[30];//whole memory will be utilized
int type_info;//first 4 bytes will be interpreted as an integer, rest unused
}


%token HEADER MAIN 
%token LB RB LCB RCB SC COMA EQ PLUS STAR

%token<test_name>VAR_LABEL

%token<type_info>INT
%token<type_info>CHAR


%start prm

%%
prm	: HEAD PROC {}

HEAD : HEADER 			{			
					printf("\n From Parser: procesed headr file.. next main... procedure..");
				}

PROC: MAIN_TYPE MAIN LB RB LCB BODY RCB {
							printf("\n From Parser: parsing successful");
					}
MAIN_TYPE : INT	{ 
					printf("\n From Parser: main type parsed");
				}


BODY	: STATEMENTS		{

					printf("\n From Parser:all statements successfully completed");
				}



STATEMENTS	: STATEMENT STATEMENTS
	   	| STATEMENT


STATEMENT	: DECLARATION_STATEMENT {
						printf("\n From Parser: Parsed a declaration statement");
					}

		| PROGRAM_STATEMENT 	{
						printf("\n From Parser: Parsed a program statement");
					}



DECLARATION_STATEMENT: DATA_TYPE VAR_LIST SC {}

DATA_TYPE: INT			{	current_type=$1;
					printf("\n From Parser:parsed \"int\" in input..");
				}

DATA_TYPE: CHAR			{
					current_type=$1;
					printf("\n From Parser:parsed \"int\" in input..");
				}


VAR_LIST : VAR_LABEL COMA VAR_LIST	{
						printf("\n From Parser:parsed variable %s",$1);
						insert_to_table($1,current_type);
			     		}

	 | VAR_LABEL 		{
					printf("\n From Parser:parsed variable %s",$1);
					insert_to_table($1,current_type);				
				}  


PROGRAM_STATEMENT : VAR_LABEL EQ A_EXPN SC {

				type_current=lookup_in_table($1);
				if(type_current!=-1)
				{
					if(compare(type_so_far,type_current)==-1)
					{
						printf("\ntype mismatch in the expression\n");
						exit(0);
					}
				}else
				{
					printf("\n variable \"%s\" undeclared\n",$1);exit(0);
				}
				type_so_far=-1;
			     }



A_EXPN		:A_EXPN PLUS A_EXPN
		|A_EXPN STAR A_EXPN
		| LB A_EXPN RB 
		| VAR_LABEL {
				printf("\n From parser: exploring %s current type=%d type so far=%d",$1,type_current,type_so_far);
				type_current=lookup_in_table($1);
				if(type_current!=-1)
				{
					if(type_so_far==-1)
					{
						type_so_far=type_current;
					}else if(compare(type_so_far,type_current)==-1)
					{
						printf("\ntype mismatch in the expression\n");
						exit(0);
					}
				}else
				{
					printf("\n variable \"%s\" undeclared\n",$1);exit(0);
				}
			     }


%%  

int lookup_in_table(char var_name[30])
{
	for(int i=0;i<=var_count;i++)
	{
		if((strcmp(var_list[i].name,var_name)==0))
		{
			return var_list[i].type;
		}
	}
	return -1;
}

void insert_to_table(char var_name[30], int type)
{
	for(int i=0;i<=var_count;i++)
	{
		if(strcmp(var_list[i].name,var_name)==0)
		{
			printf("\n multiple declaration of variable \"%s\"\n", var_name);
			exit(0);

		}
	}
	strcpy(var_list[++var_count].name,var_name);
	var_list[var_count].type=type;


	printf("\n From parser: Inserted %s,%d   to table",var_name,type);

						printf("\n ------SYMBOL TABLE-------");
						printf("\n | VARIABLE       DATA TYPE |");
						for(int i=0;i<=var_count;i++)
						{
							printf("\n |   %s             %d     |", var_list[i].name,var_list[i].type);

						}
						printf("\n -------------------------");
	

}

int compare(int t1,int t2)
{
	if(t1==t2)
	{
		return 1;
	}
	else return 0;
}


  
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

