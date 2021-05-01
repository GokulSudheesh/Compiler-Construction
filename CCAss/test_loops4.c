import stdio.h

int@main():
    set b=0,c=0::int
    loop(c<10):
        set lol1::float
        loop(b<11):
            set lol2::float
            b++
        c++
    b=0
    do:
        set lol3::int
        b++
    until(b<2)
    println("Done")
    set new_var=0::int
    loop(new_var>10):
        new_var++
    return 0