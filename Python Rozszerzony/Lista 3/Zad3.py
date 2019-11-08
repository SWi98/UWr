def sudan (n, x, y):
    cache = dict()

    def inner(n2, x2, y2):
        if (n2, x2, y2) in cache:
            return cache[(n2, x2, y2)]
        if n2 == 0:
            cache[(n2, x2, y2)] = x2 + y2
            return cache[(n2, x2, y2)]
        elif y2 == 0:
            cache[(n2, x2, y2)] = x2
            return cache[(n2, x2, y2)]
        else:
            cache[(n2, x2, y2)] = inner(n2-1, inner(n2, x2, y2-1), inner(n2, x2, y2-1) + y2 - 1 + 1) 
            return cache[(n2, x2, y2)]

    return inner(n, x, y)


print(sudan(0, 1, 1))
print(sudan(0, 2, 4))
print(sudan(1, 2, 1))
print(sudan(1, 5, 10))
print(sudan(2, 1, 1))