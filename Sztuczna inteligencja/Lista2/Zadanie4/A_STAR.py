import queue
import time
import copy
import sys
import itertools
import heapq

# state == player_pos, goals, walls, x, y, moves
VISITED = set()


def init():
    goals = set()
    walls = set()
    player_pos = []
    file = open("zad_input.txt ")
    lines = file.readlines()
    i = 0
    for y in lines:
        j = 0
        for x in y:
            if x == 'S':
                player_pos.append((i, j))
            elif x == '#':
                walls.add((i, j))
            elif x == 'G':
                goals.add((i, j))
            elif x == 'B':
                goals.add((i, j))
                player_pos.append((i, j))
            j += 1
        i += 1
    x = j
    y = i
    moves = []
    return player_pos, goals, walls, x, y, moves


def print_maze(maze):
    x = maze[3]
    y = maze[4]
    player_pos = maze[0]
    goals = maze[1]
    walls = maze[2]
    for i in range(y):
        for j in range(x):
            if (i, j) in player_pos and (i, j) in goals:
                sys.stdout.write('B')
            elif (i, j) in player_pos:
                sys.stdout.write('S')
            elif(i, j) in walls:
                sys.stdout.write('#')
            elif(i, j) in goals:
                sys.stdout.write('G')
            else:
                sys.stdout.write(' ')
        print()


def finished(state):
    player_pos = state[0]
    goals = state[1]
    for pos in player_pos:
        if pos not in goals:
            return False
    return True


def right20(state):
    player_pos = state[0]
    walls = state[2]
    for i in range(20):
        for j in range(len(player_pos)):
            pos = player_pos[j]
            new_pos = (pos[0], pos[1] + 1)
            if new_pos not in walls:
                player_pos[j] = new_pos

        state[5].append('R')

def left20(state):
    player_pos = state[0]
    walls = state[2]
    for i in range(20):
        for j in range(len(player_pos)):
            pos = player_pos[j]
            new_pos = (pos[0], pos[1] -1)
            if new_pos not in walls:
                player_pos[j] = new_pos
        state[5].append('L')

def up20(state):
    player_pos = state[0]
    walls = state[2]
    for i in range(20):
        for j in range(len(player_pos)):
            pos = player_pos[j]
            new_pos = (pos[0] - 1, pos[1])
            if new_pos not in walls:
                player_pos[j] = new_pos
        state[5].append('U')

def down20(state):
    player_pos = state[0]
    walls = state[2]
    for i in range(20):
        for j in range(len(player_pos)):
            pos = player_pos[j]
            new_pos = (pos[0]+1, pos[1])
            if new_pos not in walls:
                player_pos[j] = new_pos
        state[5].append('D')

def random_moves(state, perm):
    for x in perm:
        if x == 'U':
            up20(state)
            merge_positions(state)
        elif x == 'D':
            down20(state)
            merge_positions(state)
        elif x == 'L':
            left20(state)
            merge_positions(state)
        elif x == 'R':
            right20(state)
            merge_positions(state)


def merge_positions(state):
    player_pos = state[0]
    sorted_pos = list(sorted(player_pos))
    for i in range(len(sorted_pos)-1):
        if sorted_pos[i] == sorted_pos[i+1]:
            player_pos.remove(sorted_pos[i])


# state == player_pos, goals, walls, x, y, moves
def find_moves(state):
    walls = state[2]
    result = []
    for i in range(2):  # 0 -> moving in LEFT/RIGHT; 1 -> moving in UP/DOWN
        for j in range(-1, 2, 2):
            player_pos = []
            moves = copy.copy(state[5])
            for k in range(len(state[0])):
                old_pos = state[0][k]
                if i == 0:
                    new_pos = (state[0][k][0], state[0][k][1] + j)
                else:
                    new_pos = (state[0][k][0] + j, state[0][k][1])
                if new_pos not in walls:
                    player_pos.append(new_pos)
                else:
                    player_pos.append(copy.copy(old_pos))
            if i == 0:
                if j == 1:
                    moves.append('R')
                else:
                    moves.append('L')
            else:
                if j == 1:
                    moves.append('D')
                else:
                    moves.append('U')
            new_state = [player_pos, state[1], state[2], state[3], state[4], moves]
            merge_positions(new_state)
            if tuple(player_pos) not in VISITED:
                VISITED.add(tuple(player_pos))
                result.append(new_state)
    return result


def find_best_start(st):
    all_sequences = list(itertools.permutations(['U', 'L', 'D', 'R']))
    minPositions = 999999999
    for seq in all_sequences:
        test_state = [copy.deepcopy(st[0]), st[1], st[2], st[3], st[4], copy.deepcopy(st[5])]
        random_moves(test_state, seq)
        if minPositions > len(test_state[0]):
            minPositions  = len(test_state[0])
            best = test_state
    return best


def convert(stat):
    res = ""
    for x in stat:
        res += x
    return res


def priority(state):
    return 1


# state == player_pos, goals, walls, x, y, moves
'''def BFS(state):
    Q = []
    state = find_best_start(state)
    heapq.heappush(Q, (priority(state), state))
    VISITED.add(tuple(state[0]))
    while not Q.empty():
        new_states = find_moves(Q.get())
        for st in new_states:
            if finished(st):
                file = open("zad_output.txt", "w+")
                file.write(convert(st[5]))
                return st
            else:
                Q.put(st)'''


def BFS(state):
    Q = []  # heap
    find_best_start(state)
    heapq.heappush(Q, (priority(state), state))
    VISITED.add(tuple(state[0]))
    iter = 0
    while len(Q) > 0:
        iter += 1
        new_states = find_moves(heapq.heappop(Q)[1])
        for s in new_states:
            if finished(s):
                file = open("zad_output.txt", "w+")
                file.write(convert(s[6]))
                return s
            else:
                heapq.heappush(Q, (priority(s), s))


s = init()
BFS(s)
