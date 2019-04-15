import random
import os
import sys
import copy
import queue


def get_value(cart):
    if cart[0] == 'J':
        value = 11
    elif cart[0] == 'Q':
        value = 12
    elif cart[0] == 'K':
        value = 13
    elif cart[0] == 'A':
        value = 14
    else:
        value = int(cart[0])
    return value


def first_bigger(fst_cart, snd_cart):
    return get_value(fst_cart) > get_value(snd_cart)


def sort_hand(hand):
    for i in range(5):
        for j in range(5-i-1):
            if first_bigger(hand[j], hand[j+1]):
                hand[j], hand[j+1] = hand[j+1], hand[j]
    return hand


def draw_and_compare(blotkarz_deck, figurant_deck):
    blotkarz_hand = []
    figurant_hand = []
    blotkarz_deck = copy.deepcopy(blotkarz_deck)
    figurant_deck = copy.deepcopy(figurant_deck)
    for i in range(5):
        bx = random.randint(0, len(blotkarz_deck)-1)
        fx = random.randint(0, len(figurant_deck)-1)
        blotkarz_hand.append(blotkarz_deck[bx])
        figurant_hand.append(figurant_deck[fx])
        del blotkarz_deck[bx]
        del figurant_deck[fx]
    #print(blotkarz_hand)
    print(sort_hand(blotkarz_hand))
    #print(figurant_hand)
    print(sort_hand(figurant_hand))
    return compare(blotkarz_hand, figurant_hand)


# works
def str_flush_or_color_or_str(hand):
    hand = sort_hand(hand)
    is_color = True
    is_straight = True
    color = hand[4][1]
    for i in range(4):
        if get_value(hand[i]) != (get_value(hand[i+1]) + -1):
            is_straight = False
            break
    for i in range(4):
        if hand[i][1] != color:
            is_color = False
            break
    if is_color and is_straight:
        return 8
    elif is_color:
        return 5
    elif is_straight:
        return 4
    return 0


# How many unique carts are in the hand (doesn't take into account the colors)
def unique(hand):
    hand_values = []
    for i in range(5):
        value = get_value(hand[i])
        if value not in hand_values:
            hand_values.append(value)
    return len(hand_values)


def is_four(hand):
    if unique(hand) == 2:
        return 7
    return 0


def is_full(hand):
    if unique(hand) == 2 and is_pair(hand) == 1 and is_three(hand) == 3:
        return 6
    return 0


def is_three(hand):
    if unique(hand) == 3 and is_two_pairs(hand) != 2:
        return 3
    return 0


def is_two_pairs(hand):
    count = 0
    for i in range(4):
        for j in range(i+1, 5):
            if hand[i][0] == hand[j][0]:
                count += 1
    if count == 2 and unique(hand) == 3:
        return 2
    return 0


def is_pair(hand):
    if unique(hand) == 4:
        return 1
    return 0


def compare(blotkarz_hand, figurant_hand):
    blotkarz_value = max(str_flush_or_color_or_str(blotkarz_hand), is_four(blotkarz_hand),
                         is_four(blotkarz_hand), is_three(blotkarz_hand), is_two_pairs(blotkarz_hand),
                         is_pair(blotkarz_hand), is_full(blotkarz_hand))
    figurant_value = max(str_flush_or_color_or_str(figurant_hand), is_four(figurant_hand),
                         is_four(figurant_hand), is_three(figurant_hand), is_two_pairs(figurant_hand),
                         is_pair(figurant_hand), is_full(figurant_hand))
    print("Blotkarz:", blotkarz_value, "Figurant:", figurant_value)
    return figurant_value >= blotkarz_value


# spades (♠), clubs (♣), hearts (♥), and  diamonds (♦)
'''Bl_deck = ['2s', '2c', '2h', '2d', '3s', '3c', '3h', '3d', '4s', '4c',
           '4h', '4d', '5s', '5c', '5h', '5d', '6s', '6c', '6h', '6d', '7s', '7c', '7h',
           '7d', '8s', '8c', '8h', '8d', '9s', '9c', '9h', '9d', '10s', '10c', '10h', '10d']'''

Fi_deck = ['Js', 'Jc', 'Jh', 'Jd', 'Qs', 'Qc', 'Qh', 'Qd',
           'Ks', 'Kc', 'Kh', 'Kd', 'As', 'Ac', 'Ah', 'Ad']
Bl_deck = ['2s', '3s', '4s', '5s', '6s', '7s', '8s', '9s', '10s']

Blotkarz_count = 0
Figurant_count = 0
for i in range(10000):
   # print(draw_and_compare(Bl_deck, Fi_deck))
    if draw_and_compare(Bl_deck, Fi_deck):
        Figurant_count += 1
    else:
        Blotkarz_count +=1
print(Figurant_count, Blotkarz_count)


