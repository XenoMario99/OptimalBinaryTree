#include "optSearch.h"

#include <cstdio>
#include <limits>
#include <stdexcept>

std::vector<std::vector<int>> optSearch::makeOptimal(const std::vector<float>& probabilities) {
    const int size = probabilities.size() + 1;

    std::vector<std::vector<float>> A{std::vector<std::vector<float>>(size, std::vector<float>(size, 0))};
    std::vector<std::vector<int>> R{std::vector<std::vector<int>>(size, std::vector<int>(size, 0))};

    try {
        for (int i = 0; i < size - 1; i++) {
            A.at(i).at(i + 1) = probabilities.at(i);
            R.at(i).at(i + 1) = i + 1;
        }

        int j = 0;
        for (int diagonal = 2; diagonal < size; diagonal++) {
            for (int i = 0; i < size - diagonal; i++) {
                j = i + diagonal;

                float min = std::numeric_limits<float>::max();

                int kRes = 0;
                for (int k = i; k < j; k++) {
                    float result = A.at(i).at(k) + A.at(k + 1).at(j);
                    if (result < min) {
                        min = result;
                        kRes = k + 1;
                    }
                }

                A.at(i).at(j) = min;

                for (int n = i; n < j; n++) {
                    A.at(i).at(j) += probabilities.at(n);
                }

                R.at(i).at(j) = kRes;
            }
        }
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << '\n';
        std::exit(-1);
    }

    return R;
}