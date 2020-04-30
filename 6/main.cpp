 /* The difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025−385=2640. */
 /* Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum. */

#include <iostream>

int main() {
    const int N = 100;
    int sum = (int) (N * (N + 1) / 2);
    int square_of_sum = sum * sum;
    int sum_of_squares = (int) (N * (N + 1) * (2*N + 1) / 6);
    std::cout << square_of_sum - sum_of_squares << std::endl;
}
