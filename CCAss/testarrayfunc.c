import <stdio.h>  
int @ *getarray(*a::int):
    printf("Enter the elements in an array : ") 
    for(@i=0::int;i<5;i++): 
        scanf("%d", &a[i])
    return a
int @ main():
    @a[5],*n::int
    n=getarray(a)
    printf("\nElements of array are :")  
    for(@i=0::int;i<5;i++): 
        printf("%d", n[i])
    printf("\n")