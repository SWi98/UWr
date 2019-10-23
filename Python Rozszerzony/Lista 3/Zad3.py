

def sudan (n, x, y):
    if n == 0:
        return x + y
    elif y == 0:
        return x
    else:
        return sudan(n, sudan(n+1, x, y-1), sudan(n+1, x, y) + y + 1)

if(not None):
    print("x")