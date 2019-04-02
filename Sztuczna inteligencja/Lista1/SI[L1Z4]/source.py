import random
import os
import sys
import copy
import queue


def FindSequences(S):
    ListOfSequences = []
    for i in range(0, len(S)):
        ListOfSequences.append(copy.deepcopy(S))
        if ListOfSequences[i][i] == '0':
            ListOfSequences[i][i] = '1'
        else:
            ListOfSequences[i][i] = '0'
    return ListOfSequences


def IsTested(AllSeq, Seq):
    for i in range(0, len(AllSeq)):
        if AllSeq[i] == Seq:
            return True
    return False


def IsGood(Seq, D):
    for i in range(0, len(Seq)):

        if Seq[i] == '1':
            if i + D-1 >= len(Seq):
                return False

            # Checking if there are D '1s' starting from index i
            for j in range(i+1, i+D):
                if Seq[j] == '0':
                    return False

            # Checking, if there are any other '1s' in this list, apart from our D-length series
            for j in range(i+D, len(Seq)):
                if Seq[j] == '1':
                    return False

            return True
    return D == 0   # If there were no '1s' in the series


def RemoveRepeating(AllSeries, SeqList):
    IndexesToRemove = []
    for i in range(0, len(SeqList)):
        if IsTested(AllSeries, SeqList[i]):
            IndexesToRemove.append(i)
    for i in range(len(IndexesToRemove)-1, -1, -1):
        del SeqList[IndexesToRemove[i]]
    del IndexesToRemove
    return SeqList


def Steps(Res, Seq):
    Counter = 0
    for i in range(0, len(Res)):
        if Res[i]!=Seq[i]:
            Counter+=1
    return Counter

def opt_dist(Series, D):
    FIFO = queue.Queue()
    FIFO.put(Series)
    FIFO_counter = queue.Queue()
    FIFO_counter.put(0)
    if IsGood(Series, D):
        return 0
    CheckedSeries = [Series]
    while not FIFO.empty():
        seq = FIFO.get()
        Counter = FIFO_counter.get()
        #print(CheckedSeries)
        NewSeq = RemoveRepeating(CheckedSeries, FindSequences(seq))
        for i in range(0, len(NewSeq)):
            if IsGood(NewSeq[i], D):
                print(NewSeq[i])
                return Counter+1  #Steps(NewSeq[i], Series)
            else:
                CheckedSeries.append(NewSeq[i])
                FIFO.put(NewSeq[i])
                FIFO_counter.put(Counter + 1)
    return False

series = input()
series = list(series)
D = int(input())
