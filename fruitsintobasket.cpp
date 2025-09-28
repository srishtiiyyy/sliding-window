#include <bits/stdc++.h>
using namespace std;

/*
Problem: Fruit Into Baskets (Leetcode 904)
Given an integer array `fruits` where each element represents a type of fruit,
you can pick at most two types of fruits. You want to pick the maximum number
of fruits in a row (contiguous subarray) containing at most two distinct types.

Example:
Input: fruits = [1,2,1,2,3]
Output: 4
Explanation: The longest subarray with at most 2 distinct fruits is [1,2,1,2].
*/

int totalFruit(vector<int>& fruits) {
    int l = 0, r = 0; // Two pointers for sliding window
    unordered_map<int,int> mpp; // Stores frequency of fruit types
    int maxlen = 0;

    while(r < fruits.size()) {
        mpp[fruits[r]]++; // Add current fruit to the map

        // If more than 2 types of fruits, shrink the window from left
        while(mpp.size() > 2) {
            mpp[fruits[l]]--;
            if(mpp[fruits[l]] == 0) {
                mpp.erase(fruits[l]);
            }
            l++;
        }

        // Update maximum length of valid window
        maxlen = max(maxlen, r - l + 1);
        r++;
    }

    return maxlen;
}

int main() {
    int n;
    cout << "Enter number of fruits: ";
    cin >> n;

    vector<int> fruits(n);
    cout << "Enter fruit types: ";
    for(int i = 0; i < n; i++) cin >> fruits[i];

    cout << "Maximum fruits that can be picked: " << totalFruit(fruits) << endl;

    return 0;
}
