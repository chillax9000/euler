/* The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17. */

/* Find the sum of all the primes below two million. */

#include <iostream>
#include <vector>
#include <algorithm>

const int N = 2000000;

int main() {
    const int N_ = N + 1;
    int candidates[N_];
    std::fill(candidates + 2, candidates + N_, 1);
    candidates[0] = 0;
    candidates[1] = 0;
    
    for (int i=2; i < N_; ++i) {
        if (candidates[i] == 1) {
            for (int j=2*i; j < N_; j += i) {
                candidates[j] = 0;
            }
        }
    }

    long sum = 0;
    for (int i=0; i < N_; ++i) {
        sum += candidates[i] * i ;
    }
    std::cout << sum << std::endl;
}

bool isprime(int, const std::vector<int>&);

void slowmain() {
    std::vector<int> primes;
    for (int n=3; n < N; n += 2) {
        if (isprime(n, primes)) {
            primes.push_back(n);
        }
    }
    long sum = 0;
    for (const int p: primes) sum += p;
    std::cout << sum << std::endl;
}

bool isprime(int n, const std::vector<int>& primes) {
    for (int prime: primes) {
        if (n % prime == 0) return false;
    }
    return true;
} 
