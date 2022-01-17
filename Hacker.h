//
// Created by Ryan.Zurrin001 on 1/17/2022.
//

#ifndef HACKERRANK_HACKER_H
#define HACKERRANK_HACKER_H
#include "HackerLib.h"
/*
 * Complete the 'sockMerchant' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY ar
 */

int sockMerchant(int n, vector<int> ar) {
    int pairs = 0;
    unordered_map<int, int> sockMap;
    for (int i = 0; i < n; i++) {
        sockMap[ar[i]]++;
    }
    for (auto it = sockMap.begin(); it != sockMap.end(); it++) {
        pairs += it->second / 2;
    }
    return pairs;
}
/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

int countingValleys(int steps, string path) {
    int valleys = 0;
    int level = 0;
    for (int i = 0; i < steps; i++) {
        if (path[i] == 'U') {
            level++;
        } else {
            level--;
        }
        if (level == 0 && path[i] == 'U') {
            valleys++;
        }
    }
    return valleys;
}

/*
 * Complete the 'jumpingOnClouds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY c as parameter.
 */

int jumpingOnClouds(vector<int> c) {
    int jumps = 0;
    int i = 0;
    while (i < c.size() - 1) {
        if (i + 2 < c.size() && c[i + 2] == 0) {
            i += 2;
        } else {
            i++;
        }
        jumps++;
    }
    return jumps;
}
/*
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 */

long repeatedString(string s, long n) {
    long count = 0;
    for (char i : s) {
        if (i == 'a') {
            count++;
        }
    }
    long div = n / s.size();
    long rem = n % s.size();
    count = count * div;
    for (int i = 0; i < rem; i++) {
        if (s[i] == 'a') {
            count++;
        }
    }
    return count;
}

/*
 * Complete the 'rotLeft' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER d
 */

vector<int> rotLeft(vector<int> a, int d) {
    vector<int> result;
    for (int i = 0; i < a.size(); i++) {
        int index = (i + d) % a.size();
        result.push_back(a[index]);
    }
    return result;
}

#endif //HACKERRANK_HACKER_H
