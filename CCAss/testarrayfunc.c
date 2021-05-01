import stdio.h
int @ *getarray(*a::int):
    print("Enter the elements in an array : ") 
    for(set i=0::int,i<5,i++): 
        input(a[i])
    return a
int @ main():
    set a[5],*n::int
    n=getarray(a)
    println("Elements of array are :")
    for element in a:
        print("%d ",element)
    println()