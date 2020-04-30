/* 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder. */
/* What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20? */

#include <iostream>
#include <vector>

bool isprime(int, const std::vector<int>&);

int main() {
    int N = 20;
    std::vector<int> primes;
    int product = 1;

    for (int i=2; i <= N; ++i) {
        if (isprime(i, primes)) {
            primes.push_back(i);
            int j = i;
            while (j * i < N) {
                j *= i;
            }
            product *= j;
        }
    }
    std::cout << product << std::endl;
}

bool isprime(int n, const std::vector<int>& primes) {
    for (int prime: primes) {
        if (n % prime == 0) return false;
    }
    return true;
}
