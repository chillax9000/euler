#include <iostream>

int main() {
    int i = 1, j = 2;
    int tmp = 0;
    int sum_even = 2;
    while (j <= 4000000) {
        tmp = j;
        j += i;
        i = tmp;
        if (j % 2 == 0) sum_even += j;
    }
    std::cout << sum_even << std::endl;

}
