# The following iterative sequence is defined for the set of positive integers:

# n → n/2 (n is even)
# n → 3n + 1 (n is odd)

# Using the rule above and starting with 13, we generate the following sequence:
# 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

# It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

# Which starting number, under one million, produces the longest chain?

# NOTE: Once the chain starts the terms are allowed to go above one million.


def next_(n):
    if n % 2 == 0:
        return n // 2
    else:
        return 3*n + 1

def length_of(n, lengths):
    cur_len = 0
    while n != 1:
        if n in lengths:
            return cur_len + lengths[n]
        n = next_(n)
        cur_len += 1

    return cur_len + 1

lengths = {}

i_max = 0
l_max = 0
for i in range(1, 1000000):
    l = length_of(i, lengths)
    if i not in lengths:
        lengths[i] = l
    if l > l_max:
        l_max = l
        i_max = i

print(f"max length ({l_max}) for {i_max}")
