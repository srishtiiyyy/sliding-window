#include <bits/stdc++.h>
using namespace std;

/*
Question: Longest Substring with At Most K Distinct Characters
--------------------------------------------------------------
Given a string s and an integer k, return the length of the 
longest substring that contains at most k distinct characters.

Example:
Input: s = "eceba", k = 2
Output: 3  (Substring "ece")

Explanation:
- Use a sliding window with two pointers (l and r).
- Use a hash map to count frequencies of characters inside the window.
- Expand the window by moving r.
- If the number of distinct characters exceeds k, shrink the window by moving l until the condition is satisfied.
- Track the maximum window size where the number of distinct characters ≤ k.
*/

int kDistinctChar(string& s, int k) {
    int l = 0, r = 0;
    int maxlen = 0;
    unordered_map<char, int> mpp;

    while (r < s.size()) {
        mpp[s[r]]++;

        // Shrink window if more than k distinct chars
        while (mpp.size() > k) {
            mpp[s[l]]--;
            if (mpp[s[l]] == 0) {
                mpp.erase(s[l]);
            }
            l++;
        }

        // Update max length
        maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}

int main() {
    string s;
    int k;
    cout << "Enter string: ";
    cin >> s;
    cout << "Enter k: ";
    cin >> k;

    int result = kDistinctChar(s, k);
    cout << "Length of longest substring with at most " << k 
         << " distinct characters: " << result << endl;

    return 0;
}
