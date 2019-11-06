from math import sqrt
import timeit

'''def pierwsze_imperatywnaEr(n):
    res = []
    for i in range(2, n+1):
        res.append(i)
    for i in range(2, round(sqrt(n)) + 1):
        for j in range(i*i, n+1, i):
            if j in res:
                res.remove(j)
    return res
        
def pierwsze_skladanaEr(n):
    z = []
    [z.append(j) for i in range(2, round(sqrt(n)) + 1) for j in range(i, n+1, i) if j not in z]
    #print(z)
    return [elem for elem in range(2, n+1) if elem not in [j for i in range(2, round(sqrt(n)) + 1) for j in range(i*i, n+1, i)]]'''

def pierwsze_imperatywna(n):
    res = []
    for i in range(2, n+1):
        if i == 2 or i == 3:
            res.append(i)
        else:
            for j in range(2, round(sqrt(i)) + 1):
                if i % j == 0:
                    break
                elif j == round(sqrt(i)):
                    res.append(i)
    return res


def pierwsze_skladana(n):
    return [elem for elem in range(2, n+1) if elem == 2 or elem == 3 or all(elem % j for j in range(2, round(sqrt(elem)) + 1) )]


def pierwsze_funkcyjna(n):
    return list(filter(lambda x: x == 2 or x == 3 or list(filter(lambda y: x % y == 0 , range(2, round(sqrt(x)) + 1))) == [] , range(2, n+1)))
    

ti = timeit.Timer("pierwsze_imperatywna(2000)", "from __main__ import pierwsze_imperatywna\nprint(\"Iteracyjnie:\")")
print(ti.timeit(200))
ts = timeit.Timer("pierwsze_skladana(2000)", "from __main__ import pierwsze_skladana\nprint(\"Lista skladana:\")")
print(ts.timeit(200))
tf = timeit.Timer("pierwsze_funkcyjna(2000)", "from __main__ import pierwsze_funkcyjna\nprint(\"Funkcyjnie:\")")
print(tf.timeit(200))