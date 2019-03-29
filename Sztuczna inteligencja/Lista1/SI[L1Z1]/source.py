import copy
import queue

boardX = {'a': '1', 'b': '2', 'c': '3', 'd': '4', 'e': '5', 'f': '6', 'g': '7', 'h': '8'}
boardX2 ={1: 'a', 2: 'b', 3: 'c', 4: 'd', 5: 'e', 6: 'f', 7: 'g', 8: 'h'}


def in_board(x, y):
    return not(x > 8 or x < 1 or y > 8 or y < 1)


def not_neighbor(a_x, a_y, b):
    if a_x == b[0] and a_y == b[1]:
        return False
    for i in range(-1, 2):
        for j in range(-1, 2):
            if a_x == b[0]+i and a_y == b[1]+j:
                return False
    return True


def find_moves(player, white_king, rook, black_king):
    if player == "white":
        current = white_king
        other = black_king
    else:
        current = black_king
        other = white_king
    res = []
    for i in range(-1, 2):
        for j in range(-1, 2):
            current_x = current[0] + i
            current_y = current[1] + j
            # checking if the king will be in the board, won't be neighbor with the second king,
            # won't be in the same row or column as the rook (if we move black king)
            # and won't be in the same position as the rook (if we move white king)
            if (not(i == 0 and j == 0) and in_board(current_x, current_y)
                    and not_neighbor(current_x, current_y, other)
                    and not(player == "black" and (current_x == rook[0]
                                                   or current_y == rook[1]))
                    and not(player == "white" and (current_x == rook[0]
                                                   and current_y == rook[1]))):
                res.append(copy.deepcopy(current))
                res[len(res) - 1][0] += i
                res[len(res) - 1][1] += j

    if player == "black":
        if len(res) == 0 and (black_king[0] == rook[0] or black_king[1] == rook[1]):
            return [[-1]]
        elif len(res) == 0:
            return [[-2]]
        return res
    res2 = []

    for i in range(0, 2):
        for j in range(-7, 8):
            # Checking if we move horizontal (i=0) or vertical (i=1)
            if i == 0:
                rook_x = rook[0] + j
                rook_y = rook[1]
            else:
                rook_x = rook[0]
                rook_y = rook[1] + j
            # Checking if rook will be in board, black king won't be able to beat rook
            # and rook won't be in the same position as the white king
            if (j != 0 and in_board(rook_x, rook_y)
                and not(not_neighbor(rook_x, rook_y, white_king)
                        and not not_neighbor(rook_x, rook_y, black_king))
                    and not(rook_x == white_king[0] and rook_y == white_king[1])):
                new_rook = [copy.deepcopy(rook_x), copy.deepcopy(rook_y)]
                res2.append(new_rook)
    return {'king': res, 'rook': res2}


def translate_and_start(player, white_king, rook, black_king):
    for i in range(0):
        if(i == 0):
            current = white_king
            res =[]
        if(current[0] == 'a'):
            current[0] = 1


def opt_dist(player, white_king, rook, black_king):
    pos = [white_king, rook, black_king, player]
    fifo = queue.Queue()
    fifo.put(pos)
    fifo_counter = queue.Queue()
    fifo_counter.put(0)
    all_moves = {}
    all_positions = set()
    while not fifo.empty():
        pos = fifo.get()
        player = pos[3]
        counter = fifo_counter.get()
        new_pos = find_moves(player, pos[0], pos[1], pos[2])
        if player == "black" and new_pos[0][0] == -1: # == checkmate
            return counter, pos, all_moves
        elif player == "white":
            player = "black"
            white_king_pos = new_pos['king']
            rook_pos = new_pos['rook']

            # Adding new position to the dictionary containing all checked positions
            for i in range(0, len(white_king_pos)):
                position = (white_king_pos[i][0], white_king_pos[i][1], pos[1][0], pos[1][1],
                            pos[2][0], pos[2][1])
                position_as_list = [white_king_pos[i], pos[1], pos[2], player]
                if position not in all_positions:
                    all_positions.add(position)
                    all_moves[copy.deepcopy(position)] = copy.deepcopy(pos)
                    fifo.put(copy.deepcopy(position_as_list))
                    fifo_counter.put(counter + 1)

            for i in range(0, len(rook_pos)):
                position = (pos[0][0], pos[0][1], rook_pos[i][0], rook_pos[i][1], pos[2][0], pos[2][1])
                position_as_list = [pos[0], rook_pos[i], pos[2], player]
                if position not in all_positions:
                    all_moves[copy.deepcopy(position)] = copy.deepcopy(pos)
                    all_positions.add(position)
                    fifo.put(copy.deepcopy(position_as_list))
                    fifo_counter.put(counter + 1)

        elif new_pos != [[-2]]:
            player = "white"
            for i in range(0, len(new_pos)):
                position = (pos[0][0], pos[0][1], pos[1][0], pos[1][1], new_pos[i][0], new_pos[i][1])
                position_as_list = [pos[0], pos[1], new_pos[i], player]
                if position not in all_positions:
                    all_positions.add(position)
                    all_moves[copy.deepcopy(position)] = copy.deepcopy(pos)
                    fifo.put(copy.deepcopy(position_as_list))
                    fifo_counter.put(counter + 1)

    return False


def translate_to_tuple(d):
    d = (d[0][0], d[0][1], d[1][0], d[1][1], d[2][0], d[2][1])
    return d


def translate_to_ints(w_king, rook, b_king):
    w_king = list(w_king)
    w_king[0] = boardX[w_king[0]]
    w_string = ""
    w_string = w_string + w_king[0] + w_king[1]
    rook = list(rook)
    rook[0] = boardX[rook[0]]
    r_string = ""
    r_string = r_string + rook[0] + rook[1]
    b_king = list(b_king)
    b_king[0] = boardX[b_king[0]]
    b_string = ""
    b_string = b_string + b_king[0] + b_king[1]
    return w_king, rook, b_king


def translate_to_string(position):
    r = ""
    r = r + boardX2[position[0]] + str(position[1]) + " " + boardX2[position[2]] + str(position[3])
    r = r + " " + boardX2[position[4]] + str(position[5])
    return r


file = open("dane.txt", "r")
for line in file:
    file2 = open("result.txt", "w")
    print("\n", line)
    move, white_king, white_rook, black_king = line.split()
    current_pos = translate_to_ints(white_king, white_rook, black_king)
    white_king = list(map(int, current_pos[0]))
    white_rook = list(map(int, current_pos[1]))
    black_king = list(map(int, current_pos[2]))
    x = opt_dist(move, white_king, white_rook, black_king)
    print(str(x[0]))
    dict = x[2]
    d = x[1]
    d = translate_to_tuple(d)
    result = []
    for i in range(0, x[0]):
        result.append(translate_to_string(d))
        d = translate_to_tuple(dict[d])
    for i in reversed(result):
        print(i)
