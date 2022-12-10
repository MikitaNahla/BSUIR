from itertools import combinations

from collections import Counter
from random import sample

import re
def Create():
    _set = set()
    print('Введите мощность множества ')
    m = int(input())
    print('Введите элементы множества ')
    for i in range(0, m):
        _input(_set)
    list = []
    for item in _set:
        list.append(item)
    return list

def print_set(my_set):
    print('Множество ', end=' {')
    for item in my_set:
        if item != my_set[len(my_set) - 1]:
            print(item, end=', ')
        else:
            print(item, end='')
    print('}')

def diff_sets(set1, set2):
    temp_set = set1
    l1 = len(set1)
    l2 = len(set2)
    i = 0
    for i in range(l1):
        j = 0
        for j in range(l2):
            if (temp_set[i] == set2[j]):
                temp = set1[i]
                temp_set.remove(temp)
                l_temp = l1
                l1 = l_temp - 1
    return temp_set

#regular expression
def check(inp):
    pattern = r'[a-zA-Z0-9]+'
    tmp_list = []
    inp = inp.split('{')[1]
    inp = inp.rsplit('}')[0]
    for word in inp.split(','):
        if re.search(pattern, word):
            tmp_list.append(word)
    return sorted(tmp_list)

def correct_input(inp):
    pattern = r'[a-zA-Z0-9<>,]'
    for char in inp:
        if re.search(pattern, char):
            res = True
        else:
            return False
    return res

def _input(_set):
    inp = str(input())
    if inp[0] == "{":
        tmp_list = check(inp)
        s = '{'
        for item in tmp_list:
            if item != tmp_list[len(tmp_list) - 1]:
                s += str(item) + ', '
            else:
                s += str(item)
        s += '}'
        _set.add(s)
    elif correct_input(inp):
        _set.add(inp)
        return
    else:
        print('Введите корректное значение:')
        _input(_set)

#Main

set1 = Create()
print_set(set1)
set2 = Create()
print_set(set2)
print('Результат разности двух множеств ')
print_set(diff_sets(set1, set2))