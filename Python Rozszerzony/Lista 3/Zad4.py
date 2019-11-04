import random

def uprosc_zdanie(str, word_len, n):
    res = list(filter(lambda x: len(x) <= word_len, str.split()))
    while(len(res) > n):
        res.remove(random.choice(res))
    return " ".join(res)

tekst = "Podział peryklinalny inicjałów wrzecionowatych \
kambium charakteryzuje się ścianą podziałową inicjowaną \
w płaszczyźnie maksymalnej."
print(uprosc_zdanie(tekst, 10, 5))