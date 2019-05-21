import sys

def V(i,j):
    return 'V%d_%d' % (i,j)


def domains(Vs):
    return [q + ' in 1..9' for q in Vs]


def all_different(Qs):
    return 'all_distinct([' + ', '.join(Qs) + '])'


def get_column(j):
    return [V(i,j) for i in range(9)]


def get_raw(i):
    return [V(i,j) for j in range(9)]


def horizontal():   
    return [ all_different(get_raw(i)) for i in range(9)]


def vertical():
    return [all_different(get_column(j)) for j in range(9)]


def different_squares():

    def square(z, y):
        pos_inside=[(0,0), (1,0), (2,0), (0, 1), (0, 2), (1, 1), (2, 1), (2, 2), (1, 2)]
        return[V(z + pos[0], y + pos[1]) for pos in pos_inside]

    squares_pos =[(0, 0), (0, 3), (0, 6), (3, 0), (3, 3), (3, 6), (6, 0), (6, 3), (6, 6)]
    return[all_different(square(p[0], p[1])) for p in squares_pos]


def print_constraints(Cs, indent, d):
    position = indent
    file_output.write((indent - 1) * ' ')
    for c in Cs:
        file_output.write(c + ',')
        position += len(c)
        if position > d:
            position = indent
            file_output.write("\n")
            file_output.write((indent - 1) * ' ' )

      
def sudoku(assigments):
    variables = [ V(i,j) for i in range(9) for j in range(9)]
    
    file_output.write(':- use_module(library(clpfd)).' + "\n")
    file_output.write('solve([' + ', '.join(variables) + ']) :- ' + "\n")
    
    
    cs = domains(variables) + vertical() + horizontal() + different_squares()
    for i,j,val in assigments:
        cs.append( '%s #= %d' % (V(i,j), val) )
    
    print_constraints(cs, 4, 70),
    file_output.write("\n")
    file_output.write('labeling([ff], [' +  ', '.join(variables) + ']).' + "\n")
    file_output.write("\n")
    file_output.write(':- solve(X), write(X), nl.' + "\n")


if __name__ == "__main__":
    raw = 0
    triples = []
    file_input = open("zad_input.txt").readlines()
    file_output = open("zad_output.txt", "w")
    for x in file_input:
        x = x.strip()
        if len(x) == 9:
            for i in range(9):
                if x[i] != '.':
                    triples.append( (raw,i,int(x[i])) ) 
            raw += 1          
    sudoku(triples)


"""
89.356.1.
3...1.49.
....2985.
9.7.6432.
.........
.6389.1.4
.3298....
.78.4....
.5.637.48

53..7....
6..195...
.98....6.
8...6...3
4..8.3..1
7...2...6
.6....28.
...419..5
....8..79

3.......1
4..386...
.....1.4.
6.924..3.
..3......
......719
........6
2.7...3..
"""
