import stdio.h
import string.h
void @ func1():    
int @ main():
    set string_1 = "string1", string_2 = "string1" :: char
    set string_3 = "string2", string_4 = "string4" :: char
    set string5[100], string6[100] :: char
    string5 = "stringmoree1"
    string6 = "string1"
    if(string_1 is string_2):
        println("%s == %s",string_1,string_2)
    if(string_3 is not string_1):
        println("%s != %s",string_3,string_1)
    if(string5>string_1):
        println("%s > %s",string5,string_1)
    if(string_1<string5):
        println("%s < %s",string_1,string5)
    if(string_2 is "string1"):
        println("%s == string1",string_2)
    if(string_2[0] is 's'):
        println("YES")
    return 0