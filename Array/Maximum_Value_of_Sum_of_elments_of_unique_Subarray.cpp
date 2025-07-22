//1695. Maximum Erasure Value

#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;
        int left = 0, currsum = 0, result = 0;

        for (int right = 0; right < n; right++) {

            while (seen.count(nums[right])) {
                currsum -= nums[left];
                seen.erase(nums[left]);
                left++;
            }

            currsum += nums[right];
            seen.insert(nums[right]);

            result = max(result, currsum);
        }
        return result;
    }

int main(){
    vector<int>nums={5,2,1,2,5,2,1,2,5};
    cout<<maximumUniqueSubarray(nums); // output:8

    return 0;
}