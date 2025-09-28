#include <bits/stdc++.h>
using namespace std;

/*
    🔎 Problem: Minimum Window Substring
    -----------------------------------
    Given two strings `s` and `t`, return the minimum window substring of `s`
    such that every character in `t` (including duplicates) is included in the window.
    If no such substring exists, return "".

    👉 Example:
       Input: s = "ADOBECODEBANC", t = "ABC"
       Output: "BANC"

    Approach:
    ---------
    - Use a sliding window with two pointers (l, r).
    - Keep a frequency array for required characters from `t`.
    - Expand window with r, shrink with l when all required characters are inside.
    - Track the minimum length substring found.
*/

string minWindow(string s, string t) {
    int minLen = INT_MAX, startIndex = -1;
    int hash[256] = {0};

    // Fill frequency array with characters from t
    for (char c : t) hash[c]++;

    int required = t.size(), count = 0;
    int l = 0;

    // Expand the right pointer
    for (int r = 0; r < s.size(); r++) {
        if (hash[s[r]] > 0) count++;   // valid char found
        hash[s[r]]--;                  // decrement frequency (can go negative)

        // Shrink from left while valid
        while (count == required) {
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                startIndex = l;
            }
            hash[s[l]]++;
            if (hash[s[l]] > 0) count--;  // lost a needed char
            l++;
        }
    }

    return (startIndex == -1) ? "" : s.substr(startIndex, minLen);
}

int main() {
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;

    string result = minWindow(s, t);
    if (result.empty()) {
        cout << "No valid window found" << endl;
    } else {
        cout << "Minimum window substring: " << result << endl;
    }
    return 0;
}
