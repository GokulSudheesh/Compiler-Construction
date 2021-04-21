#include<stdio.h>
#include<string.h>
int array_format_spec[20];
int format_spec_counter = 0;

void format_string(char str[200]){
    format_spec_counter = 0;
    char specifiers[5] = {'d','c','f','l','s'};
    int i = 0;
    while(str[i]!='\0'){
        if(str[i] == '%'){
            //printf(" %c%c ",str[i],str[i+1]);
            for (int j=0;j<5;j++){
                if(str[i+1]==specifiers[j]){
                    array_format_spec[format_spec_counter] = j; //j will act as type-> 0 for int, 1 for char etc
                    format_spec_counter++;
                    break;
                }
            }
        }
        i++;
    }
}
void main(){
    format_string("hi %csmd%d %lf %d%f");
    printf("\n");
    for (int i = 0; i < format_spec_counter; i++){
        printf("%d ", array_format_spec[i]);
    }
    printf("\n");
}