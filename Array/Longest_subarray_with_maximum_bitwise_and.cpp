//2419. Longest Subarray With Maximum Bitwise AND
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestSubarray(vector<int>& nums) {
    int maxi = *max_element(nums.begin(), nums.end());
    int count = 0, maxlen = 0;

    for (int& a : nums) {
        if (a == maxi) {
            count++;
        } 
        else {
            maxlen = max(maxlen, count);
            count = 0;
        }
    }

    maxlen = max(maxlen, count);
    return maxlen;
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 3, 4};  
    cout << "Longest subarray with maximum AND: " << longestSubarray(nums) << endl; //output: 2
    return 0;
}
