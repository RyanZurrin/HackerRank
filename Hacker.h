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

/*
 * Complete the 'optimalPoint' function below. which represents Aladdin and
 * his magic carpet.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY magic
 *  2. INTEGER_ARRAY dist
 */
int optimalPoint(vector<int> magic, vector<int> dist) {
    int start = 0;
    int magicLeft = 0;
    int magicUsed = 0;
    int n = magic.size();

    for (int i = 0; i < n; i++){
        magicLeft += magic[i] - dist[i];
        if (magicLeft < 0){
            start = i + 1;
            magicUsed += magicLeft;
            magicLeft = 0;
        }
    }
    return magicUsed + magicLeft >= 0 ? start : -1;
}

/*
 * Complete the 'hourglassSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */
int hourglassSum(vector<vector<int>> arr) {
    int max_ = -63;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int sum = (arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] +
                    arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2]);
            max_ = max(max_, sum);
        }
    }
    return max_;
}

/*
 * It is New Year's Day and people are in line for the Wonderland rollercoaster ride.
 * Each person wears a sticker indicating their initial position in the queue from
 * to Any person can bribe the person directly in front of them to swap positions,
 * but they still wear their original sticker. One person can bribe at most two others.
 * Determine the minimum number of bribes that took place to get to a given queue order.
 * Print the number of bribes, or, if anyone has bribed more than two people,
 * print Too chaotic.
 */
void minimumBribes(vector<int> q) {
    bool chaotic = false;
    int bribes = 0;
    for (int i = q.size() - 1; i >= 0; i--) {
        if (q[i] - (i + 1) > 2) {
            chaotic = true;
            break;
        }
        for (int j = max(0, q[i] - 2); j < i; j++) {
            if (q[j] > q[i]) {
                bribes++;
            }
        }
    }
    if (chaotic) {
        cout << "Too chaotic";
    } else {
        cout << bribes;
    }
}

/**
 * You are given an unordered array consisting of consecutive integers
 * [1, 2, 3, ..., n] without any duplicates. You are allowed to swap any
 * two elements. Find the minimum number of swaps required to sort the array
 * in ascending order.
 * @param arr  an array of integers
 * @return  the minimum number of swaps required to sort the array in ascending order
 */
int minimumSwaps(vector<int> arr) {
    auto n = arr.size();
    int ans = 0;
    pair<int, int> ap[n];
    for (int i = 0; i < n; i++) {
        ap[i].first = arr[i];
        ap[i].second = i;
    }

    sort(ap, ap + n);
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        int old_pos = ap[i].second;
        if (visited[old_pos]) {
            continue;
        }
        int node = i;
        int cycle_size = 0;
        while (!visited[node]) {
            visited[node] = true;
            node = ap[node].second;
            cycle_size++;
        }
        if (cycle_size > 0) {
            ans += (cycle_size - 1);
        }
    }
    return ans;
}

/**
 * Starting with a 1-indexed array of zeros and a list of operations, for each
 * operation add a value to each the array element between two given indices,
 * inclusive. Once all operations have been performed, return the maximum value
 * in the array.
 * @param n  the size of the array
 * @param queries  a list of triplets where each triplet specifies the indices
 *               of the start and end of a query and the value added to each
 *               element in the inclusive range [start, end].
 * @return  the maximum value in the final array
 */
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n + 1, 0);
    for (auto q : queries) {
        arr[q[0] - 1] += q[2];
        arr[q[1]] -= q[2];
    }
    long max_ = 0;
    long sum = 0;
    for (auto a : arr) {
        sum += a;
        max_ = max(max_, sum);
    }
    return max_;
}

/**
 * Harold is a kidnapper who wrote a ransom note, but now he is worried it will be
 * traced back to him through his handwriting. He found a magazine and wants to
 * know if he can cut out whole words from it and use them to create an untraceable
 * replica of his ransom note. The words in his note are case-sensitive and he must
 * use only whole words available in the magazine. He cannot use substrings or
 * concatenation to create the words he needs.
 * Given the words in the magazine and the words in the ransom note, print Yes
 * if he can replicate his ransom note exactly using whole words from the magazine;
 * otherwise, print No.
 * @param magazine
 * @param note
 */
void checkMagazine(vector<string> magazine, vector<string> note) {
    unordered_map<string, int> m;
    for (auto s : magazine) {
        m[s]++;
    }
    for (auto s : note) {
        if (m.find(s) == m.end() || m[s] == 0) {
            cout << "No";
            return;
        }
        m[s]--;
    }
    cout << "Yes";
}

/**
 * Given two strings, determine if they share a common substring. A substring may
 * be as small as one character.
 * @param s1 the first string
 * @param s2   the second string
 * @return  "YES" if there is a common substring, otherwise "NO"
 */
string twoStrings(string s1, string s2) {
    unordered_set<string> s;
    for (auto c : s1) {
        s.insert(string(1, c));
    }
    for (auto c : s2) {
        if (s.find(string(1, c)) != s.end()) {
            return "YES";
        }
    }
    return "NO";
}
vector<int> getHashValue(string s, int i, int j) {
    vector<int> freq(26, 0);
    for (int k = i; k <= j; k++) {
        char ch = s[k];
        freq[ch - 'a']++;
    }
    return freq;
}
/**
 * Two strings are anagrams of each other if the letters of one string can be
 * rearranged to form the other string. Given a string, find the number of pairs
 * of substrings of the string that are anagrams of each other.
 * @param s the string
 * @return the number of pairs of substrings of the string that are anagrams of each other
 */
int sherlockAndAnagrams(string s) {
    map<vector<int>, int> hashMap;
    int anagramCount = 0;
    for (int i = 0; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) {
            // get hash value of substring
            vector<int> freq = getHashValue(s, i, j);
            // check if hash value is present in hash table
            hashMap[freq]++;
        }
    }
    for (auto& it : hashMap) {
        int freq = it.second;
        if (freq > 1) {
            anagramCount += freq * (freq - 1) / 2;
        }
    }
    return anagramCount;
}

/**
 * You are given an array and you need to find number of triplets of indices (i,j,k)
 * such that the elements at those indices are in geometric progression for a given
 * common ratio r and i < j < k.
 * @param arr
 * @param r
 * @return
 */
long countTriplets(vector<long> arr, long r) {
    map<int, long> left, right;
    long trip = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (right.find(arr[i]) != right.end()) {
            trip += right[arr[i]];
        }
        if (left.find(arr[i]) != left.end()) {
            right[arr[i] * r] += left[arr[i]];
        }
        left[arr[i] * r]++;
    }
    return trip;
}
/**
    @brief Given an array consisting of n positive integers. The cost of the array
    is defined as(assuming 0-based indexing) where len(arr) represents the size
    the array. Insert any integer at any location of the array such that the cost
    of the array is minimized. Find the minimum possible cost of the array after
    inserting exactly one element.

    Example: arr = [1,3,5,2,10]
    the cost of the array before insertion =
                             (1-3)^2 + (3-5)^2 + (5-2)^2 + (2-10)^2 = 81
    Two of the many scenarios are shown below:
     1. Insert 4 between 3 and 5, cost of array =
                             (1-2)^2 + (3-4)^2 + (4-5)^2 + (5-2)^2 + (2-10)^2 = 79
     2. Insert 6 between 2 and 10, cost of array =
                             (1-3)^2 + (3-5)^2 + (5-2)^2 + (2-6)^2 + (6-10)^2 = 49
     It can be proven that 49 is the minimum cost possible. Return 49.
     FUNCTION DESCRIPTION:
     Complete the function getMinimumCost in the editor below. getMinimumCost has the following parameter(s):
     @param int arr[n]: an array of integers
     @return long_int: the minimum cost of the array after inserting one element
     Constraints: 2 <= n <=10^4, 1 <= arr[i] <= 10^5
 */
long getMinimumCost(vector<int> arr) {
    long cost = 0;
    long min_cost = 0;
    long max_val = 0;
    map<int, long> m;
    // use dp to store the minimum cost of the array after inserting one element
    for (int i = 0; i < arr.size()-1; i++) {
        // insert i+1, (long)pow(arr[i+1] - arr[i], 2) int the map
        cost += (long)pow(arr[i+1] - arr[i], 2);
        m[i+1] = (long)pow(arr[i+1] - arr[i], 2);
    }
    min_cost = cost;
    int indexToInsertAt = 0;
    for (auto & it : m) {
        if (it.second > max_val) {
            max_val = it.second;
            indexToInsertAt = it.first;
        }
    }
    // print max val and index to insert at
    cout << "max val: " << max_val << " index to insert at: " << indexToInsertAt << endl;

    for (int i = 0; i < max_val; i++) {
        bool flag = false;
        vector<int> new_arr(arr.size()+1);
        for (int j = 0; j < new_arr.size(); j++) {
            if (j == indexToInsertAt) {
                new_arr[j] = i+1;
                flag = true;
            } else {
                if (flag) {
                    new_arr[j] = arr[j-1];
                } else {
                    new_arr[j] = arr[j];
                }
            }
        }
        cost = 0;
        for (int i_ = 0; i_ < new_arr.size() - 1; i_++) {
            cost += (long)pow(new_arr[i_ + 1] - new_arr[i_], 2);
        }
        if (cost < min_cost) {
            min_cost = cost;
        }
    }
    return min_cost;
}

/**
  There are n balls placed on a 1-dimensional axis with each of them moving with
  the same non-zero speed. direction[i] represents the direction in which the ith
  ball is moving, with -1 meaning left and 1 meaning right.The strength of the ith
  ball is described by strength[i]. If e balls collide, the one with the higher strength
  destroys the smaller one. If both have the same strength, both are destroyed.
  Return a list of the indices of the balls that remain after all the collisions
  have occurred, in ascending order.
 * @param direction the direction of the balls
 * @param strength the strength of the balls
 * @return the indices of the balls that remain after all the collisions have occurred, in ascending order
 */
vector<int> findRemainingBalls(vector<int> direction, vector<int> strength) {
    // create a stack to store the balls that are still moving
    stack<int> s;
    int i = 0;
    while (i < strength.size()) {
        int ball = strength[i];
        int dir = direction[i];
        if (s.empty()) {
            s.push(i);
        } else {
            int top = s.top();
            if (direction[top] > 0 && dir < 0) {
                if (strength[top] == ball) {
                   s.pop();
                } else if (strength[top] < ball) {
                    s.pop();
                    continue;
                }
            } else {
                s.push(i);
            }
        }
        i++;
    }
    vector<int> res;
    while (!s.empty()) {
        res.push_back(s.top());
        s.pop();
    }
    // sort the result
    sort(res.begin(), res.end());
    return res;
}
/**
  Non-critical request for a transaction system are routed through a throttling
  gateway to ensure that the network is not choked by non-essential requests.
  The gateway has the following limits:
  - the number of transactions in any given second cannot exceed 3.
  - the number of transactions in any given 10 second period cannot exceed 20. A
     10 second period includes all requests arriving from any time max(1, T-9) to
     T (inclusive of both) for any valid time T.
  - the number of transactions in any given minute cannot exceed 60. Similar to
    above, 1 minute is from max(1, T-59) to T (inclusive of both).
  Any request that exceeds any of the above limits will be dropped by the gateway. Given
  the times at which different requests arrive sorted ascending, find how many
  requests will be dropped.
  Note: Even if a request is dropped it is still considered for future calculations.
  Although, if a request is to be dropped due to multiple violations, it is still
  counted only once.
 * @param requestTime
 * @return
 */
int droppedRequests(vector<int> requestTime) {
    int dropped = 0;
    for (int i = 0; i < requestTime.size(); i++) {
        if (i > 2 && requestTime[i] == requestTime[i-3]) {
            dropped++;
        } else if (i > 19 && (requestTime[i] - requestTime[i-20]) < 10) {
            dropped++;
        } else if (i > 59 && (requestTime[i] - requestTime[i-60]) <= 60) {
            dropped++;
        }
    }
    return dropped;
}
#endif //HACKERRANK_HACKER_H
