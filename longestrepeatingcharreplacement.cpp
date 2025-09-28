#include <bits/stdc++.h>
using namespace std;

/*
========================================================================
LeetCode 424: Longest Repeating Character Replacement
========================================================================

📝 Problem Statement:
Given a string s and an integer k, you can choose any character of the 
string and change it to any other uppercase English character at most 
k times. Return the length of the longest substring containing the same 
letter you can get after performing the above operations.

💡 Approach:
1. Use sliding window with two pointers l and r.
2. Keep track of the frequency of characters in the current window.
3. maxfreq = max frequency of any character in the window.
4. If (window length - maxfreq) > k, shrink the window from left.
5. Update the maximum window length encountered.

Time Complexity: O(n)  
Space Complexity: O(26) ~ O(1)
========================================================================
*/

int characterReplacement(string s, int k) {
    int n = s.size();
    int maxlen = 0, l = 0, maxfreq = 0;
    int hash[26] = {0};

    for (int r = 0; r < n; r++) {
        hash[s[r] - 'A']++;
        maxfreq = max(maxfreq, hash[s[r] - 'A']);

        while ((r - l + 1) - maxfreq > k) {
            hash[s[l] - 'A']--;
            l++; // move left pointer forward
        }

        maxlen = max(maxlen, r - l + 1);
    }

    return maxlen;
}

// -------------------- MAIN FUNCTION --------------------
int main() {
    string s;
    int k;
    cout << "Enter string (uppercase letters only): ";
    cin >> s;
    cout << "Enter k: ";
    cin >> k;

    int result = characterReplacement(s, k);
    cout << "Length of longest substring after replacement: " << result << endl;

    return 0;
}
