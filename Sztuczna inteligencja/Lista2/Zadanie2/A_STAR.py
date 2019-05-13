import queue
import time
import copy
import sys
import heapq

# state == player_pos, chests, walls, goals, x, y, moves

VISITED = set()


def find_moves(state):
    result = []
    for i in range(2):  # 0 -> moving LEFT/RIGHT; 1 -> moving UP/DOWN
        for j in range(-1, 2, 2):
            player_pos = state[0]
            chests = copy.copy(state[1])
            walls = state[2]
            moves = copy.copy(state[6])
            moved = False
            if i == 0:
                new_pos = (player_pos[0], player_pos[1] + j)
                new_chest_pos = (player_pos[0], player_pos[1] + 2 * j)
            else:
                new_pos = (player_pos[0] + j, player_pos[1])
                new_chest_pos = (player_pos[0] + 2 * j, player_pos[1])
            if new_pos not in walls:
                if new_pos in chests and new_chest_pos not in chests and new_chest_pos not in walls:
                    chests.remove(new_pos)
                    chests.add(new_chest_pos)
                    player_pos = new_pos
                    moved = True
                elif new_pos not in chests:
                    player_pos = new_pos
                    moved = True
            if moved:
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
                new_state = [player_pos, chests, walls, state[3], state[4], state[5], moves]
                if (player_pos, tuple(chests)) not in VISITED:
                    VISITED.add((player_pos, tuple(chests)))
                    result.append(new_state)
    return result


def init():
    chests = set()
    goals = set()
    walls = set()
    file = open("zad_input.txt")
    lines = file.readlines()
    i = 0
    for y in lines:
        j = 0
        for x in y:
            if x == 'K':
                player_pos = (i, j)
            elif x == 'W':
                walls.add((i, j))
            elif x == 'B':
                chests.add((i, j))
            elif x == 'G':
                goals.add((i, j))
            elif x == '*':
                goals.add((i, j))
                chests.add((i, j))
            j += 1
        i += 1
    x = j
    y = i
    moves = []
    return player_pos, chests, walls, goals, x, y, moves


def print_maze(maze):
    x = maze[4]
    y = maze[5]
    player_pos = maze[0]
    chests = maze[1]
    goals = maze[3]
    walls = maze[2]
    for i in range (y):
        for j in range(x):
            if (i, j) == player_pos:
                sys.stdout.write('K')
            elif(i, j) in walls:
                sys.stdout.write('W')
            elif(i, j) in chests:
                if(i, j) in goals:
                    sys.stdout.write('*')
                else:
                    sys.stdout.write('B')
            elif(i, j) in goals:
                sys.stdout.write('G')
            else:
                sys.stdout.write('.')
        print()


def finished(state):
    chests = state[1]
    goals = state[3]
    for c in chests:
        if c not in goals:
            return False
    return True


def heur(state):
    goals = state[3]
    chests = state[1]
    player_pos = state[0]
    min_value = 999999999999
    for c in chests:
        for g in goals:
            act_dist = abs(c[0] - g[0]) + abs(c[1] - g[1])
            act_dist += abs(player_pos[0] - c[0]) + abs(player_pos[1] - c[1])
            min_value = min(act_dist, min_value)
    return min_value


def priority(state):
    return len(state[6]) + heur(state)


def convert(s):
    res = ""
    for x in s:
        res += x
    return res


# state == player_pos, chests, walls, goals, x, y, moves
def BFS(state):
    Q = []  # heap
    heapq.heappush(Q, (priority(state), state))
    VISITED.add((state[0], tuple(state[1])))
    while len(Q) > 0:
        new_states = find_moves(heapq.heappop(Q)[1])
        for s in new_states:
            if finished(s):
                file = open("zad_output.txt", "w+")
                file.write(convert(s[6]))
                return s
            else:
                heapq.heappush(Q, (priority(s), s))


obj = init()
start = time.time()
x = BFS(obj)
end = time.time()