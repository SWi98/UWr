def square(n):
    res = 0
    for i in range(1, n+1):
        res += 2 * i - 1 
        if res == n:
            return i 
        elif res > n:
            return i-1

print("sqrt({}) = {}" .format(25, square(25)))
print("sqrt({}) = {}".format(27, square(27)))
print("sqrt({}) = {}".format(100, square(100)))
print("sqrt({}) = {}".format(1, square(1)))
print("sqrt({}) = {}".format(2, square(2)))
print("sqrt({}) = {}".format(3, square(3)))
print("sqrt({}) = {}".format(6, square(6)))
print("sqrt({}) = {}".format(16, square(16)))
print("sqrt({}) = {}".format(63, square(63)))
print("sqrt({}) = {}".format(64, square(64)))
print("sqrt({}) = {}".format(66, square(66)))