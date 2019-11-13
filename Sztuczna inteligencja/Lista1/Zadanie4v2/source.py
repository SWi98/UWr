import copy

def NumberOfBits(NewSeries, GivenSeries):
    Count = 0
    for i in range(0, len(NewSeries)):
        if NewSeries[i] != GivenSeries[i]:
            Count += 1
    return Count


def opt_dist(Series, D):
    CurrentS = []
    for i in range(0, len(Series)):
        if D == 0:
            CurrentS.append('0')
        elif i < D:
            CurrentS.append('1')
        else:
            CurrentS.append('0')

    min = NumberOfBits(CurrentS, Series)

    if D == 0:
        return min

    for i in range(D, len(Series)):
        CurrentS[i-D] = '0'
        CurrentS[i] = '1'
        newMin = NumberOfBits(CurrentS, Series)
        if newMin < min:
            min = newMin
    return min


def test(s):
    for i in range(0, 6):
        print(opt_dist(s, i))


