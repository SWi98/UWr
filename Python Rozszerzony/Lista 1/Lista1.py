import functools
import itertools

def sum23(a, b):
    return round(a + 0.77 * b, 2)

def vat_faktura(zakupy): 
    return functools.reduce(sum23, zakupy)

def vat_paragon(zakupy):
    x = sum(zakupy)
    return round(0.77 * x, 2)

def drobne(kwota):
    noms = {1 : 0, 2 : 0, 5 : 0, 10 : 0, 20: 0}
    nom = 20 
    while kwota > 0:
        while kwota >= nom:
            kwota = kwota - nom
            noms[nom] = noms[nom] + 1
        nom = int(nom / 2)
    print(noms)

def romb(n):
    h = 1
    spaces = n 
    for _ in range(n):
        print(" " * spaces + '#' * h)
        h += 2
        spaces += -1
    h -= 4
    spaces += 2
    for _ in range(n):
        print(" " * spaces +  '#' * h)
        h -= 2
        spaces += 1
        

#def zaszyfruj(tekst, klucz):
 #   res = ""
  #  bin_klucz = bin(klucz)
   # for i in range(len(tekst)):
    #    ascii_num = ord(tekst[i])
     #   bin_num = bin(ascii_num)



print(vat_faktura([1, 2, 3, 4, 20.5, 115.29]))
print(vat_paragon([1, 2, 3, 4, 20.5, 115.29]))  
drobne(19)
drobne(7)
drobne(51)
romb(1)
romb(5)
romb(10)