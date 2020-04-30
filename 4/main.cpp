/* A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99. */
/* Find the largest palindrome made from the product of two 3-digit numbers. */

#include <iostream>
#include <vector>

bool IsPalindrome(int);
bool IsDoubly3DigitDivisible(const int&);
inline bool Is3Digit(const int&);

int main() {
    int n;
    for (n = 999*999; n > 100*100; --n) {
        if (IsPalindrome(n) && IsDoubly3DigitDivisible(n)) break;
    }
    if (n != 100*100) {
        std::cout << n << std::endl;
    }
}

bool IsPalindrome(int n) {
    std::vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10; 
    }
    int mid = (int) (digits.size() / 2);
    for (int i=0; i < mid; ++i) {
        if (digits[i] != digits[digits.size() - 1 - i]) return false;
    }
    return true;
}

inline bool Is3Digit(const int& n) {
    return 99 < n && n < 1000;
}

bool IsDoubly3DigitDivisible(const int& n) {
    for (int i=100; i < 1000; ++i) {
        if (n % i == 0 && Is3Digit((int) (n / i))) return true;
    }
    return false;
}
