import numpy as np
import time
import copy

bracket_map = {'}':'{', ')':'(', ']':'['}

def find_valid_brackets(s):
    stk = []
    for c in s:
        if c not in(bracket_map):
            stk.append(c)
            continue
            
        elif len(stk) == 0:
            return False
        elif bracket_map[c] != stk[-1]:
            return False
        stk.pop()

    if len(stk) == 0:
        return True

    return False

if __name__ == '__main__':
    input_str = '{[]()}'
    print(find_valid_brackets(input_str))
    print("main")