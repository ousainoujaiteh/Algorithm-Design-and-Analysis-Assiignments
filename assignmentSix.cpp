//
// Created by Ousainou Jaiteh on 10/18/22.
//
#include <string>;
#include <unordered_set>;
#include <iostream>

using namespace std;

unordered_set<char> getCharacterSet(string &s, int left, int right) {
    unordered_set<char> charSet;
    for (int i = left; i <= right; i++) {
        charSet.insert(s[i]);
    }
    return charSet;
}

int isNotNiceString(string &s, int left, int right) {
    unordered_set<char> set = getCharacterSet(s, left, right);
    for (int i = left; i <= right; i++) {
        char ch = s[i];
        if (set.find(toupper(ch)) == set.end() || set.find(tolower(ch)) == set.end()) {
            return i;
        }
    }
    return -1;
}

pair<int, int> longestNiceSubstring(string &s, int left, int right) {
    int splittingIndex = isNotNiceString(s, left, right);
    pair<int, int> rez = {left, right};
    if (splittingIndex == -1)return rez;
    pair<int, int> leftString = longestNiceSubstring(s, left, splittingIndex - 1);
    pair<int, int> rightString = longestNiceSubstring(s, splittingIndex + 1, right);
    return (leftString.second - leftString.first >= rightString.second - rightString.first) ? leftString
                                                                                            : rightString;
}

string longestNiceSubstring(string s) {

    pair<int, int> niceSubstring = longestNiceSubstring(s, 0, s.length() - 1);
    string result = s.substr(niceSubstring.first, niceSubstring.second - niceSubstring.first + 1);
    if (result.empty()) {
        return "None";
    } else {
        return result;
    }
}

int main() {
    string input;
    cin >> input;

    cout << longestNiceSubstring(input);
    return 0;
}