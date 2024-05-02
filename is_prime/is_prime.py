import numpy as np
import time

def is_prime_linear(num):
    if num <= 1:
        return False

    for i in range(2, (num//2)+1):
        if num % i == 0:
            return False

    return True

def is_prime_sqrt(num):
    if num <= 1:
        return False
    n_sq = int(np.sqrt(num))
    for i in range(2, n_sq+1):
        if num % i == 0:
            return False
    return True


if __name__ == "__main__":
    n = 111781
    start = time.time()
    if is_prime_sqrt(n):
        print("The number", n, "is prime")
    else:
        print("The number", n, "is not prime")

    end = time.time()
    print("Time taken is:", round(end-start, 6), "seconds")
