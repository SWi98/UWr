
def B(i, j):
    return 'B_%d_%d' % (i, j)


def storms(rows, cols, triples):
    writeln(':- use_module(library(clpfd)).')
    
    R = len(rows)
    C = len(cols)
    
    bs = [B(i, j) for i in range(R) for j in range(C)]
    
    writeln('solve([' + ', '.join(bs) + ']) :- ')
    writeln('[' + ', '.join(bs) + '] ins 0..1,')

    # every row has to sum into right number
    for counter, r_value in enumerate(rows):
        rs = [B(counter, j) for j in range(C)]
        writeln('sum([' + ', '.join(rs) + '], #=, ' + str(r_value) + '), ')

    # every column has to sum into right number
    for counter, c_value in enumerate(cols):
        cs = [B(j, counter) for j in range(R)]
        writeln('sum([' + ', '.join(cs) + '], #=, ' + str(c_value) + '), ')

    # A + D = 2 <=> B + C = 2
    for i in range(R - 1):
        for j in range(C - 1):
            A = B(i, j)
            B2 = B(i, j+1)
            C2 = B(i + 1, j)
            D = B(i + 1, j + 1)
            writeln(A + ' + ' + D + ' #= 2 #<==> ' + B2 + ' + ' + C2 + ' #= 2, ')

    # B = 1 => A + C > 0 for rows
    for i in range(R):
        for j in range(C - 2):
            A = B(i, j)
            B2 = B(i, j + 1)
            C2 = B(i, j + 2)
            writeln(B2 + ' #= 1 #==> ' + A + ' + ' + C2 + ' #>= 1, ')

    # B = 1 => A + C > 0 for columns
    for i in range(C):
        for j in range(R - 2):
            A = B(i, j)
            B2 = B(i, j + 1)
            C2 = B(i, j + 2)
            writeln(B2 + ' #= 1 #==> ' + A + ' + ' + C2 + ' #>= 1, ')

    for triple in triples:
        output.write('%s #= %d, ' % (B(triple[0], triple[1]), triple[2]))

    writeln('')
    writeln('    labeling([ff], [' + ', '.join(bs) + ']).')
    writeln('')
    writeln(':- solve(X), write(X), nl.')
    #writeln(":- tell('prolog_result.txt'), solve(X), write(X), nl, told.")


def writeln(s):
    output.write(s + '\n')

txt = open('zad_input.txt').readlines()
output = open('zad_output.txt', 'w')

rows = list(map(int, txt[0].split()))
cols = list(map(int, txt[1].split()))
triples = []

for i in range(2, len(txt)):
    if txt[i].strip():
        triples.append(list (map(int, txt[i].split())))


storms(rows, cols, triples)
