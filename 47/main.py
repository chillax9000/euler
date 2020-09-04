# The first two consecutive numbers to have two distinct prime factors are:

# 14 = 2 × 7
# 15 = 3 × 5

# The first three consecutive numbers to have three distinct prime factors are:

# 644 = 2² × 7 × 23
# 645 = 3 × 5 × 43
# 646 = 2 × 17 × 19.

# Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?


def decompose(n, primes, decompositions):
    for p in primes:
        if n % p == 0:
            dec = {p}
            dec.update(decompositions[n // p])
            decompositions[n] = dec
            return dec
    # n prime
    dec = {n}
    primes.add(n)
    decompositions[n] = dec
    return dec

decompositions = {}
primes = set()
last_nfactors = [None for _ in range(4)]
n = 2
while True: 
    n_factors = len(decompose(n, primes, decompositions))
    
    last_nfactors[:-1] = last_nfactors[1:]
    last_nfactors[-1] = n_factors

    if all(n_f == 4 for n_f in last_nfactors):
        for k in range(n - 3, n + 1):
            print(k, "->", decompositions[k])
        break

    n += 1
