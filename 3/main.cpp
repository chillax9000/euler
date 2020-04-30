/* The prime factors of 13195 are 5, 7, 13 and 29. */
/* What is the largest prime factor of the number 600851475143 ? */

#include <iostream>
#include <cmath>
#include <vector>

bool IsPrime(const long&, const std::vector<long>&);

int main() {
    long const number = 600851475143;
    long bound = (long) std::sqrt(number) + 1;
    std::vector<long> known_primes;

    for (long divisor = 2; divisor < bound; ++divisor) {
        if (number % divisor == 0) {
            if (IsPrime(divisor, known_primes)) known_primes.push_back(divisor);
        }
    }

    std::cout << known_primes.back() << std::endl;
}

bool IsPrime(const long& n, const std::vector<long>& smaller_primes) {
    for (long prime: smaller_primes) {
        if (n % prime == 0) return false;
    }
    return true;
}
