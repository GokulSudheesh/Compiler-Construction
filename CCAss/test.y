%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	int yylex(void);
	int yyerror(const char *s);
	int yylineno;
	struct Variables{char var_name[30];int is_Array;int dims;int array_dim[5];int ptr_depth;int LHS_type;}var_list[20];
	int var_list_ind = 0;
	int success = 0;
	int current_data_type;
	int is_modulus = 0;
	char current_operator;
	int array_format_spec[20];
	int format_spec_counter=0;
	int RWmode; // 1 -> read mode, 2 -> write mode
	int dims;
	
	struct symbol_table{char var_name[30]; int type; int dim; int pointerDepth; int dim_bounds[5];};
	struct symbol_table_stack{
    	struct symbol_table var_list[100];
    	int var_count;
		int ind_level;
    	struct symbol_table_stack * prev;
    	struct symbol_table_stack * next;
	};
	struct symbol_table_stack * pointer = NULL;

	extern void push_table();
	extern void pop_table();
	struct symbol_table get_column(char var[30]);
	extern int lookup_in_table(char var[30], int mode);
	extern void insert_to_table(char var[30], int type, int is_Array, int dims, int ptr_depth, int array_dim[5]);
	extern int get_array_dimensions(char var[30]);
	extern void display_symbol_table();
	extern void format_string(char str[200]);
	extern void check_ind(int current_ind);
%}

%union{
	int line_ind;	
	int data_type;
	char var_name[30];
	int integer_val;
	float float_val;
	char q_string[200];
	struct 
		{
			char var_name[30];
			int type;
			int  data_depth;
			int isValue;
		}EXPN_type;
}
%token HASH INCLUDE HEADER_FILE AT MAIN VOID TAB LB RB LCB RCB LSQRB RSQRB SC COLON QMARK COMA IF ELSE_IF ELSE FOR DO 
%token WHILE PRINTF SCANF ET EQ GT LT GTE LTE NE AMPER OR NOT DQUOTE PLUS MINUS MUL DIV MOD EXP UPLUS UMINUS

%left PLUS MINUS
%left MUL DIV MOD
%left UMINUS
%left UPLUS
%right EXP
%right AMPER
%token<data_type>INT
%token<data_type>CHAR
%token<data_type>FLOAT
%token<data_type>DOUBLE
%token<var_name>VAR
%token<integer_val>INT_NUMBER
%token<float_val>FLOAT_NUMBER
%token<q_string>Q_STRING
%type<line_ind>INDENTATION
%type<data_type>DATA_TYPE
%type<EXPN_type>A_EXPN
%type<EXPN_type>ARRAY_ACCESS
%type<EXPN_type>INCR_DCR_EXPN

%start prm

%%
prm	: HEADERS FUNCTIONS MAIN_FUNC_BODY{success=1;}
HEADERS : HEADER HEADERS | HEADER
HEADER	: HASH INCLUDE LT HEADER_FILE GT | HASH INCLUDE Q_STRING {format_string($3);}

FUNCTIONS : FUNCTION_BODY | FUNCTION_BODY FUNCTIONS | {/*Epsilon*/}
FUNCTION_BODY : DATA_TYPE AT VAR LB RB COLON {push_table();} BODY {pop_table();}
MAIN_FUNC_BODY : MAIN_TYPE AT MAIN LB RB COLON {push_table();} BODY {pop_table();}

BODY	: INDENTATION {/*printf("Level %d\n", $1);*/check_ind($1);} DECLARATION_STATEMENTS BODY2
BODY2	: /*Epsilon*/ | INDENTATION {/*printf("Level %d\n", $1);*/check_ind($1);} DECLARATION_STATEMENTS BODY2 | INDENTATION {/*printf("Level %d\n", $1);*/check_ind($1);} PROGRAM_STATEMENTS BODY2

DECLARATION_STATEMENTS: AT VAR_LIST COLON COLON DATA_TYPE{
						
						for(int i = 0; i < var_list_ind; i++){
							if(var_list[i].LHS_type > 0){
								if (!((current_data_type == 2 && var_list[i].LHS_type == 1) || (current_data_type == 3 && var_list[i].LHS_type == 1)
								|| (current_data_type == 3 && var_list[i].LHS_type == 3))){
									if (current_data_type+1 != var_list[i].LHS_type){
										yyerror("Incompatible types.");
										exit(0);
									}
								}
							}
							insert_to_table(var_list[i].var_name, current_data_type, var_list[i].is_Array, var_list[i].dims, var_list[i].ptr_depth, var_list[i].array_dim);
						}
						var_list_ind = 0;
						for(int i = 0; i< 20; i++){
							var_list[i].LHS_type = 0;
							if (var_list[i].is_Array){
								var_list[i].is_Array = 0;
								var_list[i].dims = 0;
							}
							if (var_list[i].ptr_depth > 0){
								var_list[i].ptr_depth = 0;
							}
						}
					} 
					| WRITE_STATEMENT
VAR_LIST : VAR COMA VAR_LIST {
				strcpy(var_list[var_list_ind].var_name,$1);
				var_list_ind++;
				//insert_to_table($1,current_data_type);
			    }
	| ARRAY_DECLARATION COMA VAR_LIST {
		//printf("<ARRAY_DECLARATION COMA VAR_LIST>");
	}
	| PTR_VAR COMA VAR_LIST
	| VAR_LIST2 COMA VAR_LIST
	| VAR {
			strcpy(var_list[var_list_ind].var_name,$1);
			var_list_ind++;
			//insert_to_table($1,current_data_type);
	      }
	| ARRAY_DECLARATION {
		//printf("<ARRAY_DECLARATION>");
	}
	| PTR_VAR
	| VAR_LIST2
VAR_LIST2 : VAR EQ A_EXPN {
				if ($3.data_depth!=0){
					yyerror("Incompatible pointer type in assignment");
					exit(0);
				}
				
				strcpy(var_list[var_list_ind].var_name,$1);
				var_list[var_list_ind].LHS_type = $3.type+1;
				var_list_ind++;
			}
PTR_VAR :	PTR_DEPTH VAR {
				//printf("<PTR_DEPTH VAR>");
				//insert_to_table($2,current_data_type);
				strcpy(var_list[var_list_ind].var_name,$2);
				var_list_ind++;
				//var_list[var_list_ind].ptr_depth = 0;
			}
PTR_DEPTH :	MUL PTR_DEPTH {
				//printf("<MUL PTR_DEPTH>");
				var_list[var_list_ind].ptr_depth++;

			} 
			| MUL {				
				//printf("<MUL>");
				var_list[var_list_ind].ptr_depth = 0;
				var_list[var_list_ind].ptr_depth++;
			}
ARRAY_DECLARATION: VAR ARRAY_SIZE {
		var_list[var_list_ind].is_Array = 1;
		strcpy(var_list[var_list_ind].var_name,$1);
		var_list_ind++;
		//insert_to_table($1,current_data_type);
	}
ARRAY_SIZE : ARRAY_SIZE LSQRB INT_NUMBER RSQRB {
				var_list[var_list_ind].dims++;
				var_list[var_list_ind].array_dim[var_list[var_list_ind].dims] = $3;
				//printf("<ARRAY_SIZE LSQRB %d RSQRB>", $3);
			}
			| LSQRB INT_NUMBER RSQRB {
				var_list[var_list_ind].dims = 0;
				var_list[var_list_ind].array_dim[var_list[var_list_ind].dims] = $2;
				//printf("<LSQRB %d RSQRB>", $2);
			}
MAIN_TYPE : INT | VOID
DATA_TYPE : INT {
			$$=$1;
			current_data_type=$1;
		} 
	| CHAR  {
			$$=$1;
			current_data_type=$1;
		}
	| FLOAT {
			$$=$1;
			current_data_type=$1;
		}
	| DOUBLE {
			$$=$1;
			current_data_type=$1;
		}
 
PROGRAM_STATEMENTS :	ASSIGNMENT_STATEMENT
				| READ_STATEMENT
				| INCR_DCR_EXPN
				| LB LOGICAL_EXPN RB QMARK LCB {push_table();} BODY2 RCB {pop_table();} COLON LCB {push_table();} BODY2 RCB {pop_table();}
				| CONDITIONAL_STATEMENTS
				| WHILE LB LOGICAL_EXPN RB COLON {push_table();} BODY2 //RCB {pop_table();}
				| DO COLON {push_table();} BODY2 WHILE LB LOGICAL_EXPN RB
				| FOR LB ASSIGNMENT_STATEMENT COMA LOGICAL_EXPN COMA INCR_DCR_EXPN RB COLON {push_table();} BODY2 //RCB {pop_table();}
				| FOR LB DECLARATION_STATEMENTS COMA LOGICAL_EXPN COMA INCR_DCR_EXPN RB COLON {push_table();} BODY2
				| {/*Epsilon*/}

WRITE_STATEMENT : PRINTF LB Q_STRING {RWmode = 2; format_string($3);} RB{
					RWmode = 0;
					if(format_spec_counter!=0){
						yyerror("More arguments expected to printf function."); exit(0);
					}
				} 
				| PRINTF LB Q_STRING {RWmode = 2; format_string($3);} COMA VAR_LIST_OP RB{
					//printf("%d",format_spec_counter);
					RWmode = 0;
					if(format_spec_counter != 0){
						printf("Parsing Failed\nLine Number %d: %d more arguments required.\n", yylineno, format_spec_counter);
						exit(0);
					}
				}
VAR_LIST_OP : A_EXPN COMA VAR_LIST_OP {
				//printf("<A_EXPN COMA VAR_LIST_OP>");
				if(array_format_spec[--format_spec_counter] == 4){
					if($1.data_depth != 1 || $1.type != 1){
						yyerror("Format '%s' expects argument of type 'char *'"); exit(0);
					}
				}
				else if (array_format_spec[format_spec_counter] != $1.type){
					yyerror("Type mismatch in arguments."); exit(0);
				}			
			}
			| A_EXPN {
				//printf("<A_EXPN>");
				if(array_format_spec[--format_spec_counter] == 4){
					if($1.data_depth != 1 || $1.type != 1){
						yyerror("Format '%s' expects argument of type 'char *'"); exit(0);
					}
				}
				else if (array_format_spec[format_spec_counter] != $1.type){
					yyerror("Type mismatch in arguments."); exit(0);
				}				
			}

READ_STATEMENT : SCANF LB Q_STRING {RWmode = 1; format_string($3);} COMA VAR_LIST_IP RB{RWmode = 0;}
VAR_LIST_IP : A_EXPN COMA VAR_LIST_IP {
				//printf("<A_EXPN COMA VAR_LIST_IP>");
				if (array_format_spec[--format_spec_counter] != $1.type){
					yyerror("Type mismatch in arguments."); exit(0);
				}
				else if ($1.data_depth != 1){
					yyerror("Error in reference depth."); exit(0);
				}		
			}
			| A_EXPN {
				//printf("<A_EXPN>");
				if (array_format_spec[--format_spec_counter] != $1.type){
					yyerror("Type mismatch in arguments."); exit(0);
				}
				else if ($1.data_depth != 1){
					yyerror("Error in reference depth."); exit(0);
				}				
			}

CONDITIONAL_STATEMENTS : IF_STATEMENT | IF_STATEMENT ELSE_STATEMENT | IF_STATEMENT ELSE_IF_STATEMENT | IF_STATEMENT ELSE_IF_STATEMENT ELSE_STATEMENT
IF_STATEMENT : IF LB LOGICAL_EXPN RB COLON {push_table();} BODY2 //RCB {pop_table();}
ELSE_IF_STATEMENT : ELSE_IF LB LOGICAL_EXPN RB COLON {push_table();} BODY2 /*RCB {pop_table();}*/ | ELSE_IF_STATEMENT ELSE_IF LB LOGICAL_EXPN RB COLON {push_table();} BODY2 //RCB {pop_table();}
ELSE_STATEMENT : ELSE COLON {push_table();} BODY2 //RCB {pop_table();}

ASSIGNMENT_STATEMENT : A_EXPN EQ A_EXPN
				{
					if($1.type!=$3.type)
					{
						yyerror("Incompatible type in assignment");
						exit(0);
					}else if($1.data_depth!=$3.data_depth)
					{
						yyerror("Incompatible pointer type in assignment");
						exit(0);
						//printf("\n Line number: %d Warning : Incompatible pointer type in assignment",yylineno);
					}
					else if($1.isValue==1)
					{
						yyerror("lvalue required as left operand of the assignment operator");
						exit(0);
					}	
				}

LOGICAL_EXPN	: NOT LB LOGICAL_EXPN1 RB | LOGICAL_EXPN1
LOGICAL_EXPN1	: LOGICAL_EXPN1 LOGICAL_OPERATOR LOGICAL_EXPN1 | LOGICAL_EXPN2 | NOT LB LOGICAL_EXPN1 RB 
				| LB LOGICAL_EXPN1 RB
LOGICAL_EXPN2	: A_EXPN COMP_OPERATOR A_EXPN
COMP_OPERATOR	: ET | GT | LT | GTE | LTE | NE
LOGICAL_OPERATOR	: AMPER AMPER | OR

A_EXPN	: A_EXPN OPR_PREC1 A_EXPN	
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
							yyerror("Type mismatch in operands");
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
						yyerror("Type mismatch in dereferencing operands");
						exit(0);						
					}
				}

		|A_EXPN OPR_PREC2 A_EXPN
				{
					if($1.type!=$3.type)
					{
						yyerror("Type mismatch in operands");exit(0);
					}
					if(is_modulus){
						if($1.type!=0 || $3.type!=0){
							yyerror("Modulus operator reserved for integers."); exit(0);
						}
						is_modulus = 0;
					}
					if($1.data_depth!=0 || $3.data_depth!=0)
					{
						printf("\nInvalid operands to binary %c", current_operator);exit(0);
					}	
					$$.isValue=1;
					$$.data_depth=0;
					$$.type=$1.type;	
				}
		| LB A_EXPN RB {
			$$.isValue = $2.isValue;
			$$.data_depth = $2.data_depth;
			$$.type = $2.type;
		}		
		| INCR_DCR_EXPN {
			$$.type=$1.type;
			$$.data_depth=$1.data_depth;	
			$$.isValue=1;
		}
		| VAR {
			struct symbol_table column = get_column($1);
			$$.type = column.type;
			$$.data_depth = column.pointerDepth;
			$$.isValue = 0;
			strcpy($$.var_name, $1);
		}
		| INT_NUMBER {
			$$.type = 0;
			$$.data_depth = 0;	
			$$.isValue = 1;
		}
		| FLOAT_NUMBER {
			$$.type = 2;
			$$.data_depth = 0;	
			$$.isValue = 1;
		}
		| MUL A_EXPN
			{
				if($2.data_depth==0)
				{
					yyerror("Invalid operand to unary \'*\' operator");
					exit(0);
				}
				else
				{
					$$.type=$2.type;
					$$.data_depth=$2.data_depth-1;
					$$.isValue=0;
				}										
			}
		| ARRAY_ACCESS {
			if(dims!=get_array_dimensions($1.var_name) && (RWmode == 0)){
				printf("\n Error: Indexing error in array: %s\n", $1.var_name);exit(0);
			}
			$$.type=$1.type;
			$$.data_depth=$1.data_depth;
			$$.isValue=0;
			dims=0;
		}			
		| AMPER A_EXPN	
			{		
				if($2.isValue==1)
				{
					yyerror("lvalue required for unary operator &");
					exit(0);
				}
				$$.type=$2.type;
				$$.data_depth=$2.data_depth+1;
				$$.isValue=1;						
			}

ARRAY_ACCESS : ARRAY_ACCESS LSQRB A_EXPN RSQRB
			{	
				dims++;
				if($3.data_depth!=0 || $3.type!=0)
				{
					yyerror("Array index integer expected\n");
					exit(0);
				}
				else if($1.data_depth==0)
				{
					yyerror("Subscripted value neither array nor pointer");
					exit(0);
				}
				else
				{
					$$.type=$1.type;
					$$.data_depth=$1.data_depth-1;
					$$.isValue=0;
					strcpy($$.var_name, $1.var_name);
				}
			}
			| VAR LSQRB A_EXPN RSQRB{
				struct symbol_table column = get_column($1);
				dims++;
				if($3.data_depth!=0 || $3.type!=0)
				{
					yyerror("Array index integer expected\n");
					exit(0);
				}
				else if(column.pointerDepth==0)
				{
					yyerror("Subscripted value neither array nor pointer");
					exit(0);
				}
				else
				{
					$$.type = column.type;
					$$.data_depth = column.pointerDepth-1;
					$$.isValue = 0;
					strcpy($$.var_name, $1);
				}
			}

INCR_DCR_EXPN : A_EXPN UNARY_OPERATORS {
				if($$.isValue==1)
				{
					yyerror("lvalue required");exit(0);
				}else
				{
					$$.type=$1.type;
					$$.data_depth=$1.data_depth;	
					$$.isValue=1;
				}
			}

UNARY_OPERATORS: UPLUS | UMINUS
OPR_PREC1: PLUS | MINUS
OPR_PREC2: DIV {current_operator='/';} 
		| MUL {current_operator='*';} 
		| EXP {current_operator='^';} 
		| MOD {current_operator='%'; is_modulus = 1;}

INDENTATION : TAB {/*printf("<TAB>");*/$$ = 1;} | INDENTATION TAB {/*printf("<INDENTATION TAB>");*/$$++;}

%%

void push_table(){
	printf("{\n");
    struct symbol_table_stack * node = (struct symbol_table_stack *)malloc(sizeof(struct symbol_table_stack));
    node->var_count = -1;
    
    if(pointer == NULL){
		node->ind_level = 1;
        pointer = node;
    }
    else{
		node->ind_level = pointer->ind_level + 1;
        pointer->next = node;
        node->prev = pointer;
        pointer = node;
    }
}

void pop_table(){
	//display_symbol_table();
	printf("}\n");
    if(pointer != NULL){
        if(pointer->prev == NULL){
            pointer = NULL;
        }
        else{
            pointer = pointer->prev;
            pointer->next = NULL;
        }        
    }
}

struct symbol_table get_column(char var[30]){
    struct symbol_table_stack * current = pointer;
    if(lookup_in_table(var,0)!=-1){        
        while(current != NULL){
            for(int i=0; i<=current->var_count; i++)
            {
                if(strcmp(current->var_list[i].var_name, var)==0)
                {
                    return current->var_list[i];
                }
            }
            current = current->prev;
        }
	}
	else{
		printf("\n variable \"%s\" undeclared\n",var);exit(0);
	}
	return current->var_list[0];
}

int lookup_in_table(char var[30], int mode) //mode (0->check all nodes) (1->check current node) 
{
    struct symbol_table_stack * current = pointer;
    while(current != NULL){
        for(int i=0; i<=current->var_count; i++)
        {
            if(strcmp(current->var_list[i].var_name, var)==0)
            {
                return current->var_list[i].type;
            }
        }
        if(mode == 1){
            return -1;
        }
        current = current->prev; 
    }    
	return -1;
}
void insert_to_table(char var[30], int type, int is_Array, int dims, int ptr_depth, int array_dim[5])
{
	if (lookup_in_table(var,1) == -1)
	{
		pointer->var_count++;
		strcpy(pointer->var_list[pointer->var_count].var_name, var);
    	pointer->var_list[pointer->var_count].type = type;
		if (is_Array){
			pointer->var_list[pointer->var_count].dim = dims+1;
			pointer->var_list[pointer->var_count].pointerDepth = dims+1;
			for(int i = 0; i <= dims; i++){
				pointer->var_list[pointer->var_count].dim_bounds[i] = array_dim[i];
				//printf("\n%d\n",pointer->var_list[var_count].dim_bounds[i]);
			}
			is_Array=0;
			dims = 0;
		}
		else{
			pointer->var_list[pointer->var_count].dim = 0;
			for(int i = 0; i < 5; i++){
				pointer->var_list[pointer->var_count].dim_bounds[i] = -1;
			}
		}
		if(ptr_depth > 0){
			pointer->var_list[pointer->var_count].pointerDepth = ptr_depth;
		}
    }
    else
    {
        char error_message[50];
		strcpy(error_message, "multiple declaration of variable: ");
		yyerror(strcat(error_message, var));
		exit(0);
    }
}
int get_array_dimensions(char var[30])
{
    struct symbol_table_stack * current = pointer;
    while(current != NULL){
        for(int i=0; i<=current->var_count; i++)
        {
            if(strcmp(current->var_list[i].var_name, var)==0)
            {
                return current->var_list[i].dim;
            }
        }
        current = current->prev;
    }
	printf("\n variable \"%s\" undeclared\n",var);exit(0);
}
void display_symbol_table(){
    struct symbol_table_stack * current = pointer;
    while(current != NULL){
        printf("\n+------------------------------SYMBOL TABLE------------------------------+\n");
        printf("|Var name\t\tType\tPtrDepth\tDim\tDim Bounds\t |\n");
        for(int i=0; i<=current->var_count; i++)
        {
            printf("|%s\t\t\t%d\t%d\t\t%d\t{", current->var_list[i].var_name, current->var_list[i].type, current->var_list[i].pointerDepth, current->var_list[i].dim);
            for(int j=0; j<5; j++){
                printf("%d ",current->var_list[i].dim_bounds[j]);
            }
            printf("}|\n");
        }
        printf("+------------------------------------------------------------------------+\n");
        current = current->prev;
    }
}
void format_string(char str[200]){
	if (RWmode == 0){ //for Header Files
		int i = 0;
		while(str[i]!='\0'){
			i++;
		}
		if (str[i-3]!='.' && str[i-2]!='h'){
			yyerror("Invalid format for header file.");exit(0);
		}
	}
	else{
		format_spec_counter = 0;
		char specifiers[5] = {'d','c','f','l','s'};
		int i = 0;
		while(str[i]!='\0'){
			if(str[i] == '%'){
				//printf(" %c%c ",str[i],str[i+1]);
				if (RWmode == 1 && str[i+1]=='s'){
					array_format_spec[format_spec_counter] = 1;
					format_spec_counter++;	
				}
				else{
					for (int j=0;j<5;j++){
						if(str[i+1]==specifiers[j]){
							array_format_spec[format_spec_counter] = j; //j will act as type-> 0 for int, 1 for char etc
							format_spec_counter++;
							break;
						}
					}
				}
			}
			i++;
		}
	}
}
void check_ind(int current_ind){
	if(current_ind < pointer->ind_level){
		int indd = pointer->ind_level - current_ind;
		while(indd!=0){
			pop_table();
			indd--;
		}
	}
	if(current_ind != pointer->ind_level){
		yyerror("Indentation Error");exit(0);
	}
}
int main()
{
    yyparse();
	if(success){
    	printf("\nParsing Successful\n");
	}
    return 0;
}

int yyerror(const char *msg)
{
	extern int yylineno;
	printf("Parsing Failed\nLine Number: %d %s\n",yylineno,msg);
	success = 0;
	return 0;
}