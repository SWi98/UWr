from math import sqrt
import timeit
import time

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

def pierwsze_iteracyjnie(n):
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


class Pierwsze:
    number = 1

    def __iter__(self, number = 2):
        self.number = 1
        return self

    def __next__(self):
        i = self.number + 1
        if i == 2 or i == 3:
            self.number += 1
            return i
        while True:
            found = True
            for j in range(2, round(sqrt(i)) + 1):
                if i % j == 0:
                    found = False
                    break
            if found:
                self.number = i
                return i
            else:
                i += 1
                

def test(fun, N):
    start_time = time.time()
    fun(N)
    print(f"{N}: {time.time() - start_time}")

def testIterator(N):
    res = []
    my_iter = Pierwsze()
    start_time = time.time()
    for _ in range(N):
        res.append(next(my_iter))
    print(f"{N}: {time.time() - start_time}")

print("\nIteracyjnie: ")
test(pierwsze_iteracyjnie, 100)
test(pierwsze_iteracyjnie, 1000) 
test(pierwsze_iteracyjnie, 10000) 
print("\nLista składana: ")
test(pierwsze_skladana, 100)
test(pierwsze_skladana, 1000) 
test(pierwsze_skladana, 10000) 
print("\nFunkcyjnie: ")
test(pierwsze_funkcyjna, 100)
test(pierwsze_funkcyjna, 1000) 
test(pierwsze_funkcyjna, 10000) 
print("\nIterator:")
testIterator(100)
testIterator(1000)
testIterator(10000)


'''
ti = timeit.Timer("pierwsze_imperatywna(2000)", "from __main__ import pierwsze_imperatywna\nprint(\"Iteracyjnie:\")")
print(ti.timeit(200))
ts = timeit.Timer("pierwsze_skladana(2000)", "from __main__ import pierwsze_skladana\nprint(\"Lista skladana:\")")
print(ts.timeit(200))
tf = timeit.Timer("pierwsze_funkcyjna(2000)", "from __main__ import pierwsze_funkcyjna\nprint(\"Funkcyjnie:\")")
print(tf.timeit(200))'''