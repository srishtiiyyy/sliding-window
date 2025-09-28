#include <bits/stdc++.h>
using namespace std;

/*
Question: Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without repeating characters.

Explanation:
- We use a sliding window approach with two pointers (l and r) to maintain the current substring.
- An array `hash` of size 256 stores the last index of each character (-1 if not seen yet).
- If the current character has been seen in the current window, move `l` to one past the previous index of that character.
- At each step, calculate the window length and update maxLen.
*/

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int HashLen = 256;
    int hash[HashLen];
    fill(hash, hash + HashLen, -1); // Initialize all characters as unseen

    int l = 0, r = 0, maxLen = 0;
    while (r < n) {
        if (hash[s[r]] != -1) {
            // Move left pointer past the last occurrence of s[r]
            l = max(hash[s[r]] + 1, l);
        }
        // Update the maximum length of substring
        maxLen = max(maxLen, r - l + 1);
        // Record the last index of s[r]
        hash[s[r]] = r;
        r++;
    }
    return maxLen;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    int result = lengthOfLongestSubstring(s);
    cout << "Length of longest substring without repeating characters: " << result << endl;

    return 0;
}
