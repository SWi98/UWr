import copy
import random
import time


def NumberOfBits(NewSeries, GivenSeries):
    Count = 0
    for i in range(0, len(NewSeries)):
        if NewSeries[i] != GivenSeries[i]:
            Count += 1
    return Count


def opt_dist(sequence, D):
    for i in range(1, len(sequence)):
        sequence[i] += sequence[i-1]
    min_value = len(sequence) + 1
    k = 0

    while k + D - 1 < len(sequence):
        ones_before = 0
        if k > 0:
            ones_before = sequence[k-1]
        ones_after = sequence[len(sequence) - 1] - sequence[k + D - 1]
        ones_in_range = sequence[k + D - 1] - ones_before
        changes_needed = ones_before + ones_after + D - ones_in_range
        min_value = min(min_value, changes_needed)
        k += 1
    return min_value


def is_good(row, row_number):
    count = 0
    for j in range(0, len(row)):
        if row[j] == 1 and count > 0 and row[j-1] == 0:
            return False
        if row[j] == 1:
            count += 1
    return count == row_number


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

    if iter_ % 10 == 0:
        f = 1

    else:
        random_row = random.randint(0, r-1)
        while is_good(rows[random_row], rows[random_row]):
            random_row = random.randint(0, r - 1)

        max_pixel_value = -1
        max_index = -1

        for j in range(len(rows[random_row])):
            differences_before = opt_dist(columns[j], column_values[j]) \
                          + opt_dist(rows[random_row], row_values[random_row])
            change(random_row, j)
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
    while i < 300:
        mark_pixel(i)
        if is_done():
            for k in range(len(rows)):
                print(rows[k])
            return 0
        if i == 299:
            rows = [copy.deepcopy([0 for ind in range(c)]) for j in range(r)]
            columns = [copy.deepcopy([0 for ind in range(r)]) for j in range(c)]
            i = 0
        i += 1


r = int(input())
row_values = []
c = int(input())
column_values = []
one_line = []
pixels = []

for i in range(r):
    row_values.append(int(input()))

for i in range(c):
    column_values.append(int(input()))

rows = [copy.deepcopy([0 for ind in range(c)]) for j in range(r)]
columns = [copy.deepcopy([0 for i in range(r)]) for j in range(c)]

st = time.time()
start()
en = time.time()
print(en - st)




