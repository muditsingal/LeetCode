import numpy as np
import time

def factorial_loop(num):
    fact = 1
    for i in range(1,num+1):
        fact = fact * i
    return fact

def factorial_recurr(num):
    if num <= 1:
        return 1
    return num*factorial_recurr(num-1)

if __name__ == "__main__":
    n = 5
    print("The factorial is: ", factorial_loop(n))
    print("The factorial by recurrsion is: ", factorial_recurr(n))