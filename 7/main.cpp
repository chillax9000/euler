/* By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13. */
/* What is the 10 001st prime number? */

#include <iostream>
#include <vector>

bool isprime(int, const std::vector<int>&);

int main() {
    const int n_stop = 10001;
    std::vector<int> primes;
    for (int n=2; primes.size() < n_stop; ++n) {
        if (isprime(n, primes)) {
            primes.push_back(n);
        }
    }
    std::cout << primes.back() << " is the " << primes.size() 
              << "th prime number" << std::endl;
}

bool isprime(int n, const std::vector<int>& primes) {
    for (int prime: primes) {
        if (n % prime == 0) return false;
    }
    return true;
}
