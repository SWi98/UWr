from itertools import product
from itertools import permutations

class Formula:

    def find_vars(self, acc):
        if isinstance(self, Zmienna):
            acc.add(self.form)              # pylint: disable=no-member
            return acc
        elif isinstance(self, Neg):
            return self.form.find_vars(acc)     # pylint: disable=no-member
        elif isinstance(self, (True_, False_)):
            return acc
        else:
            return self.left.find_vars(acc) | self.right.find_vars(acc)   # pylint: disable=no-member

    
    def is_taut(self):
        vars = self.find_vars(set())
        #vars_dict = dict([(x, [True, False]) for x in vars])
        #poss_val = [dict(zip(vars_dict, y)) for y in product(*vars_dict.values())]
        poss_val = [dict(zip(vars, y)) for y in set(permutations(2 * len(vars) * (True, False), len(vars)))]
        for val in poss_val:
            if self.oblicz(val) == False:       # pylint: disable=no-member
                return False
        return True

    def test(self):
        print("{} - tautologia? {}".format(self.__str__(), self.is_taut()))


class True_(Formula):
    def oblicz(self, zmienne):
        return True
    def __str__(self):
        return "T"
    

class False_(Formula):
    def oblicz(self, zmienne):
        return False 
    def __str__(self):
        return "F"


class Zmienna(Formula):
    def __init__(self, z):
        self.form = z

    def oblicz(self, zmienne):
        return zmienne[self.form]

    def __str__(self):
        return self.form


class Neg(Formula):
    def __init__(self, f):
        self.form = f
        
    def oblicz(self, zmienne):
        return not self.form.oblicz(zmienne)

    def __str__(self):
        return "-" + self.form.__str__()
           

class And(Formula):
    def __init__(self, fst, snd):
        self.left = fst
        self.right = snd

    def oblicz(self, zmienne):
        return self.left.oblicz(zmienne) and self.right.oblicz(zmienne)

    def __str__(self):
        return "(" + self.left.__str__() + " AND " + self.right.__str__() + ")"


class Alt(Formula):
    def __init__(self, fst, snd):
        self.left = fst 
        self.right = snd
        
    def oblicz(self, zmienne):
        return self.left.oblicz(zmienne) or self.right.oblicz(zmienne)

    def __str__(self):
        return "(" + self.left.__str__() + " OR " + self.right.__str__() + ")"

    
class Impl(Formula):
    def __init__(self, fst, snd):
        self.left = fst
        self.right = snd

    def oblicz(self, zmienne):
        return not (self.left.oblicz(zmienne)) or self.right.oblicz(zmienne)

    def __str__(self):
        return "(" + self.left.__str__() + " => " + self.right.__str__() + ")"


class Iff(Formula):
    def __init__(self, fst, snd):
        self.left = fst
        self.right = snd

    def oblicz(self, zmienne):
        return self.left.oblicz(zmienne) == self.right.oblicz(zmienne)
    
    def __str__(self):
        return "(" + self.left.__str__() + " <=> " + self.right.__str__() + ")"


#u = {"x" : [True, False], "y" : [True, False]}  
#z = set(["x", "y", "z"])
#print(set(permutations(2 * len(z) * (True, False), len(z))))
#for x in product(*u.values()):
 #   print(x)
test1 = Iff(Zmienna("x"), Zmienna("x"))
test1.test()
test2 = Impl(Zmienna("x"), And(Zmienna("y"), True_()))
test2.test()
test3 = Iff(Neg(And(Zmienna("A"), Zmienna("B"))), Alt(Neg(Zmienna("A")), Neg(Zmienna("B"))))
test3.test()
test4 = Impl(False_(), Zmienna("y"))
test4.test()
#test3.oblicz({'A': False, 'B': True})