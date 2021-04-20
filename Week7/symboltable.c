#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int is_Array;
int dims;
int array_dim[]={-1,-1,-1,-1,-1};
int ptr_depth;
struct symbol_table get_column(char var[30]);
extern int lookup_in_table(char var[30]);
extern void insert_to_table(char var[30], int type);

struct symbol_table{char var_name[30]; int type; int dim; int pointerDepth; int dim_bounds[5];};
struct symbol_table_stack{
    struct symbol_table var_list[100];
    int var_count;
    struct symbol_table_stack * prev;
    struct symbol_table_stack * next;
};
struct symbol_table_stack * pointer = NULL;

void push_table(){
    struct symbol_table_stack * node = (struct symbol_table_stack *)malloc(sizeof(struct symbol_table_stack));
    node->var_count = -1;
    
    if(pointer == NULL){
        pointer = node;
    }
    else{
        pointer->next = node;
        node->prev = pointer;
        pointer = node;
    }
}

void pop_table(){
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
    if(lookup_in_table(var)!=-1){        
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

int lookup_in_table(char var[30])
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
        current = current->prev; 
    }    
	return -1;
}

void insert_to_table(char var[30], int type)
{
	if (lookup_in_table(var) == -1)
	{
		pointer->var_count++;
		strcpy(pointer->var_list[pointer->var_count].var_name, var);
    	pointer->var_list[pointer->var_count].type = type;
		if (is_Array){
			pointer->var_list[pointer->var_count].dim = dims+1;
			pointer->var_list[pointer->var_count].pointerDepth = dims+1;
			for(int i = 0; i <= dims; i++){
				pointer->var_list[pointer->var_count].dim_bounds[i] = array_dim[i];
				//printf("\n%d\n",var_list[var_count].dim_bounds[i]);
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
        printf("\nmultiple declaration of variable: %s", var);
    }
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

void main()
{
    push_table();
    insert_to_table("var1", 1);
    insert_to_table("var1", 1);
    insert_to_table("var3", 0);
    //pop_table();
    push_table();
    insert_to_table("var4", 1);
    insert_to_table("var5", 1);
    insert_to_table("var6", 1);
    insert_to_table("var3", 1);
    display_symbol_table();
    printf("\nDone.\n");
    //Test 2
    struct symbol_table column = get_column("var3");
    printf("\nName: %s, Type %d\n", column.var_name, column.type);
}
