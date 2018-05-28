#include <cstdlib>
#include <iostream>

// Prints the lexicographically minimal binary de Bruijn sequence of the given
// order using Duval's algorithm.
// Precondition: order >= 1
void duval_debruijn(int order) {
    int w[order] = {};
    int i = 1;

    while (i) {
        // The first i digits in w form a Lyndon word over the alphabet {0, 1}
        if (order % i == 0) {
            for (int k = 0; k < i; k++) {
                std::cout << w[k];
            }
        }

        // "Fill up" w with repeating copies of the Lyndon word
        for (int j = 0; j < order-i; j++) {
            w[i+j] = w[j];
        }

        // Find the rightmost 0 in w and increment it to 1
        i = order;
        while (i && w[i-1]) {
            i--;
        }
        if (i) {
            w[i-1] = 1;
        }
    }
}

int main(int argc, char *argv[]) {
    int order = (argc == 1) ? 1 : std::atoi(argv[1]);
    duval_debruijn(order);
}
