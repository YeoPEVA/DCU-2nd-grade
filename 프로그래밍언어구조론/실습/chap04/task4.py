x = 2

def sub1():
    print("sub1_x = ", x)

def sub2():
    x = 4
    sub1()
    print("sub2_x = ", x)

sub2()