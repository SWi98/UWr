import random
import os
import sys
import copy
import queue
import time

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
    return tuple(current_sequence) in all_sequences


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
            j = i+1
            counter_of_ones = 1

            while j < n:
                if current_sequence[j] == 1:
                    counter_of_ones += 1
                    j += 1
                else:
                    j = n
                    test_list.append(counter_of_ones)

            if counter_of_ones in d_values:
                i += counter_of_ones
                d_values.remove(counter_of_ones)
            else:
                return False
        else:
            i += 1

    if len(d_values) == 0:
        return True
    else:
        return False

def opt_dist2(current_sequence, D_values):
    n = len(D_values)
    all_seq = []
    for i in range(n):



def opt_dist(current_sequence, D_values):
    fifo = queue.Queue()
    fifo.put(current_sequence)
    fifo_counter = queue.Queue()
    fifo_counter.put(0)
    if is_good(current_sequence, D_values):
        return 0
    checked_sequences = {tuple(current_sequence)}
    iter = 0
    while not fifo.empty():
        iter +=1
        seq = fifo.get()
        counter = fifo_counter.get()
        new_sequences = find_all_sequences(seq, checked_sequences)
        if iter % 10000 == 0:
            print(iter, seq)
        for i in range(0, len(new_sequences)):
            if is_good(new_sequences[i], D_values):
                print(new_sequences[i])
                return counter + 1
            else:
                checked_sequences.add(tuple(copy.deepcopy((new_sequences[i]))))
                fifo.put(new_sequences[i])
                fifo_counter.put(counter + 1)
    return False


#series = input()
#series = list(map(int, list(series)))
#D_attributes = input().split()
#D_attributes = list(map(int, list(input().split())))
x = time.time()
my_set ={1, 2}
opt_dist([0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [4])
opt_dist([0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [2, 7, 2])
#print(opt_dist([0, 0, 0, 1, 0, 0], [1]), opt_dist([0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [6]))
print(time.time() - x)