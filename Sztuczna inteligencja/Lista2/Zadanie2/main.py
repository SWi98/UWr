import copy
import queue
import sys

y_dir = [-1, 1]
x_dir = [-1, 1]


class State:
    player_pos = (0, 0)
    chests = set()
    walls = set()
    goals = set()
    moves = []
    X, Y = int, int
    mark = 0


def find_states(self):
    result = []
    if (self.moves == ['L', 'L', 'D', 'L']):
        print(self.moves)
        print(self.chests)
        print(self.goals)
        print(self.player_pos)
        print(type(self.player_pos), "<------------------------------")
        print_maze(self)
        print()
    for i in range(2):
        for j in range(-1, 2, 2):
            board = copy.deepcopy(self)
            board.moves = copy.deepcopy(self.moves)
            board.mark = copy.deepcopy(self.mark)
            board.player_pos = copy.deepcopy(self.player_pos)
            moved = False
            if i == 0:  # if we move in y direction
                new_pos = (board.player_pos[0] + j, board.player_pos[1])
                new_chest_pos = (board.player_pos[0] + j + j, board.player_pos[1])
            else:       # if we move in x direction
                new_pos = (board.player_pos[0], board.player_pos[1] + j)
                new_chest_pos = (board.player_pos[0], board.player_pos[1] + j + j)
            if new_pos not in board.walls:
                if (new_pos in board.chests and new_chest_pos not in board.walls
                        and new_chest_pos not in board.chests):  # if we can move a chest
                    board.player_pos = new_pos
                    board.chests.remove(new_pos)
                    board.chests.add(new_chest_pos)
                    moved = True
                elif new_pos not in board.chests:
                    moved = True
                    board.player_pos = new_pos

            if moved:
                if i == 0:
                    if j == -1:
                        board.moves.append('U')
                    elif j == 1:
                        board.moves.append("D")
                elif i == 1:
                    if j == -1:
                        board.moves.append('L')
                    elif j == 1:
                        board.moves.append("T")
                result.append(copy.deepcopy(board))
    if (self.moves == ['L', 'L', 'D', 'L']):
        print_maze(result[0])
        print()
        print_maze(result[1])
        print("--------------------")
    return result


def previously_checked(visited, new_state):
    for v in visited:
        if v[0] == new_state.player_pos and len(new_state.chests ^ v[1]) == 0:
            return True
    return False


def end(state):
    for chest in state.chests:
        if chest not in state.goals:
            return False
    return True


def print_maze(state):
    for i in range(state.Y+1):
        for j in range(state.X+1):
            if(i, j) in state.walls:
                sys.stdout.write('W')
            elif (i, j) in state.goals and (i, j) in state.chests:
                sys.stdout.write('*')
            elif (i, j) in state.goals:
                sys.stdout.write('G')
            elif (i, j) in state.chests:
                sys.stdout.write('B')
            elif (i, j) == state.player_pos:
                sys.stdout.write('K')
            else:
                sys.stdout.write('.')
        print()


def BFS(current_state):
    Q = queue.Queue()
    Q.put(current_state)
    visited = []
    visited.append(copy.deepcopy((copy.deepcopy(current_state.player_pos), copy.deepcopy(current_state.chests))))
    while not Q.empty():
        state_from_queue = Q.get()
        if(state_from_queue.moves == ['L', 'L', 'D', 'L']):
            print("||||||||||||||||||||||")
            print_maze(state_from_queue)
            print(state_from_queue.moves)
            print(state_from_queue.chests)
            print(state_from_queue.goals)
            print(state_from_queue.player_pos)
            print(state_from_queue.mark)
            print("||||||||||||||||||||||\n")
        new_states = find_states(state_from_queue)
        for s in new_states:
            if(s.moves == ['L', 'L', 'D', 'L', 'U'] or s.moves == ['L', 'L', 'D', 'L']):
                print("Wywołano w BFS:")
                print_maze(s)
                print(s.moves)
                print(s.chests)
                print(s.goals)
                print(s.player_pos)
                s.mark = 300
                print()
            if not previously_checked(visited, s):
                '''if (s.moves == ['L', 'L', 'D', 'L', 'U'] or s.moves == ['L', 'L', 'D', 'L']
                        or s.moves == ['L', 'L', 'D']):
                    print_maze(s)
                    print(s.moves)
                    print()'''
                if end(s):
                    print("KONIEC")
                    return s
                else:
                    Q.put(s)
                    visited.append(copy.deepcopy((copy.deepcopy(s.player_pos), copy.deepcopy(s.chests))))


def init():
    new_state = State()
    f = open("test3.txt")
    f1 = f.readlines()
    i = -1
    for y in f1:
        i += 1
        j = -1
        for x in y:
            j += 1
            if x == 'K':
                new_state.player_pos = (i, j)
            elif x == 'W':
                new_state.walls.add((i, j))
            elif x == 'B':
                new_state.chests.add((i, j))
            elif x == 'G':
                new_state.goals.add((i, j))
            elif x == '*':
                new_state.goals.add((i, j))
                new_state.chests.add((i, j))
    new_state.X = j
    new_state.Y = i
    return new_state


test = init()
print_maze(test)
print()
res = BFS(test)
#print_maze(res)
#print(res.moves)
#print(test.chests, "\n", test.goals, "\n", test.walls, "\n", test.player_pos)