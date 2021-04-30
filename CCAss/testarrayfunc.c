import stdio.h
int @ *getarray(*a::int):
    print("Enter the elements in an array : ") 
    for(set i=0::int;i<5;i++): 
        read("%d", &a[i])
    return a
int @ main():
    set a[5],*n::int
    n=getarray(a)
    println("Elements of array are :")  
    for(set i=0::int;i<5;i++): 
        print("%d", n[i])
    println()