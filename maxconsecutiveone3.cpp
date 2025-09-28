#include <bits/stdc++.h>
using namespace std;

/*
Problem: Max Consecutive Ones III (Leetcode 1004)

Given a binary array nums and an integer k, you can flip at most k zeros to ones.
Return the maximum number of consecutive 1s in the array after flipping at most k zeros.

Example:
Input: nums = [1,0,1,1,0,0,1], k = 2
Output: 5
Explanation: Flip the two zeros at indices 4 and 5 to get [1,0,1,1,1,1,1].
The longest consecutive ones = 5.
*/

int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    int l = 0, r = 0;
    int maxlen = 0, zeroes = 0;

    while(r < n) {
        if(nums[r] == 0) zeroes++; // Count zeros in current window

        // Shrink window if zero count exceeds k
        while(zeroes > k) {
            if(nums[l] == 0) zeroes--;
            l++;
        }

        // Update maximum length of valid window
        maxlen = max(maxlen, r - l + 1);
        r++;
    }

    return maxlen;
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements (0 or 1): ";
    for(int i = 0; i < n; i++) cin >> nums[i];

    cout << "Enter maximum zeros to flip (k): ";
    cin >> k;

    cout << "Maximum consecutive 1s after flipping at most " << k << " zeros: "
         << longestOnes(nums, k) << endl;

    return 0;
}
