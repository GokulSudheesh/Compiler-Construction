%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	int yylex(void);
	int yyerror(const char *s);

	int dummy;

	struct extended_type  t;//try adding this definition to action part

	struct symbol_table
	{
	 	char name[30];// variable
		int pointer_depth;//upper bound on the depth of the reference (pointer to pointer to pointer (int***)--> depth 3, pointer to pointer (int**)--> depth 2, pointer (int*)--> depth 1, normal variable-->depth 0)



		int type;//int or char
		int type_extension;//0-no type extension 1-short or 2-long
		int type_sign;//o- no sign 1-unsigned
		//unsigned long int***var;--------> |var_name:=var|type:=0|type_extension=2|type_sign=1|pointer_depth=3| 	
	}var_list[20];



	/**structure defining extending**/
	struct extended_variable
	{
	 		char name[30];// variable
		        int  pointer_depth;
	};


	struct extended_type
	{
		int name;
		int is_unsigned;
		int length_spec;
	};


	typedef struct expression_type
	{
		int  data_depth;
		int type;
		int isValue;
	}exprn_type;
		

	struct extended_type temp_type_obj;
	struct extended_variable temp_var;	


	int var_count=-1;



	int current_type;//recently seen data type-- int or char--0 or 1

	int type_current=-1;
	int type_so_far=-1;

	void lookup_in_table(char var_name[30],exprn_type*ptr);

	void insert_to_table(struct extended_variable var_obj, struct extended_type type_obj);
%}


%union{//yylval spec, shared memory of size 30 bytes
	char test_name[30];//whole memory will be utilized
	int type_info;//first 4 bytes will be interpreted as an integer, rest unused
	int ptr_depth;//first 4 bytes will be interpreted as an integer, rest unused

	struct
	{
		char name[30];// variable
		int pointer_depth;
	}ext_var;


	struct 
	{
			int name;
			int is_unsigned;
			int length_spec;
	}ext_type;



	struct 
	{
		int  data_depth;
		int type;
		int isValue;
	}expn_type;

}


%token HEADER MAIN 
%token LB RB LCB RCB SC COMA EQ PLUS STAR LSB RSB UPLUS

%token<test_name>VAR_LABEL

%token<type_info>INT
%token<type_info>CHAR

%token<type_info>UNSIGNED
%token<type_info>SHORT
%token<type_info>LONG
%token AMB
%token NUM

%type<ext_var>EXT_VAR


%type<type_info>TYPE
%type<type_info>TYPE_EXTN
%type<type_info>TYPE_SIGN

%type<ext_type>EXT_DATA_TYPE


%type<type_info>STAR_SEQ
%type<type_info>DIM_SEQ

%type<expn_type>A_EXPN

%left PLUS
%left STAR
%left UPLUS
%right AMB
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



DECLARATION_STATEMENT: EXT_DATA_TYPE VAR_LIST SC {}


EXT_DATA_TYPE : TYPE_SIGN TYPE_EXTN TYPE {
			$$.is_unsigned=temp_type_obj.is_unsigned=$1;
			$$.length_spec=temp_type_obj.length_spec=$2;
			$$.name=temp_type_obj.name=$3;
			} 
TYPE:INT {$$=$1;}
	|CHAR {$$=$1;}

TYPE_SIGN:UNSIGNED {$$=$1;}
	| {$$=0;}

TYPE_EXTN:SHORT {$$=$1;}
	|LONG {$$=$1;}
| 	{$$=0;}






VAR_LIST :EXT_VAR COMA VAR_LIST	{
						temp_var.pointer_depth=$1.pointer_depth;;
						strcpy(temp_var.name,$1.name);
						insert_to_table(temp_var,temp_type_obj);
		    		}

	 |EXT_VAR 		{
						temp_var.pointer_depth=$1.pointer_depth;;
						strcpy(temp_var.name,$1.name);
						insert_to_table(temp_var,temp_type_obj);
				} 


EXT_VAR: STAR_SEQ VAR_LABEL DIM_SEQ {        
			        strcpy($$.name,$2);
				$$.pointer_depth=$1+$3;
				
		      }
DIM_SEQ:DIM DIM_SEQ{$$=$2+1;printf("\n [] depth=%d",$$);}
	|  {$$=0;printf("\n [] depth=%d",$$);}

STAR_SEQ:STAR STAR_SEQ	{$$=$2+1;printf("\n pointer depth=%d",$$);}
	|  {$$=0;printf("\n pointer depth=%d",$$);}


DIM:LSB NUM RSB  {printf("\n Found [NUMBER]");}

PROGRAM_STATEMENT : A_EXPN EQ A_EXPN SC 
				{
					if($1.type!=$3.type)
					{
						printf("\n Incompatible type in assignment");
						exit(0);
					}else if($1.data_depth!=$3.data_depth)
					{
						printf("\n Incompatible pointer type in assignment");
						exit(0);
					}
					else if($1.isValue==1)
					{
						printf("\n lvalue required as left operand of the assignment operator");
						exit(0);
					}	
				}



A_EXPN		:A_EXPN PLUS A_EXPN 		
				{	
					$$.isValue=1;
					if($1.data_depth==$3.data_depth)
					{
						$$.data_depth=$1.data_depth;
						if($1.type==$3.type)
						{
							$$.type=$1.type;
						}else
						{
							printf("\n Type mismatch in operands");
							exit(0);	
						}
					}
					else if($1.data_depth==0)
					{	
						if($1.type==0)
						{	$$.data_depth=$3.data_depth;
							$$.type=$3.type;
						}
					}
					else if($3.data_depth==0)
					{	
						if($3.type==0)
						{	$$.data_depth=$1.data_depth;
							$$.type=$1.type;
						}
					}
					else
					{
						printf("\n Type mismatch in dereferencing operands");
						exit(0);						
					}
				}

		|A_EXPN STAR A_EXPN 
				{
					if($1.type!=$3.type)
					{printf("\n Type mismatch in operands");exit(0);}
					if($1.data_depth!=0 || $3.data_depth!=0)
					{
						printf("\n Invalid operands to binary *");exit(0);	
					}	
					$$.isValue=1;
					$$.data_depth=0;
					$$.type=$1.type;	
				}
		|LB A_EXPN RB 	{
					$$.type=$2.type;
					$$.data_depth=$2.data_depth;	
					$$.isValue=$2.isValue;	
				}

		|A_EXPN UPLUS 	{
					if($$.isValue==1)
					{
						printf("\n lvalue required");exit(0);
					}else
					{
						$$.type=$1.type;
						$$.data_depth=$1.data_depth;	
						$$.isValue=1;	
					}
				}
				
		| VAR_LABEL	{		
					exprn_type t;
					lookup_in_table($1,&t);
					if(t.type==-1)
					{
						printf("\n variabla %s undeclared",$1);
						exit(0);
					}
					$$.type=t.type;
					$$.data_depth=t.data_depth;	
					$$.isValue=0;						
				}
			   
		|NUM		{				
					$$.type=0;
					$$.data_depth=0;	
					$$.isValue=1;	
				}
			
		|  STAR A_EXPN %prec  UPLUS	
				{
					if($2.data_depth==0)
					{
						printf("\n Invalid operand to unary \'*\' operator");
						exit(0);
					}
					else
					{
						$$.type=$2.type;
						$$.data_depth=$2.data_depth-1;
						$$.isValue=0;
					}										
				}

		| A_EXPN LSB A_EXPN RSB %prec  UPLUS
				{	
					if($3.data_depth!=0 || $3.type!=0)
					{
						printf("\n Array index integer expected\n");
						exit(0);
					}
					else if($1.data_depth==0)
					{
						printf("\n Subscripted value neither array nor pointer");
						exit(0);
					}
					else
					{
						$$.type=$1.type;
						$$.data_depth=$1.data_depth-1;
						$$.isValue=0;
					}

				}
				
		| AMB A_EXPN	{		if($2.isValue==1)
						{
							printf("\n lvalue required for unary operator &");
							exit(0);
						}
						$$.type=$2.type;
						$$.data_depth=$2.data_depth+1;
						$$.isValue=1;						
				}

		;
%%  


void lookup_in_table(char var_name[30],struct expression_type*temp)
{

	for(int i=0;i<=var_count;i++)
	{
		if(strcmp(var_list[i].name,var_name)==0)
		{
			
			temp->type=var_list[i].type;
			temp->data_depth=var_list[i].pointer_depth;
			return;
		}
	}
	temp->type=-1;
	return;

}

void insert_to_table(struct extended_variable var_obj, struct extended_type type_obj)
{
	for(int i=0;i<=var_count;i++)
	{
		if(strcmp(var_list[i].name,var_obj.name)==0)
		{
			printf("\n multiple declaration of variable \"%s\"\n", var_obj.name);
			exit(0);

		}
	}
	strcpy(var_list[++var_count].name,var_obj.name);
	var_list[var_count].pointer_depth=var_obj.pointer_depth;

	var_list[var_count].type=type_obj.name;
	var_list[var_count].type_sign=type_obj.is_unsigned;
	var_list[var_count].type_extension=type_obj.length_spec;



	printf("\n From parser: Inserted %s,%d",var_obj.name,type_obj.name);
						printf("\n ---------------------------SYMBOL TABLE---------------------------");
						printf("\n |VARIABLE	POINTER DEPTH 	DATATYPE	SIGNED	SHORT/LONG|");
						for(int i=0;i<=var_count;i++)
						{
							printf("\n |   %-10s          %-2d         %-2d            %-2d          %-2d  |", var_list[i].name,var_list[i].pointer_depth,var_list[i].type, var_list[i].type_sign, var_list[i].type_extension);

						}
						printf("\n ------------------------------------------------------------------");
	

}

  
int main()
{
    yyparse();
/*    if(success)
    	printf("\n Parsing Successful\n");*/
    return 0;
}

int yyerror(const char *msg)
{
	extern int yylineno;
	printf("\n Parsing Failed\nLine Number: %d %s\n",yylineno,msg);
	return 0;
}

