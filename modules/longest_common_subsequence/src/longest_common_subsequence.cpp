// Copyright 2023 Yurin Evgeny

#include "include/longest_common_subsequence.h"

#include <vector>

std::vector<int>
get_longest_common_subsequence(int firstLength, std::vector<int> firstSequence,
                               int secondLength,
                               std::vector<int> secondSequence) {
    int lcsTable[firstLength + 1][secondLength + 1];
    for (int i = 0; i <= firstLength; i++) {
        for (int j = 0; j <= secondLength; j++) {
            if (i == 0 || j == 0)
                lcsTable[i][j] = 0;
            else if (firstSequence[i - 1] == secondSequence[j - 1])
                lcsTable[i][j] = lcsTable[i - 1][j - 1] + 1;
            else
                lcsTable[i][j] = std::max(lcsTable[i - 1][j],
                                          lcsTable[i][j - 1]);
        }
    }

    int index = lcsTable[firstLength][secondLength];
    std::vector<int> lcs;
    lcs.reserve(index + 1);
    lcs[index] = -1;

    int i = firstLength, j = secondLength;
    while (i > 0 && j > 0) {
        if (firstSequence[i - 1] == secondSequence[j - 1]) {
            lcs.push_back(firstSequence[i - 1]);
            i--;
            j--;
            index--;
        } else if (lcsTable[i - 1][j] > lcsTable[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    std::reverse(lcs.begin(), lcs.end());
    return lcs;
}
