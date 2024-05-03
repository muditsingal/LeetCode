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

    for i in range(2,int(np.sqrt(num))+1):
        if num % i == 0:
            return False
    return True

def find_primes(n):
    primes = []
    for i in range(2,n+1):
        if is_prime_sqrt(i):
            primes.append(i)

    return primes

def find_primes_vec(n):
    primes = []
    is_prime = True
    for i in range(2,n+1):
        is_prime = True
        i_sq = np.sqrt(i)
        for prime in primes:
            if i % prime == 0:
                is_prime = False
                break
            if prime > i_sq:
                break
        if is_prime:
            primes.append(i)
    return primes

if __name__ == "__main__":
    # n = 1000000
    n = 1000000
    start_time = time.time()
    # prime_list = find_primes(n)
    prime_list = find_primes_vec(n)
    end_time = time.time()
    
    # print("The prime numbers upto N are:", prime_list)
    print("Time to find primes: ", round(end_time - start_time, 6), "seconds")
