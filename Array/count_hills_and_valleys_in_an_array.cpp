//2210. Count Hills and Valleys in an Array
#include<iostream>
#include<vector>
using namespace std;

int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, left = 0;

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] != nums[i + 1]) {
                if ((nums[i] > nums[left] && nums[i] > nums[i + 1]) ||
                    (nums[i] < nums[left] && nums[i] < nums[i + 1])) {
                    cnt++;
                }
                left = i;
            }
        }

        return cnt;
    }

int main(){
    vector<int>nums={2,4,1,1,6,5};
    cout<<countHillValley(nums);
    
    return 0;
}