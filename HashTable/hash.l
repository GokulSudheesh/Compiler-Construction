%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int N=5;
struct  HashTable * BArray[5];
struct HashTable{
    char var_name[30];
    struct HashTable * next;
};
struct HashTable * create(char var_name[30]);
void insert(char var_name[30]);
int isnum(char c);
int h(char k[30]);
void display();
%}
%%
([A-Z]+|[a-z]+)([A-Z]+|[a-z]+|[0-9]+)* {insert(yytext);}
[\n\t ]+  {/*new line or space*/}
%%

struct HashTable * create(char var_name[30]){
    struct  HashTable * temp;
    temp=(struct HashTable *)malloc(sizeof(struct HashTable));
    strcpy(temp->var_name,var_name);
    return temp;
}
void insert(char var_name[30]){
    int key=h(var_name);
    //printf("%d",key);
    for(int i=0;i<N;i++){
        if(i==key){
            if(BArray[i]==NULL){
                BArray[i]=create(var_name);
            }
            else{
                struct HashTable * current=BArray[i];
                struct HashTable * node=create(var_name);
                while(current->next!=NULL){
                    current=current->next;
                }
                current->next=node;
            }
        }
    }
}
int isnum(char c){
    char num[] = {'0','1','2','3','4','5','6','7','8','9'};
    for (int i=0; i<10; i++){
        if(c==num[i]){
            return 1;
        }
    }
    return 0;
}
int h(char k[30]){
    int sum_alpha=0,sum_num=0,sum;
    for(int i=0;k[i]!='\0';i++){
        if(isnum(k[i])){
            sum_num+= (int)k[i];
        }
        else{
            sum_alpha+= (int)k[i];
        }
    }
    sum = (sum_alpha + 2*sum_num)*17+5;
    return abs(sum%N);
}

void display(){
    for(int i=0;i<N;i++){
        printf("\n %d ",i);
        struct HashTable * current=BArray[i];
        while(current!=NULL){
            printf("%s  ",current->var_name);
            current= current->next;
        }
    }
    printf("\n");
}
int yywrap(){
    return 1;
}
int main(){
    yylex();
    display();
}