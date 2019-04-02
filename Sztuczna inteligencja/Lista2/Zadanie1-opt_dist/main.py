import random
import os
import sys
import time
import copy
import queue


def find_all_sequences(sequence, all_sequences):
    all_sequences = []

    def change_bit_on_pos(k):
        if sequence[k] == 0:
            current[k] = 1
        else:
            current[k] = 0

    for i in range(len(sequence)):
        current = sequence
        change_bit_on_pos(i)
        if not tested_before(current, all_sequences):
            all_sequences.append(copy.deepcopy(current))
        change_bit_on_pos(i)

    return all_sequences


def tested_before(current_sequence, all_sequences):
    for i in range(0, len(all_sequences)):
        if all_sequences[i] == current_sequence:
            return True
    return False


def is_good(current_sequence, d_values):
    d_values = copy.deepcopy(d_values)
    n = len(current_sequence)
    i = 0
    test_list = []

    # When we don't want any 1s in our sequence
    if len(d_values) == 1 and d_values[0] == 0:
        for i in range(n):
            if current_sequence[i] == 1:
                return False
        return True

    while i < n:
        if current_sequence[i] == 1:
            if len(d_values) == 0:
                return False
            j = i+1
            counter_of_ones = 1

            while j < n:

                if current_sequence[j] == 1:
                    counter_of_ones += 1
                    j += 1
                else:
                    j = n
                    test_list.append(counter_of_ones)

            if counter_of_ones == d_values[0]:
                i += counter_of_ones
                del d_values[0]
            else:
                return False
        else:
            i += 1

    if len(d_values) == 0:
        return True
    else:
        return False


def opt_dist(current_sequence, D_values):
    fifo = queue.Queue()
    fifo.put(current_sequence)
    fifo_counter = queue.Queue()
    fifo_counter.put(0)
    if is_good(current_sequence, D_values):
        return 0
    checked_sequences = [current_sequence]

    while not fifo.empty():
        seq = fifo.get()
        counter = fifo_counter.get()
        new_sequences = find_all_sequences(seq, checked_sequences)
        for i in range(0, len(new_sequences)):
            if is_good(new_sequences[i], D_values):
                return counter + 1
            else:
                checked_sequences.append(new_sequences[i])
                fifo.put(new_sequences[i])
                fifo_counter.put(counter + 1)
    return False


def is_done():
    global rows, columns, row_values, column_values
    for i in range(len(rows)):
        if not is_good(rows[i], row_values[i]):
            return False
    for i in range(len(columns)):
        if not is_good(columns[i], column_values[i]):
            return False

    return True


def mark_pixel(iter_):
    global rows, columns, row_values, column_values

    def change(row, jj):
        if columns[jj][row] == 1:
            columns[jj][row] = 0
            rows[row][jj] = 0
        else:
            columns[jj][row] = 1
            rows[row][jj] = 1

    if iter_ % 5 == 0:
        change(random.randint(0, r-1), random.randint(0, c-1))

    else:
        random_row = random.randint(0, r-1)
        while is_good(rows[random_row], rows[random_row]):
            random_row = random.randint(0, r - 1)

        max_pixel_value = -1
        max_index = -1
        for j in range(len(rows[random_row])):
            print(columns[j], column_values[j], rows[random_row], row_values[random_row])
            differences_before = opt_dist(columns[j], column_values[j]) \
                          + opt_dist(rows[random_row], row_values[random_row])

            change(random_row, j)
            print(columns[j], column_values[j], rows[random_row], row_values[random_row])
            differences = opt_dist(columns[j], column_values[j]) \
                          + opt_dist(rows[random_row], row_values[random_row])

            if differences_before - differences > max_pixel_value:
                max_pixel_value = differences_before - differences
                max_index = j
            change(random_row, j)
        change(random_row, max_index)


def start():
    global rows, columns, row_values, column_values
    i = 0
    while i < 200:
        mark_pixel(i)
        if is_done():
            for k in range(len(rows)):
                print(rows[k])
            return 0
        if i == 199:
            print(i)
            rows = [copy.deepcopy([0 for _ in range(c)]) for _ in range(r)]
            columns = [copy.deepcopy([0 for _ in range(r)]) for _ in range(c)]
            i = 0
        i += 1


attributes = list(map(int, list(input().split())))
r = attributes[0]
c = attributes[1]
row_values = []
column_values = []
one_line = []
pixels = []

for i_ in range(r):
    row_values.append(list(map(int, list(input().split()))))

for i_ in range(c):
    column_values.append(list(map(int, list(input().split()))))

rows = [copy.deepcopy([0 for ind in range(c)]) for j in range(r)]
columns = [copy.deepcopy([0 for i in range(r)]) for j in range(c)]

print(row_values)
print(column_values)
st = time.time()
start()
end = time.time()
print(end - st)