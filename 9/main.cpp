/* A Pythagorean triplet is a set of three natural numbers, a < b < c, for which, */
/* a2 + b2 = c2 */

/* For example, 32 + 42 = 9 + 16 = 25 = 52. */

/* There exists exactly one Pythagorean triplet for which a + b + c = 1000. */
/* Find the product abc. */

#include <iostream>

int main() {
    const int sum_value = 1000;
    for (int a=1; a < sum_value; ++a) {
        for (int b=1; b < a && a + b < sum_value; ++b) {
            int c = 1000 - b - a;
            if (a * a + b * b ==  c * c) std::cout << a * b * c << std::endl;
        }
    }
}
