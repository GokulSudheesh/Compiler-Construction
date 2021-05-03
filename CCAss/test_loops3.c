import stdio.h
import string.h
void@print_array(para2[17]::char):
    write(para2)
int@main():
    set arr as [1,2,3,4,5] :: int
    for p in arr:
        set lol::int
        print("%d ",p)
    set var1,var2::float
    set var3 as '1' :: char
    set string_arr as ["Hi","this","is","just some array","a","string","array"] :: string
    print_array(string_arr[0])
    for str in string_arr:
        write(str)
    //print("%d", global1)
    return 0