import queue
import time
import copy
import sys

# state == player_pos, chests, walls, goals, x, y, moves

VISITED = set()


def find_moves(state):
    result = []
    for i in range(2):  # 0 -> moving LEFT/RIGHT; 1 -> moving UP/DOWN
        for j in range(-1, 2, 2):
            player_pos = state[0]
            chests = copy.deepcopy(state[1])
            walls = state[2]
            moves = copy.deepcopy(state[6])
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
    file = open("test3.txt")
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


# state == player_pos, chests, walls, goals, x, y, moves
def BFS(state):
    Q = queue.Queue()
    Q.put(state)
    VISITED.add((state[0], tuple(state[1])))
    while not Q.empty():
        new_states = find_moves(Q.get())
        for s in new_states:
            #if(s[6] == ['L', 'L', 'D', 'L', 'U']):
           #     print_maze(s)
           #     print(s[6])
           #     print()
            if finished(s):
                return s
            else:
                Q.put(s)



obj = init()
print_maze(obj)
print()
start = time.time()
x = BFS(obj)
end = time.time()

print(len(x[6]))
print(end - start)