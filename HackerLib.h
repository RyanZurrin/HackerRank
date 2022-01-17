//
// Created by Ryan.Zurrin001 on 1/17/2022.
//
#include <bits/stdc++.h>
using namespace std;

#ifndef HACKERRANK_HACKERLIB_H
#define HACKERRANK_HACKERLIB_H
string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

template <typename T>
static void printVector(vector<T> vector1) {
    for (auto i = 0; i < vector1.size(); i++) {
        cout << vector1[i] << " ";
    }
    cout << endl;
}
#endif //HACKERRANK_HACKERLIB_H
