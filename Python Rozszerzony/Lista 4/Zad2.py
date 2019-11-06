from functools import reduce
import timeit

def doskonale_iteracyjna(n):
    res = []
    for elem in range(1, n+1):
        helper = elem
        for x in range(1, elem):
            if elem % x == 0:
                helper -= x
        if helper == 0:
            res.append(elem)
    return res


def doskonale_skladana(n):
    return [elem for elem in range(1, n+1) if elem == sum([i for i in range(1, elem) if elem % i == 0])] 


def doskonale_funkcyjna(n):
    return list(filter(lambda elem: elem == reduce(lambda acc, x: acc + x, list(filter(lambda div: elem % div == 0, range(1, elem))), 0),\
         range(1, n+1)))


ti = timeit.Timer("doskonale_iteracyjna(2000)", "from __main__ import doskonale_iteracyjna\nprint(\"Iteracyjnie:\")")
print(ti.timeit(20))
ts = timeit.Timer("doskonale_skladana(2000)", "from __main__ import doskonale_skladana\nprint(\"Lista skladana:\")")
print(ts.timeit(20))
tf = timeit.Timer("doskonale_funkcyjna(2000)", "from __main__ import doskonale_funkcyjna\nprint(\"Funkcyjnie:\")")
print(tf.timeit(20))
